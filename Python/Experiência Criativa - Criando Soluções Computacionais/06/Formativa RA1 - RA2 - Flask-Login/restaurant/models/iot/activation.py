from models import db, User, Actuator
from datetime import datetime


class Activation(db.Model):
    __tablename__ = "activations"
    id_activation = db.Column(db.Integer(), primary_key=True)
    id_user = db.Column(db.Integer(), db.ForeignKey(User.id_user))
    id_actuator = db.Column(db.Integer(), db.ForeignKey(Actuator.id_actuator))
    date_time_activation = db.Column(db.DateTime(), nullable=False, default=datetime.now())
