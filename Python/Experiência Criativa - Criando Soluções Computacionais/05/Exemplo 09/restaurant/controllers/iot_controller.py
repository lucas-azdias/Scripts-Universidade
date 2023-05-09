from flask import Blueprint, render_template,redirect,url_for, request

iot = Blueprint("iot", __name__, template_folder = './views/', static_folder='./static/', root_path="./")


@iot.route("/")
def iot_index():
    return render_template("/iot/iot_index.html")


@iot.route("/register_sensor")
def iot_register_sensor():
    return render_template("/iot/register_sensor.html")


@iot.route("/save_sensor", methods=["POST"])
def iot_save_sensor():
    name = request.form.get("name")
    return redirect(url_for("iot.iot_index"))


@iot.route("/register_atuador")
def iot_register_atuador():
    return render_template("/iot/register_atuador.html")


@iot.route("/save_atuador", methods=["POST"])
def iot_save_atuador():
    name = request.form.get("name")
    return redirect(url_for("iot.iot_index"))


@iot.route("/register_minicontrolador")
def iot_register_minicontrolador():
    return render_template("/iot/register_minicontrolador.html")


@iot.route("/save_minicontrolador", methods=["POST"])
def iot_save_minicontrolador():
    name = request.form.get("name")
    return redirect(url_for("iot.iot_index"))
