from base64 import b64encode

# Output True = text, False = Hex
def xor_cipher(plain, key, text=False):
    hkey = []
    result = []
    for i in key:
        hkey.append(ord(i))
    i = 0
    for c in plain:
        result.append(ord(c) ^ hkey[i])
        i += 1
        if i == len(key):
            i = 0
    return to_ascii(result) if text else result


def to_ascii(result):
    cipher = ''
    for i in result:
        cipher += chr(i)
    return cipher


#Criptografia com XOR
def teste1():
    while True:
        key = input('entre com a chave: ')
        if not key:
            print("saindo ... ")
            break
        else:
            plain = input('entre com a mensagem: ')
            cipher = xor_cipher(plain, key)
            print("code cripto:", cipher)
            print("base64 cripto:", b64encode(bytearray(cipher)))
            cipher = to_ascii(cipher)
            print("unicode cripto:", cipher)
            print("decripto:", to_ascii(xor_cipher(cipher, key)))


# Colisão de CipherText
def teste2():
    while True:
        key = input('entre com a chave: ')
        if not key:
            print("saindo ... ")
            break
        else:
            plain1 = input('entre com a mensagem 1: ')
            plain2 = input('entre com a mensagem 2: ')

            cipher1 = xor_cipher(plain1, key)
            cipher2 = xor_cipher(plain2, key)

            print(xor_cipher(plain1, plain2))
            print(xor_cipher(to_ascii(cipher1), to_ascii(cipher2)))

            escuta = to_ascii(xor_cipher(to_ascii(cipher1), to_ascii(cipher2)))
            print('eu conheco a mensagem 2: ', plain2)
            print(to_ascii(xor_cipher(escuta, plain2)))
            print('eu conheco a mensagem 1: ', plain1)
            print(to_ascii(xor_cipher(escuta, plain1)))


# Exemplo de tampering
def teste3():
    plain = 'voce ofereceu R$ 0001, 00 reais pelo meu notebook usado que não funciona'
    key = input('entre com a chave: ')

    cipher = xor_cipher(plain, key, True)
    print('mensagem transmitida: ', cipher)
    a = 17
    b = 21

    tamper = xor_cipher('9999', xor_cipher('0001', cipher[a:b], True), True)
    print(tamper)

    cipher1 = cipher[:a] + tamper + cipher[b:]
    print('mensagem modificada: ', cipher1)
    print('mensagem recuperada: ', xor_cipher(cipher1, key, True))


# Modifique a chamada da função de acordo com o exercício
teste3()
