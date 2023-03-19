from flask import Flask, render_template # Importando classe responsável por nova aplicação

# Configurando nova aplicação
app = Flask(__name__) # Pode passar qualquer nome (default é o nome da execução)

@app.route('/')
# Função para a página index.html principal
def index():
    return render_template("index.html")


@app.route('/pedidos')
# Função para a página pedidos.html
def pedidos():
    return render_template("pedidos.html")


# Inicialização de execução principal
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)  # Executa o servidor (em localhost:5000 por default)
