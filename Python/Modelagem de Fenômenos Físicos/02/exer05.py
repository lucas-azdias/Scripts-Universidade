"""
Os legistas determinam a hora da morte, devido a um assassinato ou acidente,
usando a seguinte fórmula:
Onde 𝑇0 é a temperatura ambiente, 𝑇1 é a temperatura do corpo na hora da
morte. Um homem morreu a meia-noite, na varanda da sua própria casa, sem
qualquer sinal de violência. Considere que a temperatura ambiente permaneceu
constante em 21º𝐶 e que a temperatura do corpo na hora da morte era normal e
estava em 36.5º𝐶. Qual será a temperatura do corpo às 8: 00 ℎ quando for
encontrado pelo carteiro.
"""

import matplotlib.pyplot as pyplot
import numpy as np


def main():
    # Variáveis inicias
    temp_amb = 21 # Temperatura ambiente (constante)
    temp0_corpo = 36.5 # Temperatura inicial do corpo
    time_range = [0, 16] # Das 0:00 até 8:00
    step = 0.2

    def tempFinal_corpo(x):
        # Fórmula para a temperatura final do corpo dado o tempo já morto
        return temp_amb + (temp0_corpo - temp_amb) * (0.97**x)

    # Cálculo dos valores de X e Y
    x = np.arange(min(time_range), max(time_range), step)
    y = tempFinal_corpo(x)

    # Configuração do gráfico
    pyplot.title("Gráfico de pontos da temperatura do corpo morto pelo tempo")
    #pyplot.gca().set_aspect('equal', 'datalim')
    pyplot.xlabel("Tempo")
    pyplot.ylabel("Temperatura")

    # Plotagens ao gráfico
    pyplot.scatter(x, y, color="blue")

    # Mostrar gráfico
    pyplot.show()

    print(f"Para 8 horas é {tempFinal_corpo(8):.2f}°C")


if __name__ == "__main__":
    main()
