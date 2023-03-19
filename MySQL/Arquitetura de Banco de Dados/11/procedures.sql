/*
PROCEDURES retorna o resultado de uma consulta (diferente de uma função que retorna um valor único)

STORED PROCEDURES são indentificadas por um nome que as invocam
	Ex.: Processo de inserção de um novo cliente para o banco de dados
    
Ajuda com a simplificação das instruções para a manipulação dos dados (compila as requisições em uma única simples)
PAssa parte do processamento para o servidor
Facilita a manutenção e possíveis alterações no código (realizadas no servidor e não em outros arquivos)

DELIMITER $$
CREATE PROCEDURE nome_procedimento ([parâmetros])
	BEGIN
		corpo do procedimento
	END
$$
DELIMITER ;

parÂmetros -> MODO nome TIPO, MODO nome TIPO, ...
	MODO -> IN, OUT, INOUT
    TIPO -> INTEGER, VARCHAR, CHAR, TEXT, DOUBLE, ...

Para usar um procedimento:
	CALL nome_procedimento(parâmetros);

Para deletar um procedimento:
	DROP PROCEDURE IF EXISTS nome_procedimento;
    
Exemplos de uso:
	Criar um novo registro, verificar algum dado, retornar algum dado, ...
    
Nomes de parâmetros (padrão para evitar conflitos):
	De entrada: _<nome>
    De sáida: <nome>_
    De entrada e sáida: _<nome>_
*/
DELIMITER $$
CREATE PROCEDURE faturamento_dia_semana(IN ano YEAR)
	BEGIN
		SELECT
			WEEKDAY(cm.data_criacao) AS "Dia da semana",
            SUM(cm.valor_total) AS "Faturamento"
		FROM comanda cm
        WHERE YEAR(cm.data_criacao) = ano
        GROUP BY WEEKDAY(cm.data_criacao)
        ORDER BY WEEKDAY(cm.data_criacao);
	END
$$
DELIMITER ;

CALL faturamento_dia_semana(2022);


DELIMITER §§
CREATE PROCEDURE insert_new_garcom(
		IN _nome VARCHAR(50),
		IN _cpf VARCHAR(11),
		IN _sexo CHAR(1),
		IN _data_nasc DATE,
		IN _email VARCHAR(40),
		IN _telefone VARCHAR(20),
		IN _valor_hora DOUBLE
    )
	BEGIN
		DECLARE id_garcom INT DEFAULT NULL;
    
		IF _nome IS NOT NULL AND
		   _cpf IS NOT NULL AND
           _data_nasc IS NOT NULL AND
           _email IS NOT NULL AND
           _telefone IS NOT NULL AND
           _valor_hora IS NOT NULL THEN
			INSERT INTO pessoa
			VALUES (NULL, _nome, _cpf, UPPER(_sexo), _data_nasc);
			
			SET id_garcom := (SELECT LAST_INSERT_ID());
			
			INSERT INTO funcionario
			VALUES (id_garcom, _email, _telefone, NOW());
			
			INSERT INTO garcom
			VALUES (id_garcom, _valor_hora);
        END IF;
        
        SELECT id_garcom;
    END
§§
DELIMITER ;

CALL insert_new_garcom("João Paulo", "11188877700", 'm', "2000-01-10", "joaopaulo@gmail.com", "45988887777", 10.34);
