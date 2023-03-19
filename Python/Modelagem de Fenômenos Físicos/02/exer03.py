"""
Encontre o diâmetro de uma árvore com 2000 anos com seis casas
decimais. E plote um gráfico mostrando o diâmetro do tronco
anualmente.
"""

import matplotlib.pyplot as pyplot
import numpy as np


def main():
    # Variáveis inicias
    t = 2000
    x_range = [0, 2 * t]
    step = 100

    def diamentroBaoba(x):
        # Fórmula para o diâmetro do tronco pelo tempo (5.4 é para o baobá)
        return 5.4 / (1 + 2.9 * (np.e**(-0.001*x)))

    # Cálculo dos valores de X e Y
    x = np.arange(min(x_range), max(x_range), step)
    y = diamentroBaoba(x)

    # Configuração do gráfico
    pyplot.title("Gráfico de pontos do diâmetro do tronco pelo tempo")
    #pyplot.gca().set_aspect('equal', 'datalim')
    pyplot.xlabel("Tempo")
    pyplot.ylabel("Diâmetro")

    # Plotagens ao gráfico
    pyplot.scatter(x, y, color="blue")

    # Mostrar gráfico
    pyplot.show()

    print(f"Para {t} anos é {diamentroBaoba(2000):.2f} metros")


if __name__ == "__main__":
    main()
