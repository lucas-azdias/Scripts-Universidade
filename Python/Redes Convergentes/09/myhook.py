# https://github.com/oremanj/python-netfilterqueue
# apt-get install build-essential python3-dev libnetfilter-queue-dev
# sudo apt-get install python3-pip
# python3 -m pip install NetfilterQueue --break-system-packages
# python3 -m pip install scapy --break-system-packages
# iptables -I INPUT -p ICMP -j NFQUEUE --queue-num 1


from netfilterqueue import NetfilterQueue
import scapy.all as scapy
from scapy.layers.inet import IP, TCP

count = 0

def print_and_accept(pkt):
    global count
    count += 1
    print(count, pkt)
    if count % 2 == 0:
        pkt.accept()
    else:
        pkt.drop()
        p = scapy.IP(pkt.get_payload())
        print(p.show())

nfqueue = NetfilterQueue()
nfqueue.bind(1, print_and_accept)
try:
    nfqueue.run()
except KeyboardInterrupt:
    print('')

nfqueue.unbind()
