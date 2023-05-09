from models import db


class Role(db.Model):
    __tablename__ = "roles"
    id_role = db.Column(db.Integer(), primary_key=True)
    name_role = db.Column(db.String(50), nullable=False)
    description_role = db.Column(db.String(512), nullable=False)

    users = db.relationship("User", back_populates="roles", secondary="users_roles", lazy=True) # Usa back_populates quando há intermediário
