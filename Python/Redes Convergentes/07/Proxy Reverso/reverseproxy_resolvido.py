import socket
from threading import Thread


class myTCPProxy:

    def __init__(self, host='', porta=8080, escalonador='RR'):
        '''
        Construtor do aplicativo proxy

        Parametros:
        host: str (endereço IP da interface que será feito bind)
        porta: int (porta que será feito bind)
        escalonador: str (string que identifica o tipo de escalonado utilizado)
        '''
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.servidores = {}   # dicionário que mapeia o id e o endereço dos servidores
        self.conexoes = {} # dicionario que mapeia o id do servidor e o número de conexoes ativas
        self.sid_escolhido = None   # id do último servidor escolhido

        if escalonador == 'RR':
            self.escolheServidor = self.escalonadorRR
        elif escalonador == 'LB':
            self.escolheServidor = self.escalonadorLB           
        else:
            print('ERRO FATAL: Escalonador inválido')
            exit() 

        try:
            self.s.bind((host, porta))
            ip = 'em todas as interfaces' if host =='' else f'e ip {host}'
            print(f'Proxy ativado na porta {porta} {ip}')           
            self.s.listen(5)
        except Exception as e:
            print('Proxy não pode ser iniciado: ', e)
            exit()

    def contaConexoes(self, sid:str, evento:str):
        '''
        Atualiza número de conexões por servidor

        Parametros:
        sid: str (identificado do servidor)
        evento: str (add ou pop)
        '''

        c = self.conexoes.get(sid, 0) 
        
        if evento == 'add':
            self.conexoes[sid] =  c + 1
        elif evento == 'pop':
            if c > 0:
                self.conexoes[sid] =  c - 1
        else:
            print('contaConexoes: evento desconhecido')
        
        print(self.conexoes)

    
    def aguardaClientes(self):
        '''
        Aguarda a conexão de um cliente e faz o redirecionamento para dos servidores cadastrados
        '''
        print('aguardando Clientes')
        while True:
            try:
                c1, _ = self.s.accept()
                c2 = self.escolheServidor()
                self.contaConexoes(self.sid_escolhido, 'add')
                Thread( target=self.fazProxy, args=(c1, c2, self.sid_escolhido) ).start()
                Thread( target=self.fazProxy, args=(c2, c1) ).start()
            except Exception as e:
                print('ERRO em aguardaClientes:', e)

    def adicionaServidor(self, id:str, addr:tuple):
        '''
        Adiciona um servidor a lista de servidores cadastrados

        Parametros:
        id: str (idenfica o servidor)
        addr: tuple (ip e porta)
        '''
        self.servidores[id] = addr
        self.conexoes[id] = 0


    def fazProxy(self, cr:object, cs:object, sid:str = ''):
        '''
        Copia os dados recebidos dar para a conexão cs 
        
        Parametros:
        cr: socket (objeto socket do tipo conexão)
        cs: socket (objeto socket do tipo conexão)
        sid: str (identificado do servidor)
        '''
        while True:
            try:
                data = cr.recv(1024)
                if not data:
                    cs.shutdown(socket.SHUT_RDWR)
                    break
                cs.send(data)
            except:
                cs.shutdown(socket.SHUT_RDWR)
                break

        if sid != '':
            self.contaConexoes(sid, 'pop')
                

    def escalonadorRR(self):
        '''
        Escalonador: Round Robin
        - faz a conexão com o próximo servidor disponível
        '''
        
        sids = list(self.servidores.keys())
        tentativas = len(sids)

        for _ in range(tentativas):
        
            pos = 0 if self.sid_escolhido is None else sids.index(self.sid_escolhido) + 1
            self.sid_escolhido = sids[pos] if pos < len(sids) else sids[0]

            cs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            try:
                cs.connect(self.servidores[self.sid_escolhido])
                return cs
            except:
                print( f'o servidor {self.sid_escolhido} está down ')
                
        raise Exception('Nenhum servidor esta ativo')    
        

    def escalonadorLB(self):
        '''
        Escalonador: Load Balancing
        - faz a conexão com o servidor que tiver menos carga
        '''

        # conexoes = self.conexoes.copy()
        # sid = min( conexoes, key=conexoes.get)
        # em caso de falha, remova o servidor de conexoes e zere o contador em self.conexoes
  
        conexoes = self.conexoes.copy()

        sids = list(self.servidores.keys())
        tentativas = len(sids)

        for _ in range(tentativas):

            self.sid_escolhido = min( conexoes, key=conexoes.get)

            cs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            try:
                cs.connect(self.servidores[self.sid_escolhido])
                return cs
            except:
                print( f'o servidor {self.sid_escolhido} está down ')
                self.conexoes[self.sid_escolhido] = 0
                conexoes.pop(self.sid_escolhido)

                
                
        raise Exception('Nenhum servidor esta ativo')    


if __name__ == '__main__':
    x  = myTCPProxy(host='127.0.0.1', escalonador='LB')
    x.adicionaServidor('S1', ('127.0.0.1', 9999))
    x.adicionaServidor('S2', ('127.0.0.1', 9998))
    x.aguardaClientes()


