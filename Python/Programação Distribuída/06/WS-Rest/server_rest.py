#!/usr/bin/python3

# ACESSO GET: curl http://localhost:1879/eco
# ACESSO PATCH: url http://localhost:1879/eco/<MSG> -X PATCH

from flask import Flask
from flask_restful import Resource, Api


class Eco:

    def __init__(self, sufixo):
        self.sufixo = sufixo
        self.count = 0
    
    def diga(self, msg):
        self.count += 1
        return msg + self.sufixo


class EcoApi(Resource):

    def get(self):
        return {"count": eco.count}
    
    def patch(self, msg):
        return {"resp": eco.diga(msg)}


if __name__ == "__main__":
    app = Flask(__name__)
    api = Api(app)

    eco = Eco("_ECO")
    api.add_resource(EcoApi, "/eco", "/eco/<string:msg>")
    app.run(port=1879, debug=True)
