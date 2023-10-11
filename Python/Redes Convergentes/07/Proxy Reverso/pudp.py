#!/usr/bin/env python3
import socket
from multiprocessing import Process
import time, random

def mostraip():
    hostname = socket.gethostname()
    hostip = socket.gethostbyname(hostname)
    print('host: {} ip: {}'.format(hostname, hostip))

def serverUDP(myip, porta, id):
    myclients = {}
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try:
        s.bind((myip,porta))
        print(f'Servidor UDP {id} no IP {myip} e porta {porta}')
    except:
        print('erro de bind')

    while True:
        data, addr = s.recvfrom(1024)
        cid = data.decode()
        count = myclients.get(cid, 0)
        myclients[cid] = count + 1
        #print(f'{id} recebeu {data.decode()} de {addr}')
        print(f'SERVIDOR {id} = {myclients}')
        s.sendto(id.encode() , addr )

def clientUDP(ip, porta, id, myip=''):
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    #s.setsockopt( socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    if myip != '' : 
        s.bind(('127.0.0.1',0))
        print(f'{id} ativado no ip {myip}')
    else:
        print(f'{id} ativado em todas as interfaces')

    for i in range(5):
        #msg = f'REQUEST from {id}'
        msg = id
        # random.randint(2,10)
        time.sleep(5)
        try:
            s.sendto(msg.encode(), (ip, porta))
            s.setblocking(0)
            time.sleep(0.5)
            while True:
                data, addr = s.recvfrom(1024)
                #print(f'{id} recebeu {data.decode()} de {addr}')
        except:
            s.setblocking(1)
    
    print(f'{id} encerrou no ip {myip}')
            

if __name__ == '__main__':
    mostraip()
    if input('Ativar servidores? (s/n):') == 's':
        #Process(target=receptor, args=('',9999,'SX')).start()
        Process(target=serverUDP, args=('127.0.0.1', 9999,'S1')).start()
        Process(target=serverUDP, args=('127.0.0.2', 9999,'S2')).start()
    time.sleep(1)
    if input('Ativar clientes? (s/n):') == 's':
        for i in range(1,5):
            cid = f'C{i+1}'
            cip = f'127.0.0.{i+2}'
            Process(target=clientUDP, args=('172.21.206.181', 9000, cid, '')).start()
 
   