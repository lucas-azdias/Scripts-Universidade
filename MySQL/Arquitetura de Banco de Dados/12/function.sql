/*
Se diferencia da procedure, retornando retorna um valor único através da cláusula RETURN

A vantagem do MuSQL é oossuir várias funções pré-feitas (por isso é bom para fins educacionais)
*/

/*
DELIMITER $$
CREATE FUNCTION nome(parâmetros)
RETURNS var [NOT] DETERMINISTIC -> deterministic indica se a função retorna sempre o mesmo valor se dados os mesmos inputs
	BEGIN
		corpo da função
        RETURN valor;
	END $$
DELIMITER ;

Para chamar:
	CALL <nome_função>(parâmetros);
*/

DELIMITER $$
CREATE FUNCTION dia_da_semana(_date DATE)
RETURNS VARCHAR(20) DETERMINISTIC
	BEGIN
		DECLARE nome_dia_da_semana VARCHAR(20) DEFAULT NULL;
        
        SELECT
			CASE DAYOFWEEK(_date)
				WHEN 1 THEN "Domingo"
				WHEN 2 THEN "Segunda-feira"
				WHEN 3 THEN "Terça-feira"
				WHEN 4 THEN "Quarta-feira"
				WHEN 5 THEN "Quinta-feira"
				WHEN 6 THEN "Sexta-feira"
				WHEN 7 THEN "Sábado"
			END
		INTO nome_dia_da_semana;
        
        RETURN nome_dia_da_semana;
	END $$
DELIMITER ;

SELECT dia_da_semana('2022-10-24');
