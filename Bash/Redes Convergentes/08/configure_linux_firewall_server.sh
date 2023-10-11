# ip server -> 192.168.56.102
# to connect to server -> ssh redes@192.168.56.102
# 						  ssh <computer>@<ip>
# depois coloca a senha e show show

echo "flushing"
iptables -F

echo "dropping all"
iptables -P INPUT DROP
iptables -P OUTPUT DROP
iptables -P FORWARD DROP

echo "accepting loopback"
iptables -A INPUT -i lo -j ACCEPT
iptables -A OUTPUT -o lo -j ACCEPT

echo "accepting dns"
iptables -A INPUT -p UDP --sport 53 -j ACCEPT
iptables -A OUTPUT -p UDP --dport 53 -j ACCEPT

echo "accepting ssh"
iptables -A INPUT -p TCP --dport 22 -j ACCEPT
iptables -A OUTPUT -p TCP --sport 22 -j ACCEPT

echo "accepting HTTP/HTTPS"
iptables -A INPUT -p TCP -m multiport --dport 80,443 -j ACCEPT --tcp-flags ACK ACK
iptables -A INPUT -p TCP -m multiport  --dport 80,443 -j ACCEPT

echo "accepting ntp (time clock)"
iptables -A INPUT -p UDP --sport 123 -j ACCEPT
iptables -A OUTPUT -p UDP --dport 123 -j ACCEPT

echo "showing firewall rules"
iptables -L
