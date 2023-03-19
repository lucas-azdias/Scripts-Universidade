"""
Faça um algoritmo em Python para plotar as funções listadas a seguir
com título, eixos, com ticks destacados, e coordenadas plotadas
próximo as curvas. Lembre-se não plotar todos os pontos das funções
escolha apenas alguns pontos para manter os gráficos legíveis.
"""

import matplotlib.pyplot as pyplot
import numpy as np

def main():
    # Variáveis inicias
    x_range = [-50, 50]
    step = 0.01

    # Cálculo dos valores de X e Y
    x = np.arange(min(x_range), max(x_range), step)
    y = (x**2 - 25) / (x**2 - 7*x - 10)

    # Configuração do gráfico
    pyplot.title("Gráfico de pontos da Função 1")
    #pyplot.gca().set_aspect('equal', 'datalim')
    pyplot.xlabel("x")
    pyplot.ylabel("y")
    
    # Plotagens ao gráfico
    pyplot.scatter(x, y, color="blue")

    # Mostrar gráfico
    pyplot.show()


if __name__ == "__main__":
    main()
