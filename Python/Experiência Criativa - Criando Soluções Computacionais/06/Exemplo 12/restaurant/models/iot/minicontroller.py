from models import db, Device


class Minicontroller(db.Model):
    __tablename__ = "minicontrollers"
    id_minicontroller = db.Column(db.Integer(), db.ForeignKey(Device.id_device), primary_key=True)
    ports = db.Column(db.String(50))

    alerts = db.relationship("Alert", backref="minicontrollers", lazy=True)

    def save_minicontroller(name, model, brand, voltage, is_active, description, ports):
        # É MELHOR USA APENAS UM COMMIT E ADD
        device = Device(name=name, model=model, brand=brand, voltage=voltage, is_active=is_active, description=description)
        minicontroller = Minicontroller(id_minicontroller=device.id_device, ports=ports)
        device.minicontrollers.append(minicontroller)

        db.session.add(device)
        db.session.commit()

    def list_minicontrollers():
        minicontrollers = Minicontroller.query.join(Device, Device.id_device == Minicontroller.id_minicontroller)\
            .add_columns(Minicontroller.id_minicontroller, Device.name, Device.model,
                         Device.brand, Device.voltage, Device.is_active,
                         Device.description, Minicontroller.ports).all()
        return minicontrollers
