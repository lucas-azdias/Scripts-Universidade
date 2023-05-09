import certLib as CERT


def criaCA():
    print('Essas ações são feitas pela Autoridade Certificado')

    priCA, priCA_pem = CERT.geraChavePrivada(2048, 'caPrivada.pem')
    pubCA, pubCA_pem = CERT.geraChavePublica(priCA, 'caPublica.pem')

    dn = {'cn' : 'PUCPR.br', 'o':'Politecnica PUCPR',
          'c':'BR', 's':'Parana', 'l':'Curitiba'}

    CERT.geraAutoAssinado(priCA, pubCA, dn, 'certCA.pem')

    return CERT.carregaCertificado("certCA.pem", show=True)


def geraCSR():
    print('Essas ações são feitas pela administrador do Servidor Web')

    priEU, priEU_pem = CERT.geraChavePrivada(2048, 'euPrivada.pem')
    pubEU, pubEU_pem = CERT.geraChavePublica(priEU, 'euPublica.pem')

    dn = {'cn': 'bcc.pucpr.br', 'o': 'Ciencia da Computacao',
          'c': 'BR', 's': 'Parana', 'l': 'Curitiba'}

    CERT.geraCSR(priEU, dn, 'csr.pem')

    return CERT.carregaCSR('csr.pem', show=True)
    

def assinaCSR(csr, certCA):
    print('Essas ações são feitas pela CA')

    priCA = CERT.carregaChavePrivada('caPrivada.pem')

    CERT.assinaCSR(csr, certCA, priCA, file='certEU.pem')
    
    return CERT.carregaCertificado('certEU.pem', show=True)
    

def validaCertificado(certEU):
    print('Essas ações são feitas pelo navegador Web')

    certCA = CERT.carregaCertificado("certCA.pem", show=False)  # Previamente já possuía

    return CERT.verificaCertificado(certEU, certCA)
    

#--------------------------------------------------------------
print()

# 1) Crie uma CA com a seguinte DN
# CN='PUCPR.br', O='Politecnica PUCPR', C='BR', S='Parana', L='Curitiba'
certCA = criaCA()
print()

# 2) Crie um CSR para o servidor Web e assine com a CA
# CN='bcc.pucpr.br', O='Ciencia da Computacao', C='BR', S='Parana', L='Curitiba'
csr = geraCSR()
print()
certEU = assinaCSR(csr, certCA)
print()

# 3) Faça a verificação do Certificado pelo navegador Web
print(validaCertificado(certEU))
print()


"""
PERGUNTAS:

1) Como o certificado da CA é validado? -> não é validado (você apenas acredita nele)
2) Qual chave a CA usa para assinar o CSR do Servidor Web? -> usa a sua chave privada
3) O certificado do servidor contém a chave privada do Servidor Web? -> não, apenas a chave pública dele fica no certificado do Servidor Web
4) Quais informações o browser precisa conhecer para validar o certificado do Servidor Web? -> ele precisa já conhecer a chave pública do CA (já possuir o certificado dele)
"""
