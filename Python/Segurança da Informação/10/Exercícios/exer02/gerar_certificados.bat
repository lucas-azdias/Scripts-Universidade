openssl req -x509 -nodes -days 3650 -newkey rsa:2048 -keyout bcc_CA.key -out bcc_CA.crt -subj "/C=US/O=Politecnica/CN=BCC Politecnica"

openssl req -newkey rsa:2048 -days 365 -nodes -keyout client.key -out client.csr -subj "/C=BR/ST=Parana/L=Curitiba/O=BCC/CN=Cliente ID1"

openssl req -newkey rsa:2048 -days 365 -nodes -keyout client2.key -out client2.csr -subj "/C=BR/ST=Parana/L=Curitiba/O=BCC/CN=Cliente ID2"

openssl req -newkey rsa:2048 -days 365 -nodes -keyout server.key -out server.csr -subj "/C=BR/ST=Parana/L=Curitiba/O=BCC/CN=server.bcc.com"

openssl x509 -days 365 -req -in client.csr -CA bcc_CA.crt -CAkey bcc_CA.key -CAcreateserial -out client.crt

openssl x509 -days 365 -req -in client2.csr -CA bcc_CA.crt -CAkey bcc_CA.key -CAcreateserial -out client2.crt

openssl x509 -days 365 -req -in server.csr -CA bcc_CA.crt -CAkey bcc_CA.key -CAcreateserial -out server.crt
