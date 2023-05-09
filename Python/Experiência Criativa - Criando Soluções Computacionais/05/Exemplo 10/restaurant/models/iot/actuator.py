from models import db, Device


class Actuator(db.Model):
    __tablename__ = "actuators"
    id_actuator = db.Column(db.Integer(), db.ForeignKey(Device.id_device), primary_key=True)
    type_actuator = db.Column(db.String(50))
