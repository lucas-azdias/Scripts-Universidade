"""
Crie uma função que recebe dois inteiros como argumento, valor e
n e devolve valor com o enésimo bit invertido.
"""

def invertBit(valor, n):
    return valor ^ (1 << n - 1)


if __name__ == "__main__":
    valor = 0b11111111
    n = 4

    print(f"O valor {bin(valor)} com o {n}º bit invertido é igual a {bin(invertBit(valor, n))}")
