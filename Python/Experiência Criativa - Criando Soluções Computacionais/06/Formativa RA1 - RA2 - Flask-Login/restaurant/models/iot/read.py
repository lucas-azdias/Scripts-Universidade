from models import db, User, Sensor
from datetime import datetime


class Read(db.Model):
    __tablename__ = "reads"
    id_read = db.Column(db.Integer(), primary_key=True)
    id_user = db.Column(db.Integer(), db.ForeignKey(User.id_user))
    id_sensor = db.Column(db.Integer(), db.ForeignKey(Sensor.id_sensor))
    value_read = db.Column(db.Float(), nullable=False, default=0)
    date_time_read = db.Column(db.DateTime(), nullable=False, default=datetime.now())
