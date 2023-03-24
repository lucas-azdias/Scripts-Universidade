from flask import Blueprint, render_template, redirect, url_for, request


pedidos = Blueprint(name="pedidos", import_name=__name__, static_folder="./static/", template_folder="./views/")


hrefs = ["/clientes", "/pedidos", "/register_pedido", "/funcionarios/", "/funcionarios/register_funcionario"]
descriptions = ["Listar clientes", "Lista de pedidos", "Registrar pedido", "Listar funcionários", "Registrar funcionário"]

orders = list()


@pedidos.route('/')
# Função para a página pedidos
def pedidos_index():
    return render_template("/pedidos/pedidos.html", hrefs=hrefs, descriptions=descriptions, orders=orders) # Entrega o arquivo pedidos.html da pasta templates


@pedidos.route('/register_pedido')
# Função para a página register_pedido
def pedidos_register_pedido():
    return render_template("/pedidos/register_pedido.html", hrefs=hrefs, descriptions=descriptions)


@pedidos.route('/save_pedido', methods=['POST'])
# Função para o tratamento save_pedido
def pedidos_save_pedido():
    nome_produto = request.form.get("nome_produto")
    id_comanda = request.form.get("id_comanda")

    orders.append(nome_produto + ', comanda ' + id_comanda)

    return redirect(url_for('pedidos.pedidos_index'))
