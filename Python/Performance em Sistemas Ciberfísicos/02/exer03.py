"""
Escolha um site de livros gratuitos na internet e realize o seguinte exercício:
baixe um livro que tenha mais de cem páginas, usando uma requisição https
e a linguagem Python. Este arquivo deve ser baixado para a sua máquina ou
para qualquer ambiente online. Uma vez que o arquivo esteja disponível
você deverá dividir este arquivo em arquivos com no máximo 1000 palavras
e salvar cada um dos arquivos resultantes da divisão na mesma pasta onde
salvou o arquivo original. Por fim, você deverá carregar uma dúzia dos
arquivos de 1000 palavras em uma estrutura de dados em memória. Você
pode usar uma lista de strings.
"""

import requests
import PyPDF2


default_folder = "result"
link_book = "https://marcosfabionuva.files.wordpress.com/2011/08/do-livre-arbc3adtrio.pdf"
file_name = "livre-arbitrio-santo-agostinho.pdf"

outfile_name = "arquivo"
outfile_ext = "txt"
outfile_words = 1000

# Baixando arquivo
with open(default_folder + "/" + file_name, "wb") as file:
    file.write(requests.get(link_book, allow_redirects=True).content)
    file.close()


# Abrindo o arquivo PDF e extraindo os dados
pdfFile = open(default_folder + "/" + file_name, "rb")
pdfReader = PyPDF2.PdfReader(pdfFile)

text = ""
for page in pdfReader.pages:
    text += page.extract_text()

pdfFile.close()


text = text.replace("\n ", "\n") # Remove inconsistências
text = text.replace(" \n", "\n") # Remove inconsistências

total_words = text.count(" ") + text.count("\n")

# Gera os arquivos com ~1000 palavras cada
word_counter = 0
file_counter = 0
while word_counter < total_words:
    with open(default_folder + "/" + f"{outfile_name}{file_counter:03}.{outfile_ext}", "w", encoding="UTF-8") as file:
        for i in range(outfile_words):
            skip = min(text.find(" "), text.find("\n")) + 1
            file.write(text[0:skip])
            text = text[skip:]
            word_counter += 1
        file.close()
    file_counter += 1

print(total_words, file_counter)


# Carrega 12 arquivos na memória
data = list()
for i in range(12):
    with open(default_folder + "/" + f"{outfile_name}{i:03}.{outfile_ext}", "r", encoding="UTF-8") as file:
        data.append(file.read())
        file.close()

print(data)
