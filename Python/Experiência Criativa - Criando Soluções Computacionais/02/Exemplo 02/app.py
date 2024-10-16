from flask import Flask, render_template # Importando classe responsável por nova aplicação

# Configurando nova aplicação
app = Flask(__name__) # Pode passar qualquer nome (default é o nome da execução)

@app.route('/')
# Função para a página index principal
def index():
    return render_template("index.html") # Entrega o arquivo index.html da pasta templates


@app.route('/pedidos')
# Função para a página pedidos
def pedidos():
    return render_template("pedidos.html") # Entrega o arquivo pedidos.html da pasta templates


@app.route('/clientes')
# Função para a página clientes
def clientes():
    return render_template("clientes.html") # Entrega o arquivo clientes.html da pasta templates


@app.route('/funcionarios')
# Função para a página funcionarios
def funcionarios():
    # Entrega o arquivo funcionarios.html da pasta templates
    return render_template("funcionarios.html")


# Inicialização de execução principal
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True) # Executa o servidor (em localhost:5000 por default)
