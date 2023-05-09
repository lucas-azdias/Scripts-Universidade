from flask import Flask # Importando classe responsável por nova aplicação

# Configurando nova aplicação
app = Flask(__name__) # Pode passar qualquer nome (default é o nome da execução)

@app.route('/')
# Função para a página index.html principal
def index():
    return """
<html>

    <head>

    </head>

    <body>
        <h2>Meu Restaurante</h2>
        <h3>Acesse o menu:</h3>
        <ul>
            <h4>
                <li><a href="/pedidos">Lista de pedidos</a></li>
            </h4>
        </ul>
    </body>

</html>
"""


@app.route('/pedidos')
# Função para a página pedidos.html
def pedidos():
    return """
<html>

    <head>

    </head>

    <body>
        <h4>Pedidos aqui!</h4>

        <h4><a href="/">Voltar para o início</a></h4>
    </body>

</html>
"""


# Inicialização de execução principal
if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)  # Executa o servidor (em localhost:5000 por default)
