/*
Determina se um usuário que se conecta de um determinado host,
possui certos privilégios como SELECT, INSERT, UPDATE e DELETE.

Pode-se limitar o acesso a um banco, tabela ou coluna

Controle de acesso tem duas etapas:
	1 - O usuário pode se conectar?
	2 - Se sim, o servidor verifica se você possui privilégios
		para as queries que você tente executar.
    
As informações dos usuários e os privilégios ficam no banco de dados mysql em 4 tabelas
	user - possui as informações dos usuários e eos privilégios globais dele (a todos os bancos de dados);
    db - armazena os privilégios dos usuários específicos de um banco de dados (a todas as tabelas);
    tables_priv - armazena os privilégios dos usuários específicos de uma tabela (a todas as colunas);
    columns_priv - armazena os privilégios dos usuários específicos de uma coluna (apenas para a coluna).
    (há outras tabelas nesse banco de dados mysql que guardam outras informações)
    
Tipos de privilégios:
	1 - Privilégios administradores (user);
    2 - Privilégios de banco de dados (db);
    3 - Privilégios para objetos de banco de dados (tabelas, colunas, índices, views etc.) (tables_priv, columns_priv etc.).

GRANT <privilégio> ON <objeto> TO <nome do usuário> [WITH GRANT OPTION -> concede o privilégio de repassar os seus privilégios a outros];
REVOKE <privilégio> ON <objeto> TO <nome do usuário>;
<objeto>:
	*.* -> global;
    db.* -> banco de dados;
    db.tabela -> tabela de banco de dados.

ROUTINE -> são FUNCTIONS, PROCEDURES e TRIGGERS

Quando se modifica os privilégios, eles não são carregados automaticamente,
assim, é preciso: reiniciar (geralmente evitado) ou fazer um reload dos privilégios (FLUSH PRIVILEGES) que é o mais recomendado.
Por isso, tem os momentos de manutenção dos servidores (como nas instituições financeiras).

Para criar ou remover contas:
	1 - CREATE/DROP USER <nome do usuário>;
	2 - Ou diretamente nas tabelas do mysql.

Pode-se limitar os recursos do banco de dados para as contas individuais
(número de consultas, número de conexões, número de atualizações ou número de conexões simultâneas):
GRANT USAGE ON <objeto> -> se global, *.*:
	GRANT/REVOKE <privilégio> ON <objeto> TO <nome do usuário>
	WITH MAX_QUERIES_PER_HOUR <valor> | MAX_UPDATES_PER_HOUR <valor> | MAX_CONNECTIONS_PER_HOUR <valor>;
	(valor nulo indica ilimitado)

Pode-se informar o host que o usuário pode acessar através, se naõ informado é passado como "%", ou seja, qualquer IP.

Pode-se criar um ROLE para simplificar a distribuição de privilégios a usuários equivalentes
CREATE ROLE 'administrador', 'cliente', 'garcom';
(depois se dá os privilégios ao ROLE com o GRANT e, sequencialmente, se dá o ROLE ao usuário também com o GRANT)
(se haver modificações no ROLE após a concessão, ainda sim os privilégios do usuário que recebeu serão alterados)
*/

CREATE ROLE IF NOT EXISTS "clientes";

CREATE USER IF NOT EXISTS "cliente1";
CREATE USER IF NOT EXISTS "remoto" IDENTIFIED BY "remoto";
CREATE USER IF NOT EXISTS "teste" IDENTIFIED BY "123";

-- Apenas para o endereço localhost
GRANT SELECT(nome, valor, quantidade) ON restaurante.produto
TO "clientes";
GRANT "clientes" TO "cliente1";

-- Para o endereço específico
GRANT ALL ON restaurante.*
TO "remoto"@"%.restaurante.com.br" WITH GRANT OPTION;

-- Para todos os endereços
GRANT SELECT ON *.*
TO "remoto"@"%" WITH GRANT OPTION;

-- Para usuário anônimo -> " "
GRANT SELECT(nome) ON restaurante.produto
TO " "@"%.restaurante.com.br";

-- Remover usuário
DROP USER IF EXISTS "teste";
