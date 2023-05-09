from models import db, login_manager
from flask_login import UserMixin


class User(db.Model, UserMixin):
    __tablename__ = "users"
    id_user = db.Column(db.Integer(), primary_key=True)
    username = db.Column(db.String(30), nullable=False, unique=True)
    email = db.Column(db.String(50), nullable=False, unique=True)
    password = db.Column(db.String(512), nullable=False)

    roles = db.relationship("Role", back_populates="users", secondary="users_roles", lazy=True) # Usa back_populates e secondary quando há intermediário
    reads = db.relationship("Read", backref="users", lazy=True)
    activations = db.relationship("Activation", backref="users", lazy=True)

    def get_id(self):
        return str(self.id_user)

    # User-loader do Flask-Login
    @login_manager.user_loader
    def get_user(id_user):
        return User.query.filter_by(id_user=id_user).first()

    def insert_user(username, email, password):
        user = User(username=username, email=email, password=password)
        db.session.add(user)
        db.session.commit()
        return user
