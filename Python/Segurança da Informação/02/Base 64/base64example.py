from base64 import b64encode

def xor_cipher(plain, key):
    cripto = ""
    for c in plain:
        codigo = ord(c) ^ key
        cripto += chr(codigo)
    return cripto

while True:
    key = input('entre com a chave: ')
    if not key:
        print("saindo ... ")
        break
    else:
        key = int(key)

    plain = input('entre com a mensagem: ')
    cipher = xor_cipher(plain, key)


    print("cripto:", b64encode(bytearray([ord(c) for c in cipher])))
    print("decripto:", xor_cipher(cipher, key))






