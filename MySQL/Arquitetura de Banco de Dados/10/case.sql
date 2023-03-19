/*
CASE
*/
-- Funciona como um IF-ELSE
SELECT
	g.id AS "Id do garçom",
    CASE
    WHEN SUM(r.valor_produto * r.quantidade) < 300 # IF
    THEN SUM(r.valor_produto * r.quantidade) * 0.06 # Resultado para o IF == True
    ELSE SUM(r.valor_produto * r.quantidade) * 0.1 # ELSE
    END AS "Pagamento" # Indica fim do CASE (e o nomeia)
FROM garcom g
JOIN registro r ON r.id_garcom = g.id
WHERE r.id_comissao IS NULL
GROUP BY g.id;
