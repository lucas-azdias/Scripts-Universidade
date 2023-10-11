#!/usr/bin/env python3
import socket
import time
from multiprocessing import Process

def cliente(sip, sport, cport=0, cip=''):
    print(f'CLIENTE TCP na porta {cport} (0 = PORTA DINÂMICA)')
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        if cport != 0 : s.bind((cip,cport)) 
        s.connect((sip,sport))
          
    except Exception as e:
        print('erro de bind ou conexão:', e)
        exit()

    print(f'O CLIENTE PORTA={cport} informa SUCESSO - CONEXÃO BEM SUCEDIDA')
    s.send('COM OU SEM SPOOFING?'.encode())
    s.setblocking(0)
    time.sleep(1)
    try:
        data = s.recv(1024)
        print(f'O CLIENTE PORTA={cport} informa SUCESSO - O SERVIDOR RESPONDEU')
        print(f'O CLIENTE PORTA={cport} recebeu', data.decode())
    except:
        print(f'O CLIENTE PORTA={cport} informa FALHA - SEM RESPOSTA')
    
    print(f'O cliente PORTA={cport} encerrou')

def servidor(sport, sip=''):
    print(f'SERVIDOR TCP na porta {sport}')
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        s.bind((sip,sport)) 
        s.listen()  
    except:
        print('erro de bind')
        exit()

    while True:
        conn, addr = s.accept()
        data = conn.recv(1024)
        print(f'O SERVIDOR recebeu um pacote de {addr}')
        print(f'O SERVIDOR recebeu', data.decode())
        conn.send('Tem firewall nessa rede?'.encode())


if __name__ == '__main__':
    if input('Executar servidor? (s/n): ') == 's':
        Process(target=servidor, args=(9999,)).start()
    time.sleep(0.5)
    if input('Executar cliente? (s/n): ') == 's':
        Process(target=cliente, args=('192.168.56.102',9999)).start()
        Process(target=cliente, args=('192.168.56.102', 9999, 80)).start()
