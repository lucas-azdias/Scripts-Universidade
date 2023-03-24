from flask import Blueprint, render_template, redirect, url_for, request


funcionarios = Blueprint(name="funcionarios", import_name=__name__, static_folder="./static/", template_folder="./views/")


hrefs = ["/clientes", "/pedidos", "/register_pedido", "/funcionarios/", "/funcionarios/register_funcionario"]
descriptions = ["Listar clientes", "Lista de pedidos", "Registrar pedido", "Listar funcionários", "Registrar funcionário"]

empls = list()


@funcionarios.route("/")
# Função para a página funcionarios
def funcionarios_index():
    return render_template("funcionarios/funcionarios.html", hrefs=hrefs, descriptions=descriptions, empls=empls) # Entrega o arquivo funcionarios.html da pasta templates


@funcionarios.route('/register_funcionario')
# Função para a página register_funcionario
def funcionarios_register_funcionario():
    return render_template("funcionarios/register_funcionario.html", hrefs=hrefs, descriptions=descriptions)


@funcionarios.route('/save_funcionario', methods=['POST'])
# Função para o tratamento save_funcionario
def funcionarios_save_funcionario():
    nome_funcionario = request.form.get("nome_funcionario")
    tipo_funcionario = request.form.get("tipo_funcionario")

    empls.append(nome_funcionario + ", " + tipo_funcionario)

    return redirect(url_for('funcionarios.funcionarios_index'))
