# já instalado? 
import sqlite3
import os

livros = """CREATE TABLE IF NOT EXISTS "livros"
(
    id              INTEGER,
    autor          TEXT,
    titulo         TEXT,
    PRIMARY KEY (id)
); """

usuarios = """CREATE TABLE IF NOT EXISTS "usuarios"
(
    id              INTEGER,
    usuario          TEXT,
    senha         TEXT,
    PRIMARY KEY (id)
); """


def cria_banco(arquivo):
    try:
        conn = sqlite3.connect(arquivo)
        print(sqlite3.version)
        return conn
    except Exception as e:
        print(e)
        return None

def executa_SQL(conn, command):
    cur = conn.cursor()
    try:
        res = cur.execute(command)
        conn.commit()
        return res
    except:
        print("Comando SLQ inválido")
        return None

def cria_tabelas():
    conn = cria_banco('teste.db')
    executa_SQL(conn, "DROP  TABLE IF EXISTS usuarios")
    executa_SQL(conn, "DROP  TABLE IF EXISTS livros")
    executa_SQL(conn, livros)
    executa_SQL(conn, usuarios)
    executa_SQL(conn, "INSERT INTO usuarios (usuario, senha) VALUES('joao','1234')")
    executa_SQL(conn, "INSERT INTO usuarios (usuario, senha) VALUES('maria','5678')")
    executa_SQL(conn, "INSERT INTO livros (autor, titulo) VALUES('Hommer','security for dummies')")
    executa_SQL(conn, "INSERT INTO livros (autor, titulo) VALUES('Lisa','security for smart people')")
    return conn


#-------------------------------------------------------------------------------------------

conn = cria_tabelas()
exercicio = int(input('Digite o número do exercicio: '))

# EXERCICIO OBTENHA A LISTA COMPLETA DE LIVROS DA BASE
# -- multiplos comandos separados por ; não funcionam com sqlite (cur.execute())
# -- ao invés disso crie uma condição que é sempre verdade ' or 1=1--'

if exercicio == 1:
    while True:
        autor = input('Digite o nome do autor: ')
        sql = f"SELECT * FROM livros where autor = '{autor}'"
        print(sql)
        res = executa_SQL(conn, sql) 
        if res is not None:
            for r in res:
                print(r)


# EXERCICIO FAÇA O LOGIN SEM CONHECER A SENHA
# -- apenas adicone a condição que é sempre verdade ao digitar a senha ' or 1=1--'
else:
    while True:
        login = input('Digite seu login: ')
        senha = input('Digite sua senha: ')
        sql = f"Select * FROM usuarios where usuario='{login}' and senha='{senha}'"
        print(sql)
        res = executa_SQL(conn, sql)
        if res is None:
            print('usuario inválido')
        else:
            print(f'Bem vindo {login}')
