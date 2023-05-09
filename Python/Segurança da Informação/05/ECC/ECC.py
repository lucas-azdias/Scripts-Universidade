from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives.serialization import Encoding, ParameterFormat, PrivateFormat, PublicFormat
from cryptography.hazmat.primitives.serialization import BestAvailableEncryption, load_pem_public_key, load_pem_parameters


# ALICE
alice_private_key = ec.generate_private_key( ec.SECP384R1() )
alice_public_key = alice_private_key.public_key()
alice_pubkey_PEM = alice_public_key.public_bytes(Encoding.PEM, PublicFormat.SubjectPublicKeyInfo)
print(alice_pubkey_PEM)

# BOB
bob_private_key = ec.generate_private_key( ec.SECP384R1() )
bob_public_key = bob_private_key.public_key()
bob_pubkey_PEM = bob_public_key.public_bytes(Encoding.PEM, PublicFormat.SubjectPublicKeyInfo)
print(bob_pubkey_PEM)

# AMBOS
chave_publica_bob =  load_pem_public_key(bob_pubkey_PEM) 
shared_key_alice = alice_private_key.exchange(ec.ECDH(), chave_publica_bob)

chave_publica_alice =  load_pem_public_key(alice_pubkey_PEM) 
shared_key_bob = bob_private_key.exchange(ec.ECDH(), chave_publica_alice)

# DERIVACAO DA CHAVE
chave_secreta_alice = HKDF(
    algorithm=hashes.SHA256(),
    length=16,
    salt=None,
    info=b'handshake data',
).derive(shared_key_alice)

chave_secreta_bob = HKDF(
    algorithm=hashes.SHA256(),
    length=16,
    salt=None,
    info=b'handshake data',
).derive(shared_key_bob)

print(chave_secreta_alice)
print(chave_secreta_bob)









