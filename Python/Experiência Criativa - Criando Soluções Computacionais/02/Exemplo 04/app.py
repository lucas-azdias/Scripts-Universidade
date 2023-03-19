from flask import Flask, render_template # Importando classe responsável por nova aplicação

# Configurando nova aplicação
app = Flask(__name__) # Pode passar qualquer nome (default é o nome da execução)

@app.route('/')
# Função para a página index principal
def index():
    hrefs = ["/pedidos", "/clientes", "/funcionarios"]
    descriptions = ["Lista de pedidos", "Listar clientes", "Listar funcionários"]
    return render_template("index.html", hrefs=hrefs, descriptions=descriptions) # Entrega o arquivo index.html da pasta templates


@app.route('/pedidos')
# Função para a página pedidos
def pedidos():
    hrefs = ["/pedidos", "/clientes", "/funcionarios"]
    descriptions = ["Lista de pedidos", "Listar clientes", "Listar funcionários"]
    orders = ["Combo 1, comanda 5", # Não pode possuir o mesmo nome do método (gera exceção)
               "Combo 3, comanda 9",
               "Cerveja, comanda 4",
               "Batatas-fritas, comanda 6",
               "X-Burguer, comanda 1"
    ]
    return render_template("pedidos.html", hrefs=hrefs, descriptions=descriptions, orders=orders) # Entrega o arquivo pedidos.html da pasta templates


@app.route('/clientes')
# Função para a página clientes
def clientes():
    hrefs = ["/pedidos", "/clientes", "/funcionarios"]
    descriptions = ["Lista de pedidos", "Listar clientes", "Listar funcionários"]
    clnts = [
        "James Bond",
        "Cláudio Rodrigues",
        "Jobson Yelsen",
        "Michael Stalin",
        "Godfried Marks"
    ]
    return render_template("clientes.html", hrefs=hrefs, descriptions=descriptions, clnts=clnts) # Entrega o arquivo clientes.html da pasta templates


@app.route('/funcionarios')
# Função para a página funcionarios
def funcionarios():
    hrefs = ["/pedidos", "/clientes", "/funcionarios"]
    descriptions = ["Lista de pedidos", "Listar clientes", "Listar funcionários"]
    empls = ["Roberta Serra",
             "Rodrigo Campos",
             "Rogério Tempra",
             "Robson Mustang"
    ]
    return render_template("funcionarios.html", hrefs=hrefs, descriptions=descriptions, empls=empls) # Entrega o arquivo funcionarios.html da pasta templates


# Inicialização de execução principal
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True) # Executa o servidor (em localhost:5000 por default)
