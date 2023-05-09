# Qual dos Stooges enviou a mensagem?
echo "Can you can a can as a canner can can a can?" > mensagem.txt

# Chave Pública do MOE

echo "-----BEGIN PUBLIC KEY-----
MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDqdsSULdJXwpvB8usHwf1kGoy+
UKD7ErT4tTRifhk/gqElet63aSVz0lOyMpJ8D0lQfuoTi6csKpPPjEZwiRpE6Rs/
mlOWMaRkHQ0G1BtWLcdZp+u9JOXm486if5lrpe9r7mLgk25xY1pbMamZKOaMv7hT
PkDIRq1CvurpMa7QGQIDAQAB
-----END PUBLIC KEY-----" > chave_moe.pem

# Chave Pública do LARRY
echo "-----BEGIN PUBLIC KEY-----
MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDSK1tQG94Q2wlpIsBqHVYDkc/Q
pM+oEowK2JyddIlopKr/rO54A3ZpSTBLVAMrA5cn6hQafoe7BFQWXQKCag43FZT5
s4BIIS3oD0Nh5F+yNgm+NyDPM0q6kRy0I1FjRKvf2oT2BxiFsNLhFcrOGwEbdsgt
n1WWtRlh5PnoD+8CdwIDAQAB" > chave_larry.pem

-----END PUBLIC KEY-----

# Chave Pública do CURLY
echo "-----BEGIN PUBLIC KEY-----
MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDDr8RaVF7olyizNV6lMawu7xBa
Ak7TpyJEX6DWKpQw/q2BchVnBkvKCiKEYqiaPAMDufQUge4LkfDTWVNfqz+7K2zQ
cAyQxQ/d/XVy+6rOp78RzAEZZfkGF02D6yTRtzw8f9smOtkbLiR3MUylTkGy2ON5
wrjaY12SIBpNU0gqQQIDAQAB
-----END PUBLIC KEY-----" > chave_curly.pem


# ASSINATURA DIGITAL
echo "SS7k3TumWrVN35rSbxPcKnrD1sgwNQLvs6B7Tqrss7cwFwQYEGVk07u0u49wwY2c
kDyYN4QbL/E4l+Yrpif0bpha5Z9aE2i3Pzmt2t+riopX2s34Voy78Hd6uQR9MQzW
f5GZBCNsD4ofjaPuzopYHtTsAh54+RiNk8wAnS3V75c=" > assinatura.pem

openssl base64 -d -in assinatura.pem -out assinatura.bin
