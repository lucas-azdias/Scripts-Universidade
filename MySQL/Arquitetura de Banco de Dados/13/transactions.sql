/*
Quando se inicia uma transação, as mudanças não ocorrem até ser emitido o comando COMMIT
E podem ser revertidas quando usado o ROLLBACK

Apenas se aplica as instruções de DML (SELECT, INSERT, UPDATE e DELETE) que precisam ter ACID,
assim a TRANSACTION complementa isso (passa o ACID para um conjunto de operações e não mais apenas para uma específica)

Termina quando encontra a instrução de COMMIT/ROLLBACK explícito ou quando encontra instrução DDL (implícito)

Precisa ter a opção "autocommit" como FALSE, se não as alterações serão salvas automaticamente

Se encontrar erro no meio da TRANSACTION, como ainda não havia salvo, nada acontece

Há o SAVEPOINT, onde dentro de uma TRANSACTION, há o salvamento daquele estado até aquele instante, assim
em um ROLLBACK TO SAVEPOINT, há a reversão até aquele SAVEPOINT (não mais por toda TRANSACTION). mas ainda sim
é possível fazer um ROLLBACK total da TRANSACTION;
*/

USE restaurante;

SET autocommit := FALSE;

SELECT * FROM registro WHERE id_comanda = 2;

START TRANSACTION;
DELETE FROM registro WHERE id_comanda = 2;
SELECT * FROM registro WHERE id_comanda = 2;
ROLLBACK;

SELECT * FROM registro WHERE id_comanda = 2;
