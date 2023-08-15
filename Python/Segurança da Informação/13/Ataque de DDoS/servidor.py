import socket
import threading

#--------------------------------------------------------------
# FUNÇÕES

def TrataCliente(conn):
    print(' atendidos: ', clientes)
    while True:

        try:
            data = conn.recv(1000)
            if not data:
                break
        except Exception as e:
            pass



#--------------------------------------------------------------
# PROGRAMA PRINCIPAL

HOST = ''     # ANY_IP = todos os IPs do HOST
PORTA = 9999

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    s.bind((HOST, PORTA))
except:
    print('# erro de bind')
    exit()

s.listen(10)

print('aguardando conexoes em ', PORTA)

#--------------------------------------------------------------
# LOOP para tratar clientes
clientes = 0

while True:
    conn, addr = s.accept()
    threading.Thread( target=TrataCliente, args = (conn, ) ).start()
    clientes += 1
    print(f'Total de conexoes: {clientes}. Ultima conexao: {addr}')

#--------------------------------------------------------------

