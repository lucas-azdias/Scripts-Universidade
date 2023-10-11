#!/usr/bin/env python3

import socket
import time
from multiprocessing import Process
from threading import Thread
import time

conns = []

def trataCliente(conn, sid):
    global conns
    cid = None
    while True:
        try:
            data = conn.recv(1024)
            if not data:
                break

            msg = data.decode()
            msg = msg.split('=')

            if len(msg) == 2 and msg[0] == 'ID':
                if msg[1] not in conns:
                    cid = msg[1]
                    conns.append(cid)
            if cid == None:
                print('uma conexão foi recusada: o cliente não se identifiou')   
                break    
            else:
                print(f'Servidor {sid}: {conns}' ) 
                print(f'Servidor {sid} - conexoes ativas {len(conns)}')

        except Exception as e:
            # print(e)
            break
    
    if cid is not None:
        conns.remove(cid)
    
    print(f'Servidor {sid} - conexoes ativas {len(conns)}')

#-------------------------------------------------------------------------------    

def Servidor(porta, sid):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        s.bind(('', porta))
        print(f'Servidor {sid} ativado na porta {porta}')
    except Exception as e:
        print(f'Servidor {sid} FALHOU:', e)
        exit()

    s.listen(5)


    while True:
        try:
            conn, addr = s.accept()
            Thread(target=trataCliente, args=(conn,sid)).start()
        except:
            pass


if __name__ == '__main__':
    TESTE = input('Qual servidor? <ENTER> para todos: ')

    if not TESTE:
        Process(target=Servidor, args=(9999, 'S1' )).start()
        Process(target=Servidor, args=(9998, 'S2' )).start()
    elif TESTE == '1':
        Process(target=Servidor, args=(9999, 'S1' )).start()
    elif TESTE == '2':
        Process(target=Servidor, args=(9998, 'S2' )).start()
    else:
        print('Esta opção nao existe')
