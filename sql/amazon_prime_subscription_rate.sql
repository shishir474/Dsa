
-- Given the following two tables, return the fraction of users, rounded to two decimal places,
-- who accessed Amazon music and upgraded to prime membership within the first 30 days of signing up. 
-- P represents prime membership

drop table users;
create table users
(
user_id integer,
name varchar(20),
join_date date
);

-- My Sql can directly parse the date string in format YYYY-MM-DD or YY-MM-DD
insert into users
values 
(1, 'Jon', '2020-02-14'), 
(2, 'Jane', '2020-02-14'), 
(3, 'Jill', '2020-02-15'), 
(4, 'Josh', '2020-02-15'), 
(5, 'Jean', '2020-02-16'), 
(6, 'Justin', '2020-02-17'),
(7, 'Jeremy', '2020-02-18');

select * from users;
describe table users;



/*
NOTE: 
insert into users
values (1, 'Jon', CAST('2-14-20' AS date)), 
(2, 'Jane', CAST('2-14-20' AS date)), 
(3, 'Jill', CAST('2-15-20' AS date)), 
(4, 'Josh', CAST('2-15-20' AS date)), 
(5, 'Jean', CAST('2-16-20' AS date)), 
(6, 'Justin', CAST('2-17-20' AS date)),
(7, 'Jeremy', CAST('2-18-20' AS date));

The error you're seeing is likely due to the CAST('2-14-20' AS date) part — the date format '2-14-20' is ambiguous or invalid in many SQL engines, especially MySQL, which typically expects the format 'YYYY-MM-DD' or 'YY-MM-DD'.
MySQL automatically parses date strings in the 'YYYY-MM-DD' format without requiring CAST().

'2-14-20' can be misinterpreted or rejected due to locale or SQL dialect issues.

If you’re using PostgreSQL, you can use:

CAST('2020-02-14' AS DATE)

*/


select * from users;
select * from events;

create table events
(
user_id integer,
type varchar(10),
access_date date
);

INSERT INTO events (user_id, type, access_date)
VALUES
(1, 'Pay',    '2020-03-01'), 
(2, 'Music',  '2020-03-02'), 
(2, 'P',      '2020-03-12'),
(3, 'Music',  '2020-03-15'), 
(4, 'Music',  '2020-03-15'), 
(1, 'P',      '2020-03-16'), 
(3, 'P',      '2020-03-22');


-- so let's say in total we've 10 users and out of 10, 5 accessed amazon music and among them 2 upgraded to prime within 30 days
-- ans will be 2/5 i.e 50%
    
-- first get those users who accessed amazon prime
select * from users 
where user_id in (
select distinct user_id from events
where type = 'Music');

select * from events;

-- Now I need access date when they converted there membership to prime
-- so join with the events table. left join bcoz we need all users who accessed amazon music irrespecitve of whether they converted to prime
select * from users u 
left join events e on u.user_id = e.user_id 
where u.user_id in (			-- 1. first get those users who accessed amazon music
select distinct user_id from events
where type = 'Music');

-- now if I add e.type = 'p' condition in where clause it will just filter 2 rows where type = 'P' for user_id 2 and 3
-- But I want user_id 2,3,and 4. Hence adding this condition in join

select u.*, e.type, e.access_date from users u 
left join events e on u.user_id = e.user_id and e.type = 'P'
where u.user_id in (			-- 1. first get those users who accessed amazon music
select distinct user_id from events
where type = 'Music');

-- Now I need the above 3 users in the denominator (i.e total users who accessed amazon prime
-- I need to find users who upgraded to prime within 30 days of joining

select u.*, e.user_id, e.type, e.access_date, datediff(day,join_date, access_date) from users u 
left join events e on u.user_id = e.user_id and e.type = 'P'
where u.user_id in (			-- 1. first get those users who accessed amazon music
select distinct user_id from events
where type = 'Music');

-- our ans will be 1/3
select 
--u.*, e.type, e.access_date, datediff(day,join_date, access_date) from users u 
count(distinct u.user_id), count(distinct case when datediff(day,join_date, access_date) <= 30 then u.user_id end)
, 1.0*count(distinct case when datediff(day,join_date, access_date) <= 30 then u.user_id end)/count(distinct u.user_id) * 100
from users u 
left join events e on u.user_id = e.user_id and e.type = 'P'
where u.user_id in (			-- 1. first get those users who accessed amazon music
select distinct user_id from events
where type = 'Music');
