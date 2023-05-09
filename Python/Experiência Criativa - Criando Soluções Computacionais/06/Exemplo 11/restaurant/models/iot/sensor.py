from models import db, Device


# Criando tabela de Sensor com herança de Device
class Sensor(db.Model):
    __tablename__ = "sensors"
    id_sensor = db.Column(db.Integer(), db.ForeignKey(Device.id_device), primary_key=True) # Precisa dizer que é chave estrangeira primeiro que primária
    measure_sensor = db.Column(db.String(15))

    reads = db.relationship("Read", backref="sensors", lazy=True)
