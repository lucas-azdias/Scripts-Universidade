from cryptography import x509
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.x509.oid import NameOID
import datetime
from cryptography import x509
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding

# Gera a chave privada e salva (opcionalmente) em um arquivo
def geraChavePrivada(tamanho, arquivo=None):

    private_key = rsa.generate_private_key(
        public_exponent=65537,
        key_size=tamanho,
    )

    if arquivo is not None:
        private_pem = private_key.private_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PrivateFormat.TraditionalOpenSSL,
            encryption_algorithm=serialization.NoEncryption()
            )
        with open(arquivo, "wb") as key_file:
            key_file.write(private_pem)
        
    return private_key, private_pem

# Calcula a chave pública a partir da chave privada e salva (opcionalmente) em um arquivo
def geraChavePublica(private_key, arquivo=None):
    public_key = private_key.public_key()
    public_pem = public_key.public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )

    if arquivo is not None:
        with open(arquivo, "wb") as key_file:
            key_file.write(public_pem)

    return public_key, public_pem

# Carrega a chave privada de um arquivo (a chave não deve ser gerada a cada vez que o algoritmo é executado) 
def carregaChavePrivada(arquivo):
    with open(arquivo, "rb") as key_file:
        private_key = serialization.load_pem_private_key(
            key_file.read(),
            password=None,
        )
    return private_key

# A chave pública vem pela rede em formato PEM, então é necessário convertê-la antes de usá-la
def converteChavePublica(public_pem):
    public_key = serialization.load_pem_public_key(public_pem)
    return public_key

# Gera um certificado Autoassinado do tipo CA ROOT
# - dn é o distinguished name: { cn='common name', o='organization', c='country', s='state', l='city', alias='apelido' }
def geraAutoAssinado(private_key, public_key, dn, file = None, dias=365, ca=True):

    if type(dn) is not dict:
        return "você não passou o dn como um dicionário"
    
    subjectDN = x509.Name([
        x509.NameAttribute(NameOID.COUNTRY_NAME, dn.get('c','esqueci o c')),
        x509.NameAttribute(NameOID.STATE_OR_PROVINCE_NAME, dn.get('s','esqueci o s')),
        x509.NameAttribute(NameOID.LOCALITY_NAME, dn.get('l','esqueci o l')),
        x509.NameAttribute(NameOID.ORGANIZATION_NAME, dn.get('o','esqueci o o')),
        x509.NameAttribute(NameOID.COMMON_NAME, dn.get('cn','esqueci o cn')),
    ])
    
    builder = x509.CertificateBuilder()
    builder = builder.subject_name(subjectDN)
    builder = builder.issuer_name(subjectDN)
    builder = builder.not_valid_before(datetime.datetime.today())
    builder = builder.not_valid_after(datetime.datetime.today() + datetime.timedelta(days=dias) )
    builder = builder.serial_number(x509.random_serial_number())
    builder = builder.public_key(public_key)

    if 'alias' in dn:
        builder = builder.add_extension( x509.SubjectAlternativeName( [x509.DNSName(dn['alias']), ] ), critical=False )

    if ca:
        builder = builder.add_extension( x509.BasicConstraints(ca=ca, path_length=None), critical=True, )
    
    certificate = builder.sign( private_key=private_key, algorithm=hashes.SHA256(), )
    cert_pem = certificate.public_bytes(encoding=serialization.Encoding.PEM)

    if file:
        with open(file, 'wb') as f: 
            f.write(cert_pem)

    return cert_pem

# Gera um CSR (Certificate Signing Request)
def geraCSR(private_key, dn, file = None):

    subjectDN = x509.Name([
        x509.NameAttribute(NameOID.COUNTRY_NAME, dn.get('c','esqueci o c')),
        x509.NameAttribute(NameOID.STATE_OR_PROVINCE_NAME, dn.get('s','esqueci o s')),
        x509.NameAttribute(NameOID.LOCALITY_NAME, dn.get('l','esqueci o l')),
        x509.NameAttribute(NameOID.ORGANIZATION_NAME, dn.get('o','esqueci o o')),
        x509.NameAttribute(NameOID.COMMON_NAME, dn.get('cn','esqueci o cn')),
    ])


    builder = x509.CertificateSigningRequestBuilder()
    builder = builder.subject_name(subjectDN)
    if 'alias' in dn:
        builder = builder.add_extension( x509.SubjectAlternativeName( [x509.DNSName(dn['alias']), ] ), critical=False )

    # OBS: A chave privada é usada para assinar e não é incluida no CSR, apenas a chave pública.
    csr = builder.sign(private_key, hashes.SHA256())
    csr_pem = csr.public_bytes(serialization.Encoding.PEM)


    if file:
        with open(file, 'wb') as f: 
            f.write(csr_pem)

    return csr_pem

