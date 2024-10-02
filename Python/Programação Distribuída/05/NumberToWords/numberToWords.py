from zeep import Client


url = "https://www.dataaccess.com/webservicesserver/NumberConversion.wso"
client = Client(url + "?wsdl")
print(client.service.NumberToWords(123))
