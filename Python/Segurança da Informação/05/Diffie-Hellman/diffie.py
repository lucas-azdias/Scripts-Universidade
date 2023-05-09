from random import randint
 
if __name__ == '__main__':
 
    # P é um número primo
    P = 23
     
    # G é um número que deve satisfazer uma propriedade em relação a P (Primitive Root)
    G = 9    
      
    print(f'O valor de P (fixo) {P}')
    print(f'O valor de G (fixo) {G}')
     
    a = int(input('segredo da Alice: '))      
    x = int(pow(G,a,P)) 
    print(f'Alice envia a chave pública {x} para Bob')
     
    b = int(input('segredo do Bob: '))   
    y = int(pow(G,b,P)) 
    print(f'Bob envia a chave pública {y} para Alice')  

    # Chave secreta calculada pela Alice
    ka = int( y ** a % P)   
    
    # Chave secreta calculada pela Bob
    kb = int(pow(x,b,P))
     
    print(f'Chave secreta da Alice : {ka}')
    print(f'Chave secreta do Bob : {kb}')