/*
VIEWS são tabelas virtuais, onde se salva a estrutura de uma consulta e as consultas individuais que ela executou
Atuam como tabelas com seus próprios campos (que por sua vez são derivados de outros)

São baseadas nas consultas SELECT
Pode-se usar elas para separar os tipos de consultas que um usuário pode ter dos dados (apenas liberar as consultas que eu quero para aquele usuário)

CREATE [OR REPLACE] [ALGORITHM = algorithm_type] VIEW view_name [(column_list)] AS select_statement
*/
CREATE VIEW view_cliente_produto
(id_cliente, nome_cliente, data_nasc_cliente, data_criacao_cliente, nome_produto, quantidade_total_produto)
AS (
SELECT
	p.id,
    p.nome,
    p.data_nasc,
    cl.data_criacao,
    pr.nome,
    SUM(r.quantidade)
FROM pessoa p
NATURAL JOIN cliente cl
INNER JOIN comanda cm ON cm.id_cliente = cl.id
INNER JOIN registro r ON r.id_comanda = cm.id
INNER JOIN produto pr ON pr.id = r.id_produto
GROUP BY p.id, p.nome, p.data_nasc, cl.data_criacao, pr.nome
);

SELECT * FROM view_cliente_produto;

SELECT
	nome_produto,
    SUM(quantidade_total_produto)
FROM view_cliente_produto
GROUP BY nome_produto
ORDER BY SUM(quantidade_total_produto) DESC;
