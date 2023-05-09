from models import db, Device


# Criando tabela de Sensor com herança de Device
class Sensor(db.Model):
    __tablename__ = "sensors"
    id_sensor = db.Column(db.Integer(), db.ForeignKey(Device.id_device), primary_key=True) # Precisa dizer que é chave estrangeira primeiro que primária
    measure = db.Column(db.String(15))

    reads = db.relationship("Read", backref="sensors", lazy=True)

    def save_sensor(name, model, brand, voltage, is_active, description, measure):
        device = Device(name=name, model=model, brand=brand, voltage=voltage, is_active=is_active, description=description)
        db.session.add(device)
        db.session.commit()

        sensor = Sensor(id_sensor=device.id_device, measure=measure)
        db.session.add(sensor)
        db.session.commit()

    def save_sensor_alt(name, model, brand, voltage, is_active, description, measure):
        # É MELHOR USA APENAS UM COMMIT E ADD
        device = Device(name=name, model=model, brand=brand, voltage=voltage, is_active=is_active, description=description)
        sensor = Sensor(id_sensor=device.id_device, measure=measure)
        device.sensors.append(sensor)

        db.session.add(device)
        db.session.commit()

    def list_sensors():
        sensors = Sensor.query.join(Device, Device.id_device == Sensor.id_sensor)\
            .add_columns(Sensor.id_sensor, Device.name, Device.model,
                         Device.brand, Device.voltage, Device.is_active,
                         Device.description, Sensor.measure).all()
        return sensors
