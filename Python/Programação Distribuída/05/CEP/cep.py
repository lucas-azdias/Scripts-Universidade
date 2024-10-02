from json import loads
from requests import get
from urllib.parse import urlencode


url = "http://cep.republicavirtual.com.br/web_cep.php?"
params = {"cep": "", "formato": "json"}
print(url + urlencode(params))

while True:
    cep = input("Digite um CEP: ").replace("-", "")
    if len(cep) == 8 and cep.isnumeric():
        break
params["cep"] = cep

response = loads(get(url, params).text)

print(f'{response["tipo_logradouro"].strip()} {response["logradouro"].strip()} - {response["bairro"].strip()}, {response["cidade"].strip()}-{response["uf"].strip()}')
