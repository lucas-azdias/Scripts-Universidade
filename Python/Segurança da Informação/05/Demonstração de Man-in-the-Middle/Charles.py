import socket
import RSALib as RSA
import AESLib as AES


# 1) ALICE GERA AS CHAVES PÚBLICAS E PRIVADA

chavePriObj, chavePriPEM = RSA.geraChavePrivada(2048, "chavepriva.pem")
chavePubObj, chavePubPEM = RSA.geraChavePublica(chavePriObj, "chavepublica.pem")

print('ESTA TELA PERTENCE A CHARLES')

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('', 9999))

alice = ('127.0.0.1', 9998)

def MITM_Passivo():
    while True:   
        data, addr = s.recvfrom(1024) 
        if data.decode() == 'HELLO':
            bob = addr

        if addr == bob:    
            s.sendto(data, alice)
            print(data, '\n')
        else:
            s.sendto(data, bob)
            print(data, '\n')

def MITM_Ativo():
    while True:   
        data, addr = s.recvfrom(1024) 
        if data.decode() == 'HELLO':
            bob = addr

            # Cria chave secreta com Bob
            s.sendto(chavePubPEM, bob )
            chaveCifrada, addr = s.recvfrom(1024)
            chaveSecreta = RSA.decifraComPrivada(chaveCifrada, chavePriObj, text=False)

            # Cria chave secreta com Alice
            s.sendto('HELLO'.encode(), alice )
            data, addr = s.recvfrom(1024) 
            chavePubObj = RSA.converteChavePublica(data)
            chave, chavePEM = AES.geraChave(128)
            chavecifrada = RSA.cifraComPublica(chave, chavePubObj, text=False)
            s.sendto(chavecifrada, alice )
            ciphertext, addr = s.recvfrom(1024) 
            plaintext = AES.decifraMensagem(ciphertext, chave) 
            print("ROUBEI A MENSAGEM:")
            print(plaintext)

            # Repassa a mensagem para Bob
            ciphertext = AES.cifraMensagem(plaintext, chaveSecreta)
            s.sendto(ciphertext, bob ) 

#MITM_Passivo()
MITM_Ativo()






