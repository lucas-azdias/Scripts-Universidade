# EXERCICIO 1
# REDIRECIONAMENTO COM IPTABLES

iptables -t nat -F
iptables -t nat -A OUTPUT -o lo -p tcp --dport 9000 -j REDIRECT --to-port 9999
iptables -t nat -I OUTPUT -o lo -p udp --dport 9000 -j REDIRECT --to-port 9999
iptables -t nat -A PREROUTING -i eth0 -p tcp --dport 9000 -j REDIRECT --to-port 9999
iptables -t nat -I PREROUTING -i eth0 -p udp --dport 9000 -j REDIRECT --to-port 9999
iptables -t nat -L

# OBSERVAÇÔES
# 1. Pacotes gerados localmente passam pelas chains OUTPUT e POSTROUTING
# 2. Pacotes externos passam pelas chains PREROUTING e INPUT
# 3. A chain INPUT não é usada em redirecionamento
# 4. Use o comando netstat -t nat -n para ver os mapeamentos do TCP

#----------------------------------------------------------------------------------------------------------------------------------------------------
# EXERCICIO 2
# BALANCEAMENTO EM LOOP BACK

iptables -t nat -F
iptables -t nat -I OUTPUT -o lo -p tcp --dport 9000 -m state --state NEW -m statistic --mode nth --every 2 --packet 0 -j REDIRECT --to-port 9999
iptables -t nat -A OUTPUT -o lo -p tcp --dport 9000 -m state --state NEW -j REDIRECT --to-port 9998
iptables -t nat -I OUTPUT -o lo -p udp --dport 9000 -m statistic --mode nth --every 2 --packet 0 -j REDIRECT --to-port 9999
iptables -t nat -A OUTPUT -o lo -p udp --dport 9000 -j REDIRECT --to-port 9998
iptables -t nat -L

# OBSERVACOES
# 1. Apenas a primeira regra que puder ser atividada é aplicada ao pacote
# 2. -I insere a regra no começo e -A insere a regra no final 
# 3. As regras mais específicas precisam ser colocadas primeiro (-I)
# 4. A ação (JUMP) REDIRECT rediciona portas no host local
# 5. Para ver of fluxos mapeados utilize netstat -nat (para TCP) ou netstat -u -nat (para UDP)
# 6. Não pode haver redirecionamento de um mesmo fluxos 
# 7. O controle de estado NEW é usado para evitar que isso aconteça em exemplos na Internet, mas ele parece ser desnecessário

#---------------------------------------------------------------------------------------------------------------------------------------------------
# EXERCICIO 3
# BALANCEAMENTO COM PROBABILIDADE

iptables -t nat -F
iptables -t nat -I OUTPUT -o lo -p udp --dport 9000 -m statistic --mode random --probability 0.3 -j REDIRECT --to-port 9999
iptables -t nat -A OUTPUT -o lo -p udp --dport 9000 -j REDIRECT --to-port 9998
iptables -t nat -L

# OBSERVAÇÔES
# 1. A probabilidade só irá atingir o valor especificado para um grande número de conexões
# 2. Ver https://ipset.netfilter.org/iptables-extensions.man.html
# 3. É possível verificar as estatísticas com iptables -t nat -vL


#---------------------------------------------------------------------------------------------------------------------------------------------------
# EXERCICIO 4
# BALANCEAMENTO COM DNAT

# FUNCIONA NA MAQUINA LOCAL
iptables -t nat -F
iptables -t nat -I OUTPUT -o lo -p udp --dport 9000 -m statistic --mode nth --every 2 --packet 0 -j DNAT --to-destination 127.0.0.1:9999
iptables -t nat -A OUTPUT -o lo -p udp --dport 9000 -j DNAT --to-destination 127.0.0.1:9998
iptables -t nat -L

# FUNCIONA PARA ACESSO REMOTO
iptables -t nat -F
iptables -t nat -I PREROUTING -p udp --dport 9000 -m statistic --mode nth --every 2 --packet 0 -j DNAT --to-destination 127.0.0.1:9999
iptables -t nat -A PREROUTING -i eth0 -p udp --dport 9000 -j DNAT --to-destination 127.0.0.1:9998
iptables -t nat -L
sysctl -w net.ipv4.conf.all.route_localnet=1
sysctl -w net.ipv4.ip_forward=1

# OBSERVAÇÔES
# 1. Por questões de segurança o linux não faz roteamento de loopback
# 2. A variável route_localnet elimina essa restrição
# 3. A variável ip_forward não afeta a interface de loopback
# 4. Nesse exemplo, os servidores individuais não são acessíveis remotamente, apenas pelo DNAT

#---------------------------------------------------------------------------------------------------------------------------------------------------
# EXERCICIO 5
# BALANCEAMENTO PARA ENDEREÇOS DIFERENTES
iptables -t nat -F
iptables -t nat -I PREROUTING -i eth0 -p udp --dport 9000 -m statistic --mode nth --every 2 --packet 0 -j DNAT --to-destination 127.0.0.1:9999
iptables -t nat -A PREROUTING -i eth0 -p udp --dport 9000 -j DNAT --to-destination 127.0.0.2:9999
iptables -t nat -L
sysctl -w net.ipv4.conf.all.route_localnet=1
sysctl -w net.ipv4.ip_forward=1

# OBSERVACOES
# 1. É possível criar interfaces dummies no linux: 
# - modprobe dummy (/etc/modprobe.d/dummy.conf)
# - ip link add dummy0 type dummy
# - ip addr add 10.0.0.10/24 dev dummy0
# - ip link set dummy0 up




 

