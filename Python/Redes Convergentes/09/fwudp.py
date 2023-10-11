#!/usr/bin/env python3
import socket
import time
from multiprocessing import Process

def cliente(sip, sport, cport=0, cip=''):
    print(f'CLIENTE UDP na porta {cport} (0 = PORTA DINÂMICA)')
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
    
    try:
        if cport != 0 : s.bind((cip,cport))   
    except Exception as e:
        print('erro de bind', e)
        exit()

    print('O CLIENTE vai testar o acesso ..')
    s.sendto('COM OU SEM SPOOFING?'.encode(), (sip,sport))
    time.sleep(1)
    try:
        data, addr = s.recvfrom(1024)
        print(f'O CLIENTE PORTA={cport} informa SUCESSO - O SERVIDOR RESPONDEU')
        print(f'O CLIENTE PORTA={cport} recebeu', data.decode())
    except:
        print(f'O CLIENTE PORTA={cport} informa FALHA - SEM RESPOSTA')
    
    print(f'O cliente PORTA={cport} encerrou')

def servidor(sport, sip=''):
    print(f'SERVIDOR UDP na porta {sport}')
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    try:
        s.bind((sip,sport))   
    except:
        print('erro de bind')
        exit()

    while True:
        data, addr = s.recvfrom(1024)
        print(f'O SERVIDOR recebeu um pacote de {addr}')
        print('O SERVIDOR recebeu', data.decode())
        s.sendto('Tem firewall nessa rede?'.encode(), addr)


if __name__ == '__main__':
    if input('Executar servidor? (s/n): ') == 's':
        Process(target=servidor, args=(9999,)).start()
    time.sleep(0.5)
    if input('Executar cliente? (s/n): ') == 's':
        Process(target=cliente, args=('192.168.56.102',9999)).start()
        Process(target=cliente, args=('192.168.56.102', 9999, 5300)).start()
