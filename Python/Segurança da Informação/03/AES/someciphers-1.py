# https://cryptography.io/en/latest/hazmat/primitives/symmetric-encryption/

from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from base64 import b64encode
import os


def cipherAES(msg, key, iv):
    # ECB(não tem iv), CBC, CTR, GCM
    cipher = Cipher(algorithms.AES(key), modes.CBC(iv))
    encryptor = cipher.encryptor()
    # buffer = tamanho da mensagem + tamanho de um bloco (16 bytes) - 1
    buf = bytearray(len(msg) + 16 - 1)
    len_encrypted = encryptor.update_into(msg, buf)
    ciphertext = bytes(buf[:len_encrypted]) + encryptor.finalize()
    print("Ciphertext (B64)", b64encode(ciphertext))
    print("Ciphertext (BYTES)", [c for c in ciphertext])

    decryptor = cipher.decryptor()
    len_decrypted = decryptor.update_into(ciphertext, buf)
    plaintext = bytes(buf[:len_decrypted]) + decryptor.finalize()
    print("Plaintext", plaintext)
    plaintext = bytes([ p for p in plaintext if p != 0 ]).decode()
    print("Plaintext (Decoded)", plaintext)
    

def testaAES():
    # pode se usar chaves de 128, 192 ou 256 bits
    chave = os.urandom(16)
    print("chave", end=": ")
    for b in chave:
        print(b, end=' ')
    # iv tem o tamanho do bloco
    iv = os.urandom(16)
    print("\n iv  ", end=": ")
    for b in iv:
        print(b, end=' ')

    while True:
        msg = input('\nDigite a mensagem: ')
        if not msg:
            print('bye my friend!!!')
            break
        msg = msg.encode('utf-8')
        # Tem que completar para ser multiplo de 16
        msg = msg + bytearray(16 - len(msg)%16)
        print("\nMensagem: ", msg)

        try: 
            cipherAES(msg, chave, iv)
        except Exception as e:
            print(e)
            break    
    

def cipherRC4(msg, chave):
    algorithm = algorithms.ARC4(chave)
    cipher = Cipher(algorithm, mode=None)
    encryptor = cipher.encryptor()
    ciphertext = encryptor.update(msg)
    print("Ciphertext (B64):", b64encode(ciphertext))
    print("Ciphertext (BYTES):", [c for c in ciphertext] )
    decryptor = cipher.decryptor()
    plaintext = decryptor.update(ciphertext)
    print("Plaintext (Decoded):", plaintext.decode())


def testaRC4():
    # pode se usar chaves de 40, 56, 64, 80, 128, 192 ou 256 bits
    chave = input('\nDigite a chave: ')
    chave = chave.encode()

    while True:
        msg = input('\nDigite a mensagem: ')
        if not msg:
            print('bye my friend!!!')
            break
        msg = msg.encode()
        try: 
            cipherRC4(msg, chave)
        except Exception as e:
            print(e)
            break
        

    
#testaRC4()
testaAES()
