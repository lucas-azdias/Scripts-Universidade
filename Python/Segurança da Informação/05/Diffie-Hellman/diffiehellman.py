from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import dh
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives.serialization import Encoding, ParameterFormat, PrivateFormat, PublicFormat
from cryptography.hazmat.primitives.serialization import BestAvailableEncryption, load_pem_public_key, load_pem_parameters



# 1) Os parâmetros precisam ser os mesmos para ALICE E BOB
# Como combinar os parâmetros?
# - HARD CODED (pior opção)
# - PELA REDE EM ABERTO (o p pode mudar a cada sessão)
# - PELA REDE CRIPTOGRAFADO (se já houver um canal de criptografia anterior )


# 1) ALICE gera os parâmetros, chave pública e privada
# - ALICE envia sua chave pública para BOB
parameters = dh.generate_parameters(generator=2, key_size=512)
parametros_PEM = parameters.parameter_bytes(Encoding.PEM, ParameterFormat.PKCS3 )

private_key = parameters.generate_private_key()
public_key = private_key.public_key()

pub_PEM = public_key.public_bytes(Encoding.PEM, PublicFormat.SubjectPublicKeyInfo)

# 2) BOB recebe os parâmetros de ALICE e gera as chaves pública e privada
parameters =  load_pem_parameters(parametros_PEM) 
private_key1 = parameters.generate_private_key()
public_key1 = private_key1.public_key()

pub_PEM1 = public_key1.public_bytes(Encoding.PEM, PublicFormat.SubjectPublicKeyInfo)

# 3) ALICE CALCULA O SEGREDO

bob_pubkey =  load_pem_public_key(pub_PEM1) 
shared_key = private_key.exchange(bob_pubkey)

# 4) BOB CALCULA O SEGREDO
alice_pubkey =  load_pem_public_key(pub_PEM) 
shared_key1 = private_key1.exchange(public_key)

# 5) AMBOS OS SEGREDOS SÃO IGUAIS
print('\nOs segredos são iguais?')
print( shared_key == shared_key1)

# 6) AS CHAVES PRIVADAS SÃO DIFERENTES
ei = BestAvailableEncryption(b'senha')
pb = private_key.private_bytes(Encoding.PEM, PrivateFormat.PKCS8, ei)
pb1 = private_key1.private_bytes(Encoding.PEM, PrivateFormat.PKCS8, ei )
print('\nAs chaves privadas são iguais?')
print(pb==pb1)

# 7) A CHAVE SECRETA (DE QUALQUER TAMANHO É DERIVADA A PARTIR DO SEGREDO )
derived_key = HKDF(
    algorithm=hashes.SHA256(),
    length=16,
    salt=None,
    info=b'handshake data',
).derive(shared_key)

print('\nComo ficou a chave secreta? Ela muda a cada execução? ')
print([ i for i in derived_key ] )
