from models import db


class User(db.Model):
    __tablename__ = "users"
    id_user = db.Column(db.Integer(), primary_key=True)
    username_user = db.Column(db.String(30), nullable=False, unique=True)
    email_user = db.Column(db.String(50), nullable=False, unique=True)
    password_user = db.Column(db.String(30), nullable=False)

    roles = db.relationship("Role", back_populates="users", secondary="users_roles", lazy=True) # Usa back_populates e secondary quando há intermediário
