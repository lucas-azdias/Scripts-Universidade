/*
Manipulalção de Datas
*/

SET @date := '2022-10-05';

SELECT DAYOFWEEK(@date);
-- Retorna o índice do dia da semana (1 = Domingo, 2 = Segunda-feira etc.)

SELECT WEEKDAY(@date);
-- Retorna o índice do dia da semana (0 = Segunda-feira, 1 = Terça-feira etc.)

SELECT DAYOFMONTH(@date);
-- Retorna o dia da data em relação ao mês

SELECT DAYOFYEAR(@date);
-- Retorna o dia da data em relação ao ano

SELECT MONTH(@date);
-- Retorna o mês da data

SELECT YEAR(@date);
-- Retorna o ano da data

SELECT NOW();
SELECT CURRENT_TIMESTAMP();
-- Retorna a data-hora atual

SELECT CURDATE();
-- Retorna a data atual

SELECT DAYNAME(@date);
-- Retorna o nome do dia da semana da data

SELECT MONTHNAME(@date);
-- Retorna o nome do mês da 

SELECT DATE_ADD(@date, INTERVAL 4 YEAR);
SELECT DATE_ADD(NOW(), INTERVAL 10 HOUR);
-- Retorna a soma da data passada com um intervalo

SELECT DATE_SUB(CURDATE(), INTERVAL 200 YEAR);
-- Retorna a subtração da data passada com um intervalo

# Cálculo de idade
SELECT YEAR(FROM_DAYS(TO_DAYS(NOW()) - TO_DAYS('2004-06-11'))) as "Idade";
