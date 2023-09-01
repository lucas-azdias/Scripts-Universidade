#!/usr/bin/env python3
import socket
from ipaddress import ip_address, IPv4Address, IPv6Address

s4 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s6 = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)

while True:

    ip = input('IP de destino: ')
    try:
        ip_address(ip)
    except:
        print("IP inválido.")
        continue
    porta = int(input('Porta de destino: '))
    msg = input('Digite a mensagem: ')

    try:
        s4.sendto(msg.encode(), (ip, porta))
        print('transmitindo em IPv4')
    except:
        s6.sendto(msg.encode(), (ip, porta))
        print('transmitindo em IPv6')
