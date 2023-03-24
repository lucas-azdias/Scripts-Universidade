from flask import Flask, render_template # Importando classe responsável por nova aplicação
from controllers.funcionarios_controllers import funcionarios
from controllers.pedidos_controlller import pedidos


# Configurando nova aplicação
app = Flask(__name__, static_folder="static/", template_folder="views/") # Pode passar qualquer nome (default é o nome da execução)

app.register_blueprint(funcionarios, url_prefix="/funcionarios")
app.register_blueprint(pedidos, url_prefix="/pedidos")


hrefs = ["/clientes", "/pedidos/", "/pedidos/register_pedido", "/funcionarios/", "/funcionarios/register_funcionario"]
descriptions = ["Listar clientes", "Lista de pedidos", "Registrar pedido", "Listar funcionários", "Registrar funcionário"]


@app.route('/')
# Função para a página index principal
def index():
    return render_template("index.html", hrefs=hrefs, descriptions=descriptions) # Entrega o arquivo index.html da pasta templates


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


# Inicialização de execução principal
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True) # Executa o servidor (em localhost:5000 por default)