# Assina uma CSR por uma CA
def assinaCSR(csr_cert, ca_cert, private_ca_key, file = None, dias=60):

    cert = x509.CertificateBuilder()
    
    cert = cert.subject_name( csr_cert.subject )
    cert = cert.issuer_name( ca_cert.subject )
    cert = cert.public_key( csr_cert.public_key() )
    cert = cert.serial_number( x509.random_serial_number() )
    cert = cert.not_valid_before( datetime.datetime.today())
    cert = cert.not_valid_after( datetime.datetime.today() + datetime.timedelta(days=dias) )
    cert = cert.sign(private_ca_key, hashes.SHA256())

    # DER é um formato de certificate em binário
    # cert_der = cert.public_bytes(serialization.Encoding.DER)

    cert_pem = cert.public_bytes(serialization.Encoding.PEM)

    
    if file:
        with open(file, 'wb') as f: 
            f.write(cert_pem)

    return cert_pem

# Carrega um certificado 
def carregaCertificado(file, formato='PEM', show=False):

    try:
        with open(file, 'rb') as f: data = f.read()      
    except Exception as e:
        print(e)
        return None

    if formato == 'PEM':
        cert = x509.load_pem_x509_certificate(data)
    else:
        cert = x509.load_der_x509_certificate(data)

    if show:
        print('Emissor:', cert.issuer)
        print('CN do Emissor:', cert.issuer.get_attributes_for_oid(NameOID.COMMON_NAME)[0].value )
        print('Requerente: ', cert.subject)
        #print('Extensoes: ', cert.extensions)
        print('Chave Pública: ', cert.public_key())
        print('Inicio Validade: ', cert.not_valid_before)
        print('Fim Validade: ', cert.not_valid_after)
        print('Algoritmo Assinatura: ', cert.signature_hash_algorithm)
        

    return cert

# Carrega um CSR 
def carregaCSR(file, formato='PEM', show=False):

    try:
        with open(file, 'rb') as f: data = f.read()      
    except Exception as e:
        print(e)
        return None


    if formato == 'PEM':
        csr = x509.load_pem_x509_csr(data)
    else:
        csr = x509.load_der_x509_csr(data)

    if show:
        print('Requerente: ', csr.subject)
        print('CN do Requerente:', csr.subject.get_attributes_for_oid(NameOID.COMMON_NAME)[0].value )

    return csr

# Verifica um certificado
def verificaCertificado(cert, issuer):
    if cert.subject == cert.issuer:
        print('Este certificado é AUTOASSINADO')
        return True
    
    pubCA = issuer.public_key()

    try:
        pubCA.verify(cert.signature, cert.tbs_certificate_bytes, padding.PKCS1v15(), cert.signature_hash_algorithm )
        return True
    except Exception as e:
        print('Assinatura inválida:', type(e))
        return False




# Use essa porção do código para testar as funções da biblioteca

if __name__ == "__main__":

    # -----------------------------------------------------------------------------
    # Cria uma CA
    priCA, priCA_pem = geraChavePrivada(2048, 'caPrivada.pem')
    pubCA, pubCA_pem = geraChavePublica(priCA, 'caPublica.pem')
    dn = {'cn' : 'minaCA.com', 'o':'minhaCA LTDA', 'c':'br', 's':'Parana', 'l':'Curitiba'} 
    certCA_pem = geraAutoAssinado(priCA, pubCA, dn, 'certCA.pem') 
    certCA = carregaCertificado("certCA.pem", show=True)
    # execute ** openssl x509 -in certCA.pem -text **

    # -----------------------------------------------------------------------------
    # Gera um CSR
    priEU, priEU_pem = geraChavePrivada(2048, 'euPrivada.pem')
    pubEU, pubEU_pem = geraChavePublica(priEU, 'euPublica.pem')

    dn = {'cn' : 'eu.com', 'o':'EU LTDA', 'c':'br', 's':'Parana', 'l':'Curitiba'}
    csr_pem =  geraCSR(priEU, dn, 'csr.pem')
    csr = carregaCSR('csr.pem', show=True)
    # execute ** openssl req -text -noout -verify -in csr.pem **

    # -----------------------------------------------------------------------------
    # Assina o CSR
    certEU = assinaCSR(csr, certCA, priCA, 'certEU.pem')
    certEU = carregaCertificado('certEU.pem', show=True)

    # -----------------------------------------------------------------------------
    # Verifica o Certificado
    print( verificaCertificado(certEU, certCA) )
