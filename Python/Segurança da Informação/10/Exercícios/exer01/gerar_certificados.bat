openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout server.key -out server.crt -subj "/C=BR/ST=Parana/L=Curitiba/O=BCC/CN=server.bcc.com"

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout client.key -out client.crt -subj "/C=BR/ST=Parana/L=Curitiba/O=BCC/CN=Cliente ID1"

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout client2.key -out client2.crt -subj "/C=BR/ST=Parana/L=Curitiba/O=BCC/CN=Cliente ID2"

copy client.crt + client2.crt allclients.crt
