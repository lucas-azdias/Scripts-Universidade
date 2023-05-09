echo "INICIANDO TESTES..."


echo "TESTE MOE"
openssl dgst -sha256 -verify chave_moe.pem -signature assinatura.bin mensagem.txt


echo "TESTE LARRY"
openssl dgst -sha256 -verify chave_larry.pem -signature assinatura.bin mensagem.txt


echo "TESTE CURLY"
openssl dgst -sha256 -verify chave_curly.pem -signature assinatura.bin mensagem.txt
