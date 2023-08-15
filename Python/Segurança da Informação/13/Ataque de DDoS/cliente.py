import socket
import threading
import time

def fazConexao(s, ip, porta, tempo=0):
    try:
        s.connect((ip,porta))
        if tempo > 0: 
            time.sleep(tempo)
    except Exception as e:
        print(e)
    
    return

#--------------------------------------------------------------
# PROGRAMA PRINCIPAL
IP = '127.0.0.1'
PORTA = 9999

n = int(input('Numero de conexoes: '))
tempo = int(input('Tempo em segundos: '))

conexoes = []

for i in range(n):
    print(i)
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    t = threading.Thread(target=fazConexao, args=(s,IP,PORTA,tempo))
    t.start()
    conexoes.append(t)

for t in conexoes: t.join()

