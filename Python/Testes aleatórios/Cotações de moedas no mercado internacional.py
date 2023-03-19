print("\n| Cotações de moedas no mercado internacional |\n")

#Head
import forex_python.converter

#Body
base_currency = input("Moeda base de cotação [AAA]: ").upper()
final_currency = input("Moeda final de cotação [AAA]: ").upper()

base_amount = float(input("Valor na moeda base: "))
final_amount = round(forex_python.converter.CurrencyRates().convert(base_currency, final_currency, base_amount), 3)

print(f"Valor na moeda final: {final_amount} {base_currency}")
