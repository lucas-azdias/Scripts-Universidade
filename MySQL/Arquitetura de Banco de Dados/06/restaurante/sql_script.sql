/*DDL*/
# SQL não possui sensibiliade de caixa de letras (CREATE == create)

create database if not exists restaurante character set utf8mb4 collate utf8mb4_general_ci; # Cria database se não existir com o charset utf8mb4_general_ci
#drop database if exists restaurante; # Deleta database se existir

#show databases; # Mostra databases no server

use restaurante; # Coloca o database como o default para operações subsequentes

# DDL - Data Definition Language (dá forma ao database, montando o esqueleto)
# DML - Data Manipulation Language (manipula dentro do database, mexendo nas instâncias)
# DCL - Data Control Language (controla os privilégios para acesso do database)

# Pode-se alterar uma tabela com o 'alter table <tabela> add/drop/modify/change/rename <campo> <tipo> [first/after <campor>]'
# Pode-se visualizar os campos de uma tabela usando o 'describe'

# Deletar tabelas para garantir que não haja dados inválidos (na criação do database)
# Ordem inversa ao de criação
drop table if exists registro_horas;
drop table if exists registro;
drop table if exists pagamento_funcionario;
drop table if exists produto_ingrediente;
drop table if exists ingrediente;
drop table if exists produto;
drop table if exists pagamento_forma;
drop table if exists forma_pagamento;
drop table if exists comanda;
drop table if exists pagamento;
drop table if exists garcom;
drop table if exists serv_gerais;
drop table if exists funcionario;
drop table if exists cliente;
drop table if exists pessoa;

# Cria uma tabela com os atributos seguintes
create table if not exists pessoa( # Tudo conta como uma linha (vai até o ';')
	id integer auto_increment not null /*primary key*/, # Primary key -> junção das restrições 'unique' com 'not null'
    nome varchar(50) not null,
    cpf char(11) /*unique*/ not null,
    data_nasc date not null,
    sexo char(1) not null default 'i', # Se vier como nulo, é passado como o default
    
    # Definições póstumas permitem definições compostas (não para o atributa, mas para o par deles)
    primary key(id), # Definição póstuma de 'primary key'
    unique(cpf) # Definição póstuma da restrição 'unique'
);

create table if not exists cliente(
	id integer not null,
    data_criacao date not null,
    
	primary key(id),
    foreign key(id) references pessoa(id) # Tabela Pessoas precisa necessariamente existir previamente
);

create table if not exists funcionario(
	id integer not null,
    data_vinculo date not null,
    email varchar(40) not null,
    telefone varchar(20) not null,
    
	primary key(id),
    foreign key(id) references pessoa(id) # Tabela Pessoas precisa necessariamente existir previamente
);

create table if not exists serv_gerais(
	id integer not null,
    salario float not null,
    
    primary key(id),
    foreign key(id) references funcionario(id)
);

create table if not exists garcom(
	id integer not null,
    valor_hora float not null,
    
    primary key(id),
    foreign key(id) references funcionario(id)
);

create table if not exists pagamento(
	id integer auto_increment not null,
    id_cliente integer not null,
    valor float not null,
    data_hora datetime not null,
    
    primary key(id, id_cliente),
    foreign key(id_cliente) references cliente(id)
);

create table if not exists comanda(
	id integer auto_increment not null,
	data_registro datetime not null,
    id_cliente integer not null,
    id_pagamento integer,
    
    primary key(id),
    foreign key(id_cliente) references cliente(id),
    foreign key(id_pagamento) references pagamento(id)
);

create table if not exists forma_pagamento(
	id integer auto_increment not null,
	nome varchar(30) not null,
    
    primary key(id)
);

create table if not exists pagamento_forma(
	id_pagamento integer not null,
    id_forma integer not null,
    valor float not null,
    
    primary key(id_pagamento, id_forma),
    foreign key(id_pagamento) references pagamento(id),
    foreign key(id_forma) references forma_pagamento(id)
);

create table if not exists produto(
	id integer auto_increment not null,
    nome varchar(50) not null,
    valor float not null,
    quantidade integer,
    
    primary key(id)
);

create table if not exists ingrediente(
	id integer auto_increment not null,
    nome varchar(50) not null,
    quantidade decimal(6, 3) not null,
    
    primary key(id)
);

create table if not exists produto_ingrediente(
	id_produto integer not null,
    id_ingrediente integer not null,
    
    primary key(id_produto, id_ingrediente),
    foreign key(id_produto) references produto(id),
    foreign key(id_ingrediente) references ingrediente(id)
);

create table if not exists pagamento_funcionario(
	id integer auto_increment not null,
    id_funcionario integer not null,
    data_pag datetime not null,
    valor double not null,
    
    primary key(id),
    foreign key(id_funcionario) references funcionario(id)
);

create table if not exists registro(
	id_comanda integer not null,
	id_garcom integer not null,
	id_produto integer not null,
    data_hora datetime not null,
    valor_produto float not null,
    quantidade integer not null,
    id_pagamento integer,
    
    primary key(id_comanda, id_garcom, id_produto),
    foreign key(id_comanda) references comanda(id),
    foreign key(id_garcom) references garcom(id),
    foreign key(id_produto) references produto(id),
    foreign key(id_pagamento) references pagamento_funcionario(id)
);

create table if not exists registro_horas(
	id_garcom integer not null,
    data_reg datetime not null,
    numero_horas float not null,
    id_pagamento integer,
    
    foreign key(id_garcom) references garcom(id),
    foreign key(id_pagamento) references pagamento_funcionario(id)
);

/*DML*/
insert into pessoa(nome, cpf, data_nasc, sexo)
values ('João da Silva', '11122233300', '2000-01-01', 'm'),
	   ('Maria de Jesus', '22233344499', '2001-02-02', 'f');
       
# Usando '*', são selecionados todos os atributos
select nome, data_nasc from pessoa;

insert into pessoa(nome, cpf, data_nasc, sexo)
values ('Carlos Rodrigues', '99988877700', '1990-03-15', 'm');

select nome, data_nasc from pessoa
where data_nasc >= '2000-01-01';

# No SafeMode, pode-se deletar apenas se referenciando as keys (primary ou foreign)
# NÃO É RECOMENDADO DESABILITAR O SAFEMODE
delete from pessoa
where id = 2;

insert into pessoa(id, nome, cpf, data_nasc, sexo)
values (2, 'Maria de Jesus', '22233344499', '2001-02-02', 'f');

select * from pessoa;

/*Para não acumular databases inúteis*/
drop database if exists restaurante;
