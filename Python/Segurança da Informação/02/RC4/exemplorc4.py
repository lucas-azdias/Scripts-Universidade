from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
# É uma boa biblioteca pois permite o uso de forma simples ou de forma mais avançada

while True:

    chave = input('Digite a chave secreta: ')

    chave = chave.encode() # chave em bytes

    meu_cipher = Cipher( algorithms.ARC4(chave), mode=None)
    cifrador = meu_cipher.encryptor()
    decifrador = meu_cipher.decryptor()


    mensagem = input('Digite a mensagem: ').encode()
    ciphertext = cifrador.update(mensagem)

    print('Mensagem cifrada: ', ciphertext)

    plaintext = decifrador.update(ciphertext)
    print('Mensagem decifrada: ', plaintext.decode())