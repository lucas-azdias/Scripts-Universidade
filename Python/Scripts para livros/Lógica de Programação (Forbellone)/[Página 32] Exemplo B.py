#Cálculo de quantidade de latas de tinta para pintar um tanque cilíndrico e o custo delas

import math

#Head
radius = float(input("Raio do tanque: "))
height = float(input("Altura do tanque: "))
area = 0

volumePaint = float(input("Volume da lata de tinta: "))
areaPaint = float(input("Área pintada por litro de tinta: "))
pricePaint = float(input("Preço da lata de tinta: "))
amountPaint = 0
totalCost = 0

#Body
area = 2 * (math.pi * radius ** 2) + (2 * math.pi * radius * height)
amountPaint = math.trunc(area / areaPaint)
if area / areaPaint > amountPaint:
    amountPaint += 1
totalCost = pricePaint * amountPaint

print(f"\nVocê precisará de {amountPaint} latas de tintas que custarão a você {totalCost:.2f} reais")