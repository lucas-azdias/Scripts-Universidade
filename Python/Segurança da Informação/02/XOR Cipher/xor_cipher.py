def xor_cipher(plain, key):
    cipher = ""
    for c in plain:
        cipher += chr(ord(c) ^ key)
    return cipher

while True:
    key = input('entre com a chave: ') # Entre 0 e 255 (1 byte)
    if not key:
        print("saindo ... ")
        break
    else:
        key = int(key)
    plain = input('entre com a mensagem: ')
    cipher = xor_cipher(plain, key)
    print("cripto:", cipher)
    print("decripto:", xor_cipher(cipher, key))
