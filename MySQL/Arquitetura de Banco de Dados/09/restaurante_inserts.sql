CREATE DATABASE IF NOT EXISTS restaurante;
USE restaurante;

SET sql_mode = 'ONLY_FULL_GROUP_BY';

DROP TABLE IF EXISTS restaurante.registro;
DROP TABLE IF EXISTS restaurante.produto;
DROP TABLE IF EXISTS restaurante.comanda;
DROP TABLE IF EXISTS restaurante.pagamento_forma;
DROP TABLE IF EXISTS restaurante.pagamento;
DROP TABLE IF EXISTS restaurante.forma_pagamento;
DROP TABLE IF EXISTS restaurante.registro_horas;
DROP TABLE IF EXISTS restaurante.pagamento_funcionario;
DROP TABLE IF EXISTS restaurante.servicos_gerais;
DROP TABLE IF EXISTS restaurante.garcom;
DROP TABLE IF EXISTS restaurante.funcionario;
DROP TABLE IF EXISTS restaurante.cliente;
DROP TABLE IF EXISTS restaurante.pessoa;

CREATE TABLE IF NOT EXISTS restaurante.pessoa(
	id INTEGER AUTO_INCREMENT NOT NULL,    
	nome VARCHAR(50) NOT NULL,
    cpf CHAR(11) UNIQUE NOT NULL,
    sexo CHAR(1) NOT NULL,
    data_nasc DATE NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS restaurante.cliente(
	id INTEGER NOT NULL PRIMARY KEY,    
	data_criacao DATETIME NOT NULL,
    FOREIGN KEY (id) REFERENCES pessoa(id)
);

CREATE TABLE IF NOT EXISTS restaurante.funcionario(
	id INTEGER NOT NULL PRIMARY KEY,
    email VARCHAR(40) NOT NULL,
    telefone VARCHAR(20) NOT NULL,
	data_criacao DATETIME NOT NULL,
    FOREIGN KEY (id) REFERENCES pessoa(id)
);

CREATE TABLE IF NOT EXISTS restaurante.garcom(
	id INTEGER NOT NULL PRIMARY KEY,    
	valor_hora DOUBLE NOT NULL,
    FOREIGN KEY (id) REFERENCES funcionario(id)
);

CREATE TABLE IF NOT EXISTS restaurante.servicos_gerais(
	id INTEGER NOT NULL PRIMARY KEY,    
	salario DOUBLE NOT NULL,
    FOREIGN KEY (id) REFERENCES funcionario(id)
);

CREATE TABLE IF NOT EXISTS restaurante.pagamento_funcionario(
	id INTEGER AUTO_INCREMENT NOT NULL,
    valor double NOT NULL,
    data_hora DATETIME NOT NULL,
    id_funcionario INTEGER NOT NULL,
    PRIMARY KEY(id),
    FOREIGN KEY (id_funcionario) REFERENCES funcionario(id)
);

CREATE TABLE IF NOT EXISTS restaurante.registro_horas(
    numero_horas double NOT NULL,
    data_registro DATETIME NOT NULL,
    id_garcom INTEGER NOT NULL,
    id_pagamento_horas INTEGER,
    FOREIGN KEY (id_garcom) REFERENCES garcom(id),
    FOREIGN KEY (id_pagamento_horas) REFERENCES pagamento_funcionario(id)
);

CREATE TABLE IF NOT EXISTS restaurante.forma_pagamento(
	id INTEGER NOT NULL PRIMARY KEY, 
    nome VARCHAR(30) NOT NULL
);

CREATE TABLE IF NOT EXISTS restaurante.pagamento(
	id INTEGER AUTO_INCREMENT NOT NULL,
    valor double NOT NULL,
    data_hora DATETIME NOT NULL,
    id_cliente INTEGER NOT NULL,
    PRIMARY KEY(id),
    FOREIGN KEY (id_cliente) REFERENCES cliente(id)
);

CREATE TABLE IF NOT EXISTS restaurante.pagamento_forma(
	id_forma_pagamento INTEGER NOT NULL,
    id_pagamento INTEGER NOT NULL,
    valor double NOT NULL,
    parcelas SMALLINT(2),
    PRIMARY KEY(id_pagamento, id_forma_pagamento),
    FOREIGN KEY (id_forma_pagamento) REFERENCES forma_pagamento(id),
    FOREIGN KEY (id_pagamento) REFERENCES pagamento(id)
);

CREATE TABLE IF NOT EXISTS restaurante.comanda(
	id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY,   
	data_criacao DATETIME NOT NULL,
    valor_total DOUBLE,
    num_items INT,
	id_cliente INTEGER NOT NULL,
    id_pagamento INTEGER,
	FOREIGN KEY  (id_cliente) REFERENCES cliente(id),
    FOREIGN KEY  (id_pagamento) REFERENCES pagamento(id)
);

CREATE TABLE IF NOT EXISTS restaurante.produto(
	id INTEGER AUTO_INCREMENT NOT NULL,
    nome VARCHAR(50) NOT NULL,
    valor DOUBLE NOT NULL,
    quantidade integer NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS restaurante.registro(
	data_hora DATETIME NOT NULL,
    valor_produto DOUBLE NOT NULL DEFAULT 0.0,
    quantidade integer NOT NULL,
    id_comanda INTEGER NOT NULL,
    id_garcom INTEGER NOT NULL,
    id_produto INT NOT NULL,
    id_comissao INTEGER,
    PRIMARY KEY(id_comanda, id_garcom, id_produto),
    FOREIGN KEY (id_produto) REFERENCES produto(id),
    FOREIGN KEY (id_comanda) REFERENCES comanda(id),
    FOREIGN KEY (id_garcom) REFERENCES garcom(id),
    FOREIGN KEY  (id_comissao) REFERENCES pagamento_funcionario(id)
);

INSERT INTO pessoa (nome, cpf, sexo, data_nasc)  
VALUES ("Antônio dos Santos", "00000000000", "M", "2000-01-02"), ("Maria de Jesus", "10000000000", "F", "2001-04-12"), 
		("José da Silva", "20000000000", "M", "1993-04-12"),("Marcia Rocha", "30000000000", "F", "1998-05-10"),
        ("Marcos Antonio de Lima", "40000000000", "M", "1990-03-11"),("Vinicius Prado", "50000000000", "M", "1987-12-19"),
        ("Sabrina Antunes", "60000000000", "F", "1995-07-8"),("Luiz Antonio Junior", "70000000000", "M", "1992-01-12"),
        ("Valter Paes", "80000000000", "M", "1979-10-06"), ("João Arthur de Souza", "90000000000", "M", "1989-09-16"), 
        ("Janice Aparecida", "11000000000", "F", "1986-01-20");
  
INSERT INTO cliente (id, data_criacao)
VALUES (1, "2022-01-01"),(2, "2022-01-01"),(3, "2022-03-01"),(4, "2022-02-01"),(11, "2022-09-27");

INSERT INTO funcionario (id, email, telefone, data_criacao)
VALUES (5,"marcos@restaurante.com", "41999999999","2022-01-07"),
		(6,"vinicius@restaurante.com", "41988888888", "2022-01-03"),
        (7,"sabrina@restaurante.com", "41987777777", "2022-01-05"),
        (8,"luizantonio@restaurante.com", "41999999999","2022-01-07"),
		(9,"valterpaes@restaurante.com", "41988888888", "2022-01-03"),
        (10,"joaoarthur@restaurante.com", "41987777777", "2022-01-05");
        
INSERT INTO garcom (id, valor_hora)
VALUES (5,70.00),(6,73.00),(7,55.00);

INSERT INTO servicos_gerais (id, salario)
VALUES (8,1500.00),(9,1300.00),(10,2200.00);

INSERT INTO comanda (id_cliente, data_criacao,valor_total, num_items)
VALUES (1, "2022-09-01", 0.0, 0),(2, "2022-03-01", 0.0, 0), (3, "2022-06-01", 0.0, 0),(4, "2022-02-01", 0.0, 0),
        (4, "2022-02-18", 0.0, 0),(1, "2022-05-12", 0.0, 0), (1, "2022-07-11", 0.0, 0),(3, "2022-12-01", 0.0, 0),
        (3, "2022-08-21", 0.0, 0),(4, "2022-08-28", 0.0, 0),(11, "2022-09-27", 0.0, 0),(11, "2022-09-28", 0.0, 0);

INSERT INTO produto (nome, valor,quantidade)  
VALUES ("Refrigerante Laranja 1l", 7.00, 134),("Refrigerante Coca 1l", 7.00, 120),("Refrigerante Guaraná 1l", 7.00, 120),
		("Caipirinha de Limão", 18.00, 40),("Batata Frita 300g", 22.00, 70),("Alcatra acebolada 450g", 38.00, 90),
		("Cerveja 600ml", 12.00, 134),("Suco Polpa Abacaxi", 14.00, 70),("Batata Frita 500g", 39.00, 70),
        ("Executivo Frango", 28.00, 30),("Executivo Bife", 32.00, 30),("Executivo Picanha", 45.00, 30),
        ("Salada Mista", 25.00, 30),("Strogonoff de Frango", 35.00, 30),("Strogonoff de Carne", 37.00, 30),
        ("Esfirra de Frango", 4.90, 10), ("Esfirra de Carne", 4.90, 15), ("Esfirra de Queijo Provolone", 5.90, 5),
        ("Coxinha de Costela", 7.90, 20);

INSERT INTO registro(data_hora, valor_produto, quantidade, id_comanda, id_garcom,id_produto)
VALUES ("2022-09-01 23:42:00", 14.00, 3, 1, 5, 8),("2022-09-01 21:30:00", 38.00, 1, 1, 5, 6),("2022-09-01 21:30:00", 12.00, 2, 1, 5, 7),
		("2022-09-01 21:30:00", 12.00, 2, 1, 5, 13),("2022-09-01 22:00:00", 22.00, 1, 1, 6, 5),("2022-09-01 22:10:00", 22.00, 1, 1, 7, 19),
		("2022-09-01 22:10:00", 22.00, 1, 1, 7, 10),("2022-03-01 23:42:00", 7.00, 5, 2, 5, 2),("2022-03-01 21:30:00", 18.00, 2, 2, 5, 4),
        ("2022-03-01 21:30:00", 12.00, 6, 2, 5, 7),("2022-03-01 21:30:00", 25.00, 2, 2, 5, 13),("2022-03-01 22:00:00", 22.00, 1, 2, 6, 5),
        ("2022-03-01 22:10:00", 7.90, 1, 2, 7, 19),("2022-03-01 22:10:00", 28.00, 1, 2, 7, 10),("2022-06-01 23:42:00", 7.00, 1, 3, 5, 3),
		("2022-06-01 21:30:00", 7.00, 1, 3, 6, 1),("2022-06-01 21:30:00", 12.00, 2, 3, 6, 7),("2022-02-01 21:30:00", 22.00, 2, 4, 5, 4),
        ("2022-02-01 22:00:00", 14.00, 1, 4, 6, 8),("2022-02-01 22:10:00", 45.00, 1, 4, 7, 12),("2022-02-01 22:10:00", 28.00, 1, 4, 7, 10);

/*
SET SQL_SAFE_UPDATES = 0; #FALSE
SET SQL_SAFE_UPDATES = 1; #TRUE
*/
SET SQL_SAFE_UPDATES = 0; #FALSE
UPDATE comanda SET 
	valor_total = (SELECT SUM(quantidade * valor_produto) FROM restaurante.registro WHERE id_comanda = comanda.id),
	num_items = (SELECT SUM(quantidade) FROM restaurante.registro WHERE id_comanda = comanda.id);
SET SQL_SAFE_UPDATES = 1; #TRUE

INSERT INTO restaurante.registro_horas (numero_horas,data_registro,id_garcom)
	VALUES (4, '2022-09-01 23:59:00', 5), (2, '2022-09-01 23:59:00', 6), (3, '2022-03-01 23:59:00', 7);
    
/*EXERCÍCIOS*/

/*
1. Inserir um registro de produto nas comandas 5, 6, 10 e 12.
*/
INSERT INTO registro(data_hora, valor_produto, quantidade, id_comanda, id_garcom,id_produto) VALUES
	("2022-10-03 08:23:00", (SELECT valor FROM restaurante.produto WHERE id = 7), 4, 5, 6, 7),
	("2022-10-03 08:23:00", (SELECT valor FROM restaurante.produto WHERE id = 9), 8, 6, 5, 9),
	("2022-10-03 08:23:00", (SELECT valor FROM restaurante.produto WHERE id = 3), 2, 10, 5, 3),
	("2022-10-03 08:23:00", (SELECT valor FROM restaurante.produto WHERE id = 5), 7, 12, 7, 5);
SELECT * FROM registro;

/*
2. Atualizar o valor do produto 8 para R$ 12,00.
*/
UPDATE produto SET
	valor = 12
	WHERE id = 8;
SELECT * FROM produto;

/*
3. Atualizar a quantidade do produto 2, registrado na comanda 2, pelo
   garçom com 5, para ser igual a 3.
*/
UPDATE registro SET
	quantidade = 3
    WHERE id_comanda = 2 AND id_garcom = 5 AND id_produto = 2;
SELECT * FROM registro WHERE id_comanda = 2 AND id_garcom = 5;

/*
4. Excluir o registro do produto 19 na comanda 2.
*/
DELETE FROM registro WHERE id_comanda = 2 AND id_produto = 19;
SELECT * FROM registro WHERE id_comanda = 2;

/*
5. Criar a tabela Ingredientes, a qual está ligada ao produto por meio
   de uma relação muitos para muitos.
*/
CREATE TABLE ingrediente(
	id INT AUTO_INCREMENT NOT NULL,
    nome VARCHAR(50) NOT NULL,
    
    PRIMARY KEY(id)
);
CREATE TABLE produto_ingrediente( #Relação NxN
	id_produto INT NOT NULL,
    id_ingrediente INT NOT NULL,
    
    PRIMARY KEY(id_produto, id_ingrediente),
    FOREIGN KEY(id_produto) REFERENCES produto(id),
    FOREIGN KEY(id_ingrediente) REFERENCES ingrediente(id)
);

/*
6. Inserir os ingredientes necessários para preparação do produto 4
   ("Caipirinha de Limão") e vincular esses ingredientes.
*/
INSERT INTO ingrediente (nome)
VALUES ("Limão");
INSERT INTO produto_ingrediente
VALUES(4 /*CAIPIRINHA DE LIMÃO*/, 1/*LIMÃO*/);
SELECT * FROM ingrediente;
SELECT * FROM produto_ingrediente;


# DELETA O BANCO DE DADOS
#DROP DATABASE IF EXISTS restaurante;