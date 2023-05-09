from models import db, Device


class Actuator(db.Model):
    __tablename__ = "actuators"
    id_actuator = db.Column(db.Integer(), db.ForeignKey(Device.id_device), primary_key=True)
    type = db.Column(db.String(50))

    activations = db.relationship("Activation", backref="actuators", lazy=True)

    def save_actuator(name, model, brand, voltage, is_active, description, type):
        # É MELHOR USA APENAS UM COMMIT E ADD
        device = Device(name=name, model=model, brand=brand, voltage=voltage, is_active=is_active, description=description)
        actuator = Actuator(id_actuator=device.id_device, type=type)
        device.actuators.append(actuator)

        db.session.add(device)
        db.session.commit()

    def list_actuators():
        actuators = Actuator.query.join(Device, Device.id_device == Actuator.id_actuator)\
            .add_columns(Actuator.id_actuator, Device.name, Device.model,
                         Device.brand, Device.voltage, Device.is_active,
                         Device.description, Actuator.type).all()
        return actuators
