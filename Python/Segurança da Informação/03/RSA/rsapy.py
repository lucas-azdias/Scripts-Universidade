# python3 -m pip install rsa

import rsa
import base64
import time

# Private key decryption
def fun1(key):
    publicKey, privateKey = rsa.newkeys(key)
    cipher = rsa.encrypt(b'Hello World!', publicKey)
    base64Text = base64.b64encode(cipher).decode()

    print(base64Text)

    text = rsa.decrypt(base64.b64decode(base64Text.encode()), privateKey)
    print(text.decode())


#-----------------------------------------------

b = time.time()
fun1(512)
print( time.time() - b) 

b = time.time()
fun1(1024)
print( time.time() - b) 

b = time.time()
fun1(2048)
print( time.time() - b) 