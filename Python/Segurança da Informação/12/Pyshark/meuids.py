# pip install pyshark
# python -m pip install pyshark
# https://github.com/KimiNewt/pyshark
# https://github.com/StopDDoS/packet-captures

import pyshark
from datetime import timedelta
from datetime import datetime
       
# ESSA FUNCAO MOSTRA COMO PEGAR OS DADOS DOS PACOTES
# capture é uma captura feita em arquivo ou online
def imprime_sumario(capture):
    for p in capture:
        print(p.layers)
        print(p.sniff_time)
        print(p.eth.type)
        print(p.length)

        if p.eth.type == '0x0800': # SE FOR PACOTE IP
            print('pacote IP', p.ip.src,"->", p.ip.dst, p.ip.proto )
            if p.ip.proto == '6': # SE FOR PACOTE TCP
                print('pacote TCP', p.tcp.srcport, p.tcp.dstport, p.tcp.flags)

# Essa função mostra como testar os flags TCP
# RES URG ACK PSH RST SYN FIN
def retornaFlag(p):
    try:
        if p.eth.type == '0x0800' and p.ip.proto == '6' :
                flags = str(p.tcp.flags)
                f = []
                if eval(flags) & 1: f.append('FIN')
                if eval(flags) & 2: f.append('SYN')
                if eval(flags) & 4: f.append('RST')
                if eval(flags) & 16: f.append('ACK')
                return f      
        else:
            return [] 
    except Exception as e:
        print('Erro', e)

# Essa função precisa de tshark instalado
def sniffRede(nic, tempo):
    # nic = 'enp3s0'
    capture = pyshark.LiveCapture(interface= nic )
    capture.sniff(timeout=tempo)
    return capture


if __name__ == '__main__':

    capture = pyshark.FileCapture('semAtaque.pcap')
    # capture = pyshark.FileCapture('desafio2.pcapng')
    # imprime_sumario(capture)

    # EXERCICIO 1: Determine os endereços IP de origem presentes na captura
    # DICA: use set() para eliminar os IPs repetidos
    ip_origens = []
    for p in capture:
        if p.eth.type == '0x0800':  # SE FOR PACOTE IP
            ip_origens.append(p.ip.src)
    print("\n", set(ip_origens))

    # EXERCICIO 2: Conte o número de pacotes enviados por cada origem
    ip_origens = {}
    for p in capture:
        if p.eth.type == '0x0800':  # SE FOR PACOTE IP
            if not p.ip.src in ip_origens:
                ip_origens[p.ip.src] = 1
            else:
                ip_origens[p.ip.src] += 1
    print("\n", ip_origens)

    # EXERCICIO 3: Determine o endereço IP de origem que mais enviou pacotes
    # DICA: Keymax = max( dict, key= lambda x: dict[x])

    # EXERCICIO 4: Determine o IP de destino para onde foi enviado mais tráfego (em volume)

    # EXERCICIO 5: Crie uma função que conta o número de [SYN] enviados por cada IP de origem

    # EXERCICIO 6: que conta o número de SYN enviados para cada IP de destino

    # EXERCICIO 7: Determine o IP do adversário e da vítima do ataque de SYN FLOOD

    # EXERCICIO 8: O que você pode fazer para ter certeza que é um ataque?
    # DICA: calcule a taxa de envio de SYN
    # intervalo = ultimo_SYN.sniff_time -  primeiro_SYN.sniff_time
