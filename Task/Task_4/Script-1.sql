
--Предыдущее задание (создание базы)-----------------------

--Нужно хранить персональную информацию о клиентах :

--имя,
--фамилия,
--email,
--телефон.

--Сложность в том, что телефон у клиента может быть не один, а два, три и даже больше.
--А может и не быть — например, если он не захотел его оставлять.


--Метод, создающий структуру БД(таблицы).

create table if not exists FIO (
id_FIO serial primary key,
names varchar (200) not null,
surnames varchar (200) not null,
email varchar (100) not null,
unique(names, surnames, email));

create table if not exists telephone (
id_telephone serial primary key,
id_FIO integer not null references FIO(id_FIO),
telephones_cod varchar (5),
telephones numeric(15,0),
unique(id_FIO,telephones_cod,telephones));

-------------------------------------

---Метод, позволяющий добавить нового клиента (без телефона).
insert into FIO ( names,surnames,email) values ('Имя 1', 'Фамилия 1', 'mail_1_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 2', 'Фамилия 2', 'mail_2_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 3', 'Фамилия 3', 'mail_3_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 4', 'Фамилия 4', 'mail_4_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 5', 'Фамилия 5', 'mail_5_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 6', 'Фамилия 6', 'mail_6_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 7', 'Фамилия 7', 'mail_7_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 8', 'Фамилия 8', 'mail_8_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 9', 'Фамилия 9', 'mail_9_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 10', 'Фамилия 10', 'mail_10_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 11', 'Фамилия 11', 'mail_11_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 12', 'Фамилия 12', 'mail_12_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 13', 'Фамилия 13', 'mail_13_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 14', 'Фамилия 14', 'mail_14_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 15', 'Фамилия 15', 'mail_15_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 16', 'Фамилия 16', 'mail_16_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 17', 'Фамилия 17', 'mail_17_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 18', 'Фамилия 18', 'mail_18_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 19', 'Фамилия 19', 'mail_19_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 20', 'Фамилия 20', 'mail_20_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 21', 'Фамилия 21', 'mail_21_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 22', 'Фамилия 22', 'mail_22_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 23', 'Фамилия 23', 'mail_23_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 24', 'Фамилия 24', 'mail_24_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 25', 'Фамилия 25', 'mail_25_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 26', 'Фамилия 26', 'mail_26_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 27', 'Фамилия 27', 'mail_27_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 28', 'Фамилия 28', 'mail_28_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 29', 'Фамилия 29', 'mail_29_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 30', 'Фамилия 30', 'mail_30_1@yandex.ru');
insert into FIO ( names,surnames,email) values ('Имя 40', 'Фамилия 30', 'mail_40_1@yandex.ru');


insert into telephone (id_FIO,telephones_cod,telephones) values (1, '+7', 9055774720);
insert into telephone (id_FIO,telephones_cod,telephones) values (2, '',0);
insert into telephone (id_FIO,telephones_cod,telephones) values (3, '',0);
insert into telephone (id_FIO,telephones_cod,telephones) values (4, '',0);
insert into telephone (id_FIO,telephones_cod,telephones) values (5, '+7', 9775774724);
insert into telephone (id_FIO,telephones_cod,telephones) values (5, '+7', 9775774725);
insert into telephone (id_FIO,telephones_cod,telephones) values (5, '+7', 9775774726);
insert into telephone (id_FIO,telephones_cod,telephones) values (5, '+7', 9775774727);
insert into telephone (id_FIO,telephones_cod,telephones) values (5, '+7', 9775774728);
insert into telephone (id_FIO,telephones_cod,telephones) values (5, '+7', 9775774729);
insert into telephone (id_FIO,telephones_cod,telephones) values (6, '+7', 9055774725);
insert into telephone (id_FIO,telephones_cod,telephones) values (7, '+7', 9055774726);
insert into telephone (id_FIO,telephones_cod,telephones) values (8, '+7', 9055774727);
insert into telephone (id_FIO,telephones_cod,telephones) values (9, '+7', 9055774728);
insert into telephone (id_FIO,telephones_cod,telephones) values (10, '+7', 9055774729);
insert into telephone (id_FIO,telephones_cod,telephones) values (11, '+7', 9055774730);
insert into telephone (id_FIO,telephones_cod,telephones) values (12, '+7', 9055774731);
insert into telephone (id_FIO,telephones_cod,telephones) values (13, '+7', 9055774732);
insert into telephone (id_FIO,telephones_cod,telephones) values (14, '+7', 9055774733);
insert into telephone (id_FIO,telephones_cod,telephones) values (15, '+7', 9055774734);
insert into telephone (id_FIO,telephones_cod,telephones) values (16, '+7', 9055774735);
insert into telephone (id_FIO,telephones_cod,telephones) values (17, '8', 9055774736);
insert into telephone (id_FIO,telephones_cod,telephones) values (18, '8', 9055774737);
insert into telephone (id_FIO,telephones_cod,telephones) values (19, '8', 9055774738);
insert into telephone (id_FIO,telephones_cod,telephones) values (20, '8', 9055774739);
insert into telephone (id_FIO,telephones_cod,telephones) values (21, '8', 9055774740);
insert into telephone (id_FIO,telephones_cod,telephones) values (22, '8', 9055774741);
insert into telephone (id_FIO,telephones_cod,telephones) values (23, '8', 9055774742);
insert into telephone (id_FIO,telephones_cod,telephones) values (24, '8', 9055774743);
insert into telephone (id_FIO,telephones_cod,telephones) values (25, '8', 9055774744);
insert into telephone (id_FIO,telephones_cod,telephones) values (26, '8', 9055774745);
insert into telephone (id_FIO,telephones_cod,telephones) values (27, '8', 9055774746);
insert into telephone (id_FIO,telephones_cod,telephones) values (28, '8', 9055774747);
insert into telephone (id_FIO,telephones_cod,telephones) values (29, '8', 9055774748);
insert into telephone (id_FIO,telephones_cod,telephones) values (30, '8', 9055774749);

