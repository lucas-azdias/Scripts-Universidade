from flask import Blueprint, render_template, redirect, url_for, request, flash

auth = Blueprint("auth", __name__, template_folder="./views/", static_folder='./static/', root_path="./")


user_email = "antonio@gmail.com"
user_password = "1234"


@auth.route("/")
def auth_index():
    return render_template("auth/auth_index.html")


@auth.route("/sign_in")
def auth_sign_in():
    return render_template("auth/auth_sign_in.html")


@auth.route("/auth", methods=["POST"])
def auth_auth():
    email = request.form.get("email")
    password = request.form.get("password")

    if email != user_email or password != user_password:
        flash("Credenciais incorretas.")
        return redirect(url_for("auth.auth_sign_in"))
    else:
        flash("Logado com sucesso.")
        return redirect(url_for("auth.auth_index"))
