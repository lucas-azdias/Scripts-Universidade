#!/usr/bin/env python3
import socket
from multiprocessing import Process
import time
from random import randint

def clientTCP(ip, porta, id, inicio, tempo ):
    time.sleep(inicio)
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        s.connect((ip,porta))
        s.send(f'ID={id}'.encode())
        if tempo > 0:
            time.sleep(tempo)
        else:
            data = s.recv(1024)
            print('id:', data)

    except Exception as e:
        print(f'Cliente {id} FALHOU: ', e)

        
            

if __name__ == '__main__':

    TESTE = int(input('Entre com o número do teste: '))

    if TESTE == 1:
        print('Conexoes permanentes chegando em intervalos de 5 segundos')
        for i in range(0,10):
            Process(target=clientTCP, args=('127.0.0.1', 8080, f'C{i}', 5*i, 0 )).start()

    elif TESTE == 2:
        print('Conexoes com duracao aleatoria chegando em intervalos de 5 segundos')
        for i in range(0,10):
            Process(target=clientTCP, args=('127.0.0.1', 8080, f'C{i}', 5*i, randint(5,10) )).start()

    elif TESTE == 3:
        print('Mixto de conexões permanentes e aleatórias')

        tempo = lambda i : 0 if i%2 == 0 else 5
        
        for i in range(0,10):
            Process(target=clientTCP, args=('127.0.0.1', 8080, f'C{i}', 0, tempo(i) )).start()

        time.sleep(5)

        for i in range(10, 20):
            Process(target=clientTCP, args=('127.0.0.1', 8080, f'C{i}', 0, 0 )).start()
    else:
        print('Teste desconhecido')


    
    