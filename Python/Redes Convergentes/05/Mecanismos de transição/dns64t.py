# python -m pip install dnspython
# python -m pip install ifaddr
# python -m pip install icmplib

import socket
import dns.resolver
import ifaddr
from ping3 import ping, verbose_ping
from icmplib import ping


# DNS do google
# 2001:4860:4860::8888 
# 2001:4860:4860::8844

print('TESTE DE CONECTIVIDADE IPv6 GLOBAL')
res = ping('2001:4860:4860::8888')  # Returns delay in seconds.
print(res)
if not res.is_alive:
    print('Esta máquina nao tem ACESSO GLOBAL IPv6')
else:
    print('ACESSO GLOBAL IPv6')
 

# Verificacao dos adaptadores do dispositivo
print('\n---------------')
adapters = ifaddr.get_adapters()

for adapter in adapters:
    print("\nNIC: " , adapter.nice_name)
    for ip in adapter.ips:
        print(ip.ip,"/", ip.network_prefix)


def consulta_dns(fqdn, nameserver="1.1.1.1", qtype="AAAA"):
    resolver = dns.resolver.Resolver(configure=False)
    resolver.nameservers = [nameserver]
    answer = resolver.resolve(fqdn, qtype)
    if len(answer) == 0:
        return None
    else:
        return str(answer[0])

print('\n---------------')
print('tem suporte a IPv6: ', socket.has_ipv6)
print('tem suporte a pilha dupla: ',socket.has_dualstack_ipv6())

print('\n---------------')
while True:
    try:
        fqdn = input('Digite o FQDN: ')
        print( consulta_dns(fqdn, qtype="A") )
        print( consulta_dns(fqdn, qtype="AAAA") )
    except Exception as e:
        print(e)