"""
A Escala de Richter a magnitude de um terremoto, 𝑅, é dada por:
Onde 𝐼 representa a intensidade do terremoto que está sendo medido e 𝐼0 é a
intensidade padrão de referência. Determine a intensidade do terremoto do
terremoto de 7,8 que abalou a Turquia em 06 de fevereiro de 2023 em relação a
intensidade padrão de referência. Trace um gráfico mostrando a intensidade deste
terremoto em comparação com o terremoto mais intenso de 2004 (Indonésia) e
com o terremoto do Chile de 1960.
"""

import matplotlib.pyplot as pyplot
import sympy as sy


def main():
    # Variáveis inicias
    i0 = 10**(-5)
    values_i = {
        "Turkey - 2023": 7.8,
        "Indonésia - 2004": 9.1,
        "Chile - 1960": 9.5
    }

    r = sy.Symbol('r')

    # Cálculo dos valores de X e Y
    x = [sy.solve(sy.log(i / i0, 10) - r, r)[0] for i in values_i.values()] # Fórmula para a Escala de Richter
    y = list(values_i.values())

    # Configuração do gráfico
    pyplot.title("Gráfico de pontos da intensidade dos terremotos")
    #pyplot.gca().set_aspect('equal', 'datalim')
    pyplot.xlabel("Intensidade")
    pyplot.ylabel("Escala Richter")

    # Plotagens ao gráfico
    keys = list(values_i.keys())
    for i in range(len(values_i)):
        pyplot.scatter(x[i], y[i], color="blue")
        pyplot.annotate(keys[i], xy=(x[i] + 0.0025, y[i] + 0.0025))

    # Mostrar gráfico
    pyplot.show()


if __name__ == "__main__":
    main()
