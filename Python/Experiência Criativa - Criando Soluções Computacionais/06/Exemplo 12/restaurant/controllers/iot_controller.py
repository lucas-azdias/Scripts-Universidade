from flask import Blueprint, render_template,redirect,url_for, request
from models import Sensor, Actuator, Minicontroller

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
    model = request.form.get("model")
    brand = request.form.get("brand")
    voltage = request.form.get("voltage")
    measure = request.form.get("measure")
    is_active = True if request.form.get("is_active") == "on" else False
    description = request.form.get("description")

    Sensor.save_sensor(name, model, brand, voltage, is_active, description, measure)

    return redirect(url_for("iot.iot_index"))


@iot.route("/list_sensors")
def iot_list_sensors():
    sensors = Sensor.list_sensors()
    return render_template("/iot/list_sensors.html", sensors=sensors)


@iot.route("/register_atuador")
def iot_register_atuador():
    return render_template("/iot/register_atuador.html")


@iot.route("/save_atuador", methods=["POST"])
def iot_save_atuador():
    name = request.form.get("name")
    model = request.form.get("model")
    brand = request.form.get("brand")
    voltage = request.form.get("voltage")
    type = request.form.get("type")
    is_active = True if request.form.get("is_active") == "on" else False
    description = request.form.get("description")

    Actuator.save_actuator(name, model, brand, voltage, is_active, description, type)
    return redirect(url_for("iot.iot_index"))


@iot.route("/list_atuadores")
def iot_list_atuadores():
    atuadores = Actuator.list_actuators()
    return render_template("/iot/list_atuadores.html", atuadores=atuadores)


@iot.route("/register_minicontrolador")
def iot_register_minicontrolador():
    return render_template("/iot/register_minicontrolador.html")


@iot.route("/save_minicontrolador", methods=["POST"])
def iot_save_minicontrolador():
    name = request.form.get("name")
    model = request.form.get("model")
    brand = request.form.get("brand")
    voltage = request.form.get("voltage")
    ports = request.form.get("ports")
    is_active = True if request.form.get("is_active") == "on" else False
    description = request.form.get("description")

    Minicontroller.save_minicontroller(name, model, brand, voltage, is_active, description, ports)
    return redirect(url_for("iot.iot_index"))


@iot.route("/list_minicontroladores")
def iot_list_minicontroladores():
    minicontroladores = Minicontroller.list_minicontrollers()
    return render_template("/iot/list_minicontroladores.html", minicontroladores=minicontroladores)
