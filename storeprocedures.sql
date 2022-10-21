/*login*/
CREATE DEFINER=`anqsl`@`localhost` PROCEDURE `login`(in account varchar(11),in password varchar(16))
BEGIN 
    declare result tinyint default 0;
    declare account_password varchar(16);
    declare account_id int default 0;
    declare notfound tinyint default 0;
    declare cursor_account cursor for select account.password,account.id from account where account.account=account;
    declare continue handler for  not found set notfound = 1;
    if notfound=0 then
    open cursor_account;
    fetch cursor_account into account_password,account_id;
    if account_password=password then
	set result=1;
    else
    set account_id=0;
    end if;
    end if;
    select result,account_id;
END
/*register*/
CREATE DEFINER=`anqsl`@`localhost` PROCEDURE `register`(in account varchar(11),in password varchar(16))
BEGIN
    declare result tinyint default 0;
    declare notfound tinyint default 0;
    declare cursor_account cursor for select *from account where account.account=account;
    declare continue handler for not found set notfound=1;
    if notfound=1 then
    insert into account(account,password)values(account,password);
    set result=1;
    end if;
    select result;
END
