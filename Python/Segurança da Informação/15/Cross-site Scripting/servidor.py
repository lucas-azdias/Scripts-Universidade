from flask import Flask, render_template, request
import db

app = Flask(__name__)


@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        db.add_comment(request.form['comment'])

    search_query = request.args.get('q')

    comments = db.get_comments(search_query)

    return render_template('index.html',
                           comments=comments,
                           search_query=search_query)


#------------------------------------------------------------------------------------
# PROTECAO {% autoescape true %} no início do código HTML faz com que o código em variáveis seja convertido em caracteres especiais
# conforme o link: https://flask.palletsprojects.com/en/2.3.x/templating/
# Tente os seguintes comandos no FORM HTML:
# <script>alert('BOM dia, seu código é INSEGURO!!!')</script>
# <script> window.open('http://netiswork.pro.br:40231') </script> -- desabilite o bloqueio de popup



if __name__ == '__main__':
   app.run(host='127.0.0.1',port=8000,debug=False)