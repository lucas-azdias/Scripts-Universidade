from models import db, Device


class Minicontroller(db.Model):
    __tablename__ = "minicontrollers"
    id_minicontroller = db.Column(db.Integer(), db.ForeignKey(Device.id_device), primary_key=True)
    ports_minicontroller = db.Column(db.String(50))
