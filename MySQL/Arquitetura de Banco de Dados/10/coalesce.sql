/*
COALESCE
*/
-- Retorna o primeiro valor não nulo nos parâmetros passados
SELECT id_comanda, COALESCE(id_comissao, 0) FROM registro;

# Caso seja necessário apenas especificar o que acontece caso um único parâmetro seja nulo, pode-se usar o IFNULL
SELECT id_comanda, IFNULL(id_comissao, 0) FROM registro;
