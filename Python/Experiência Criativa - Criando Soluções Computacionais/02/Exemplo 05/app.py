from flask import Flask, request, render_template, redirect, url_for # Importando classe responsável por nova aplicação

# Configurando nova aplicação
app = Flask(__name__) # Pode passar qualquer nome (default é o nome da execução)


hrefs = ["/pedidos", "/register_pedido", "/clientes", "/funcionarios"]
descriptions = ["Lista de pedidos", "Registrar pedidos", "Listar clientes", "Listar funcionários"]

orders = ["Combo 1, comanda 5",
          "Combo 3, comanda 9",
          "Cerveja, comanda 4",
          "Batatas-fritas, comanda 6",
          "X-Burguer, comanda 1"
]

@app.route('/')
# Função para a página index principal
def index():
    return render_template("index.html", hrefs=hrefs, descriptions=descriptions) # Entrega o arquivo index.html da pasta templates


@app.route('/pedidos')
# Função para a página pedidos
def pedidos():
    return render_template("pedidos.html", hrefs=hrefs, descriptions=descriptions, orders=orders) # Entrega o arquivo pedidos.html da pasta templates


@app.route('/clientes')
# Função para a página clientes
def clientes():
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
    empls = ["Roberta Serra",
             "Rodrigo Campos",
             "Rogério Tempra",
             "Robson Mustang"
    ]
    return render_template("funcionarios.html", hrefs=hrefs, descriptions=descriptions, empls=empls) # Entrega o arquivo funcionarios.html da pasta templates


@app.route('/register_pedido')
# Função para a página register_pedido
def register_pedido():
    return render_template("register_pedido.html", hrefs=hrefs, descriptions=descriptions)


@app.route('/save_pedido', methods=['POST'])
# Função para o tratamento save_pedido
def save_pedido():
    nome_produto = request.form.get("nome_produto")
    id_comanda = request.form.get("id_comanda")

    orders.append(nome_produto + ', comanda ' + id_comanda)

    return redirect(url_for('pedidos'))


# Inicialização de execução principal
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True) # Executa o servidor (em localhost:5000 por default)
