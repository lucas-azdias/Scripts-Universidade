from flask_sqlalchemy import SQLAlchemy


db = SQLAlchemy()
instance = "sqlite:///restaurant"
#instance = "mysql+pymysql://[user]:[password]@localhost:3306/[db_name]"
