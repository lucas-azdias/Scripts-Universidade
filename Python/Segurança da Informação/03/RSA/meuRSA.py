def find_primos(lower, upper):
    primos = [ ]

    for num in range(lower, upper + 1):
       if num > 1:
           for i in range(2, num):
               if (num % i) == 0:
                   break
           else:
               primos.append(num)
    return(primos)


def find_divisores(num):
    divisores = [ ]

    for i in range(2, num+1):
        if (num % i) == 0:
            divisores.append(i)
            
    return(divisores)

def testa_coprimo(a,b):
    x = find_divisores(a)
    y = find_divisores(b)
    if len(list(set(x) & set(y))) == 0:
        return (True)
    else:
        return (False)

    
def encontra_d(e, F):
    for i in range(0,10000):
        if (i * e) % F == 1:
            break
    if(i == 9999): print('nao achei')
    return (i)

p = 61
q = 53
n = p * q
F= (p-1)*(q-1)
print("Escolher um número entre 1 e", F, "comprimo com ", n)
e = 97
print(testa_coprimo(e, n))
d =encontra_d(e, F)
pub = (e, n)
pri = (d, n)
print(pub, pri)
print( d * e % F)
c = ord('x')**e % n
print(chr(c))
m = c ** d % n
print(chr(m))