----------------------------------------------------

---Метод, позволяющий добавить телефоны нового клиента.
insert into telephone (id_FIO,telephones_cod,telephones) values ((select f.id_fio from fio as F where f.names = 'Имя 40' and f.surnames = 'Фамилия 30' and f.email = 'mail_40_1@yandex.ru' ), '8', 9055774749777);

--Метод, позволяющий добавить телефон для существующего клиента (заменить старый номер).
update telephone as t set telephones_cod = '+100', telephones = 555555555 
where t.id_fio = (select f.id_fio from fio as F where f.names = 'Имя 7' and f.surnames = 'Фамилия 7' and f.email = 'mail_7_1@yandex.ru')
and (telephones_cod = '+7' and telephones = 9055774726);

--Метод, позволяющий изменить данные о клиенте (по частям).
update fio as F set names = 'я тут был 4!!!!!!' where f.id_fio  = (select f.id_fio from fio as F where f.names = 'Имя 4' and f.surnames = 'Фамилия 4' and f.email = 'mail_4_1@yandex.ru' );
update fio as F set surnames = 'я тут был 5!!!!!!' where f.id_fio  = (select f.id_fio from fio as F where f.names = 'Имя 7' and f.surnames = 'Фамилия 7' and f.email = 'mail_7_1@yandex.ru' );
update fio as F set email = 'я тут был 6!!!!!!' where f.id_fio  = (select f.id_fio from fio as F where f.names = 'Имя 6' and f.surnames = 'Фамилия 6' and f.email = 'mail_6_1@yandex.ru' );

--Метод, позволяющий изменить данные о клиенте (целиком).
update fio as F set names = 'я тут был!!!!!!', surnames = 'я тут был!!!!!!', email = 'я тут был!!!!!!' 
where f.id_fio  = (select f.id_fio from fio as F where f.names = 'Имя 25' and f.surnames = 'Фамилия 25' and f.email = 'mail_25_1@yandex.ru' );

--Метод, позволяющий удалить существующего клиента (полностью).
delete from telephone t where t.id_fio  = (select f.id_fio from fio as F where f.names = 'Имя 6' and f.surnames = 'Фамилия 6' and f.email = 'я тут был !!!!!!' );
delete from fio f where f.id_fio  = (select f.id_fio from fio as F where f.names = 'Имя 6' and f.surnames = 'Фамилия 6' and f.email = 'я тут был !!!!!!' );

--Метод, позволяющий удалить телефон у существующего клиента.
delete from telephone t where t.id_fio  = (select f.id_fio from fio as F where f.names = 'Имя 5' and f.surnames = 'Фамилия 5' and f.email = 'mail_5_1@yandex.ru' )
and (telephones_cod = '+7' and telephones = 9775774729);

--Метод, позволяющий найти все телефоны клиента
select id_FIO,telephones_cod,telephones from telephone 
where id_FIO = (select f.id_fio from fio as F where f.names = 'Имя 5' and f.surnames = 'Фамилия 5' and f.email = 'mail_5_1@yandex.ru' );



--Метод, позволяющий найти клиента по его данным — имени, фамилии, email или телефону.

--Метод, позволяющий найти клиента по его данным — имени
select id_fio, names, surnames, email  from fio where names = 'nnnn';

--Метод, позволяющий найти клиента по его данным — фамилии
select id_fio, names, surnames, email  from fio where surnames = 'Фамилия 5';

--Метод, позволяющий найти клиента по его данным — email
select id_fio, names, surnames, email  from fio where email = 'mail_5_1@yandex.ru';

--Метод, позволяющий найти клиента по его данным — телефону
select id_fio, names, surnames, email  from fio 
where id_FIO = (select t.id_fio from telephone as t where t.telephones_cod = '+7' and t.telephones = 9055774730);

--Метод, позволяющий удалить всю базу таблиц
drop table telephone,fio;







select id_FIO,telephones_cod,telephones 
from telephone  T
where telephones = 0;

select id_FIO,telephones_cod,telephones 
from telephone  T
where telephones_cod = '+7';

select F.names from fio f
where F.names = 'Имя 5';
order by F.names desc

select t.id_fio, t.telephones from telephone t
group by t.id_fio, t.telephones
having t.id_fio = 5;
order by t.id_fio desc

select F.id_fio, T.id_telephone, F.names,F.surnames,F.email, T.telephones_cod, T.telephones from telephone t 
LEFT outer join FIO F on T.id_telephone = F.id_fio
group by  F.id_fio, T.id_telephone, F.names,F.surnames,F.email, T.telephones_cod, T.telephones
order by F.names desc

select F.id_fio, T.id_telephone, F.names,F.surnames,F.email, T.telephones_cod, T.telephones from telephone t 
RIGHT outer join FIO F on T.id_telephone = F.id_fio
group by  F.id_fio, T.id_telephone, F.names,F.surnames,F.email, T.telephones_cod, T.telephones
order by F.names desc



























































