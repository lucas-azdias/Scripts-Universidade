/*
São uma série de operações realizadas na hora em que é disparado uma resposta ou seja realizado alguma ação esperífica

A vantagem é retirar o processamento das máquinas clientes e pessar para o server

Fica assosciadas a uma tabela específica
*/

/*
DELIMITER $$
CREATE TRIGGER nome
	trigger_time trigger_event ON tabela
    FOR EACH ROW
    [trigger_order]
    BEGIN
		corpo da trigger (dá para fazer acesso ao valor anterior ou posterior a operação usando OLD.col_nome e NEW.col_name)
    END $$
DELIMITER ;

trigger_time -> BEFORE ou AFTER
trigger_event -> INSERT, UPDATE ou DELETE
trigger_order -> FOLLOWS ou PRECEDES
*/

DELIMITER $$
CREATE TRIGGER after_insert_registro
	AFTER INSERT ON registro
	FOR EACH ROW
    BEGIN
		UPDATE comanda SET
			valor_total = valor_total + NEW.valor_produto * NEW.quantidade,
            num_itens = num_itens + NEW.quantidade
            WHERE id = NEW.id_comanda;
		
        UPDATE produto SET
			quantidade = quantidade - NEW.quantidade
            WHERE id = NEW.id_produto;
    END $$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER before_insert_registro
	BEFORE INSERT ON registro
	FOR EACH ROW
    BEGIN
		DECLARE quantidade INT DEFAULT 0;
        
        SELECT quantidade INTO @quantidade FROM produto
        WHERE id = NEW.id_produto;
        
        IF @quantidade < NEW.quantidade THEN
			SET NEW.quantidade := @quantidade;
		ELSEIF NEW.quantidade < 0 OR NEW.quantidade IS NULL THEN
			SET NEW.quantidade := 0;
		END IF;
    END $$
DELIMITER ;
