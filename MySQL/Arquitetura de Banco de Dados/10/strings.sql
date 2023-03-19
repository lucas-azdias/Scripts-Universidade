/*
Manipulação de Strings
*/

SELECT CONCAT("My", "SQL");
-- Concatena Strings

SELECT CONCAT_WS(", ", "Abacaxi", "Maçã");
-- Concatena Strings com um separador entre elas

SELECT CHAR_LENGTH("Abacaxi");
-- Conta o número de caracteres em uma String

SELECT SUBSTRING("Gulag", 3);
SELECT SUBSTRING("Gulag" FROM 3);
SELECT SUBSTRING("Gulag", 1, 3);
-- Retorna uma String com todos os caracteres após a posição passada (incluindo o que está nela) ou entre o intervalo passado (de forma inclusiva)

SELECT UPPER("Gulag");
SELECT UCASE("Gulag");
-- Retorna a String com todas as letras como maiúsculas

SELECT LOWER("Gulag");
SELECT LCASE("Gulag");
-- Retorna a String com todas as letras como minúsculas

SELECT REPEAT("G", 2);
-- Retorna um String formada pela repetição da String passada pela quantidade desejada

SELECT REVERSE("GULAG");
-- Retorna um String formada pelo inverso da String passada
