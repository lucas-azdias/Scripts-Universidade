from models import db, Minicontroller
from datetime import datetime


class Alert(db.Model):
    __tablename__ = "alerts"
    id_alert = db.Column(db.Integer(), primary_key=True)
    id_user = db.Column(db.Integer(), db.ForeignKey(Minicontroller.id_minicontroller))
    message_alert = db.Column(db.String(50))
    date_time_alert = db.Column(db.DateTime(), nullable=False, default=datetime.now())
