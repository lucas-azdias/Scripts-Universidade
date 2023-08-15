# Ataques contra eval
# __import__('os').system('mkdir opa')
# __import__('os').system('dir')
# __import__(‘os’).system(‘rm –rf /’)

def calculadora():
    expressao = input('Digite a operacao: ')
    print( 'resultado: ', eval(expressao))


# Ataque contra exec
# Exec executa códigos em python
# a=10;b=20;print(a+b)

def codigoDinamico():
    print('Digite o código:')
    val = input()
    exec(val) 
    
# Ataque contra subprocess
# 127.0.0.1; ls -l

import shlex
import subprocess

def pingRemoto():
    endereco = input('Digite o ip: ')
    comando = f"ping -c 1 {endereco}"
    subprocess.Popen(comando, shell=True)


def pingRemoto2():
    endereco = input('Digite o ip: ')
    comando = "ping -c 1 {}".format(endereco)
    args = shlex.split(comando)
    subprocess.Popen(args)


# while True:
#     calculadora()

while True:
    codigoDinamico()

# while True:
#     try:
#         pingRemoto()
#     except Exception as e:
#         print(e)

