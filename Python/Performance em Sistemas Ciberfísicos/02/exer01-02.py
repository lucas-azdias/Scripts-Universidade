"""
Crie uma função que troque o valor de duas variáveis sem usar
uma variável temporária ou operações aritméticas.
"""


def swapVars(a, b):
    a <<= len(bin(b)) - 2
    for i in range(len(bin(b)) - 2):
        a ^= (1 << i) & b
    b = a >> len(bin(b)) - 2
    a ^= b << (len(bin(a)) - 2) - (len(bin(b)) - 2)


if __name__ == "__main__":
    a0 = 0b1101
    b0 = 0b0110

    a1 = a0
    b1 = b0

    swapVars(a1, b1)

    print(f"O valor de a era {bin(a0)} e de b era {bin(b0)}, e, após a inversão, a é {bin(a1)} e b é {bin(b1)}")
