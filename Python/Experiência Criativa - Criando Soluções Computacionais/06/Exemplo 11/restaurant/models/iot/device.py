from models import db


# Criando tabela de Device extendendo db.Model (dá acesso aos recursos do SQLAlchemy)
class Device(db.Model):
    __tablename__ = "devices" # Nome padrão nas tabelas
    id_device = db.Column(db.Integer(), primary_key=True) # Não precisa especificar que é auto_increment ou not null (por já ser chave primária)
    name_device = db.Column(db.String(50), nullable=False)
    brand_device = db.Column(db.String(30))
    model_device = db.Column(db.String(30))
    voltage_device = db.Column(db.Float(), nullable=False)
    description_device = db.Column(db.String(512), nullable=False)
    is_active_device = db.Column(db.Boolean(), nullable=False, default=False)

    # Caso seja um sensor, dá para recuperar a tabela Sensor específica por essa variável
    sensor_device = db.relationship("Sensor", backref="devices", lazy=True) # Lazy -> faz as consultas serem mais rápidas (não é obrigatório)

    # Caso seja um atuador, dá para recuperar a tabela Actuator específica por essa variável
    actuator_device = db.relationship("Actuator", backref="devices", lazy=True)

    # Caso seja um minicontrolador, dá para recuperar a tabela Minicontroller específica por essa variável
    minicontroller_device = db.relationship("Minicontroller", backref="devices", lazy=True)
