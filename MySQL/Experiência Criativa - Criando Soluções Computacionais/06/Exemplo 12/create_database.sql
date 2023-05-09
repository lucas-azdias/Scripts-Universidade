create database if not exists experiencia_criativa_restaurante;

-- drop database if exists experiencia_criativa_restaurante;

create user if not exists "admin" identified by "123";
grant all on experiencia_criativa_restaurante.* to "admin" with grant option;
