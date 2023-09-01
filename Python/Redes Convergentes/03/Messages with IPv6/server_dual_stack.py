#!/usr/bin/env python3
import socket
import sys
import time

# Os sistemas operacionais podem não suportar todos os modos do IPv6
# Alguns sistemas suportam pilha dupla, em um único socket
try:
    socket.AF_INET6
    socket.IPPROTO_IPV6
    socket.IPV6_V6ONLY
except AttributeError:
    print('Alguns desses atributos não são suportados')

NIC4 = '0.0.0.0'
NIC6 = '::'

porta = int(input('Porta do servidor: '))

s6 = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
# Se o sistema suportar pilha dupla haverá conflito de porta se o modo não for restrito para IPv6
s6.setsockopt(socket.IPPROTO_IPV6, socket.IPV6_V6ONLY, False)

try:
    s6.bind((NIC6, porta))
except:
    print('# erro de bind IPv6')
    print('# -- este socket é dual-stack?')
    sys.exit()

s6.setblocking(0)

while True:
    try:
        data, addr = s6.recvfrom(1024)
        print(f'recebi {data} do endereco {addr} pelo socket s6')
    except:
        pass

        time.sleep(1)
