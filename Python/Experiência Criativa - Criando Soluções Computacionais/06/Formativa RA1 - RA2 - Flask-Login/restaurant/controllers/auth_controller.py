from flask import Blueprint, render_template, redirect, url_for, request, flash
from flask_login import login_user, logout_user, login_required, current_user
from models import User

auth = Blueprint("auth", __name__, template_folder="./views/", static_folder='./static/', root_path="./")


user_email = "antonio@gmail.com"
user_password = "1234"


@auth.route("/")
def auth_index():
    return render_template("auth/auth_index.html")


@auth.route("/login")
def auth_login():
    if not current_user.is_authenticated:
        return render_template("auth/auth_login.html")
    else:
        return redirect(url_for("auth.auth_index"))


@auth.route("/sign_in")
def auth_sign_in():
    if not current_user.is_authenticated:
        return render_template("auth/auth_sign_in.html")
    else:
        return redirect(url_for("auth.auth_index"))


@auth.route("/logout")
@login_required
def auth_logout():
    logout_user()
    flash("Deslogado com sucesso.")
    return redirect(url_for("auth.auth_login"))


@auth.route("/auth", methods=["POST"])
def auth_auth():
    username = request.form.get("username")
    password = request.form.get("password")

    user = User.query.filter_by(username=username).first()

    if not user or user.password != password:
        flash("Credenciais incorretas.")
        return redirect(url_for("auth.auth_sign_in"))
    else:
        login_user(user)
        flash("Logado com sucesso.")
        return redirect(url_for("auth.auth_index"))


@auth.route("/register", methods=["POST"])
def auth_register():
    username = request.form.get("username")
    email = request.form.get("email")
    password = request.form.get("password")
    
    info = [username, email, password]
    if None in info or "" in info:
        flash("Erro no registro.")
        return redirect(request.referrer)
    
    usernames = [user.username for user in User.query.all()]
    if not username in usernames:
        user = User.insert_user(username, email, password)
        if not current_user.is_authenticated:
            login_user(user)
        flash("Registrado com sucesso.")
    return redirect(request.referrer)
