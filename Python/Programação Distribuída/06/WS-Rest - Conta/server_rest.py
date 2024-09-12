#!/usr/bin/python3

# ACESSO GET: curl http://localhost:1879/eco
# ACESSO PATCH: url http://localhost:1879/eco/<MSG> -X PATCH

from flask import Flask, request
from flask_restful import Resource, Api


class Contas:

    def __init__(self):
        self.contas = {}
    
    def saldo(self, conta):
        return self.contas[conta] if conta in self.contas.keys() else None
    
    def deposito(self, conta, valor):
        if conta in self.contas.keys():
            self.contas[conta] += valor
            return False
        else:
            self.contas[conta] = valor
            return True

    def saque(self, conta, valor):
        if self.contas[conta] >= valor:
            self.contas[conta] -= valor
            return True
        else:
            return False


class ContasApi(Resource):

    def get(self):
        conta = request.headers["conta"]
        return {"saldo": contas.saldo(conta)}
    
    def patch(self, valor):
        conta = request.headers["conta"]

        if str(request.url_rule).strip() == "/contas/deposito/<float:valor>":
            return {"created": contas.deposito(conta, valor)}
        
        if str(request.url_rule).strip() == "/contas/saque/<float:valor>":
            return {"done": contas.saque(conta, valor)}
        
        return {"done": False}


if __name__ == "__main__":
    app = Flask(__name__)
    api = Api(app)

    contas = Contas()
    api.add_resource(ContasApi, "/contas", "/contas/deposito/<float:valor>", "/contas/saque/<float:valor>")
    app.run(port=1879, debug=True)
