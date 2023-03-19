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
    x_range = [-1, 1]
    step = 0.001

    # Cálculo dos valores de X e Y
    x = np.arange(min(x_range), max(x_range), step)
    y1 = (4/5) * (np.sqrt(np.abs(x)) - np.sqrt(1 - x**2))
    y2 = (4/5) * (np.sqrt(np.abs(x)) + np.sqrt(1 - x**2))

    # Configuração do gráfico
    pyplot.title("Gráfico de pontos da Função 2")
    pyplot.gca().set_aspect('equal', 'datalim')
    pyplot.xlabel("x")
    pyplot.ylabel("y")
    
    # Plotagens ao gráfico
    pyplot.scatter(x, y1, color="blue") # Parte de baixo
    pyplot.scatter(x, y2, color="blue") # Parte de cima

    # Mostrar gráfico
    pyplot.show()


if __name__ == "__main__":
    main()
