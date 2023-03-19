# OBS.: Em nomeando o ID de uma tabela, deve-se nomear como "id_<table>" pois facilita uso do SELECT e do JOIN

-- Os JOINS são baseados na Teoria dos Conjuntos.

/*
NATURAL JOIN
*/
SELECT * FROM pessoa, cliente
WHERE pessoa.id = cliente.id;

SELECT * FROM pessoa NATURAL JOIN cliente; -- Retorna em relação ao primeiro campo de mesmo nome nas tabelas

SELECT
	p.id,
	p.nome,
    c.id,
    c.data_criacao
FROM pessoa as p, cliente as c
WHERE p.id = c.id;

/*
INNER JOIN
*/
SELECT pessoa.*, cliente.*, comanda.*
FROM pessoa
INNER JOIN cliente ON cliente.id = pessoa.id
INNER JOIN comanda ON comanda.id_cliente = cliente.id;

/*
LEFT JOIN
*/
SELECT *
FROM cliente cl
LEFT JOIN comanda co ON co.id_cliente = cl.id;

SELECT
	pc.nome AS "Nome do cliente",
    pc.data_nasc AS "Data de nascimento do cliente",
    c.id AS "Id da comanda",
    p.id AS "Id do produto",
    p.nome AS "Nome do produto",
    r.valor_produto "Valor do produto",
    g.valor_hora "Valor-hora do garçom",
    pe.nome AS "Nome do garçom",
    f.telefone AS "Telefone do garçom"
FROM pessoa pc
INNER JOIN cliente cl ON pc.id = cl.id
INNER JOIN comanda c ON c.id_cliente = cl.id
LEFT JOIN registro r ON r.id_comanda = c.id
LEFT JOIN produto p ON p.id = r.id_produto
LEFT JOIN garcom g ON g.id = r.id_garcom
LEFT JOIN funcionario f ON f.id = g.id
LEFT JOIN pessoa pe ON pe.id = f.id;

/*
RIGHT JOIN
*/
SELECT *
FROM pagamento_funcionario pf
RIGHT JOIN registro r ON pf.id = r.id_comissao;

/*
FULL OUTER JOIN
*/
/*
SELECT *
FROM pagamento_funcionario pf
FULL OUTER JOIN registro r ON r.id_comissao = pf.id;
*/ -- Não há no MySQL (precisa usar o UNION entre um LEFT JOIN e um RIGHT JOIN)
(
SELECT * FROM pagamento_funcionario pf
LEFT JOIN registro r ON r.id_comissao = pf.id
)
UNION
(
SELECT * FROM pagamento_funcionario pf
RIGHT JOIN registro r ON r.id_comissao = pf.id
);

/*
CROSS JOIN (é o produto cartesiano)
*/
SELECT * FROM cliente
CROSS JOIN funcionario;
