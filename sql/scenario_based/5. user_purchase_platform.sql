-- https://www.youtube.com/watch?v=4MLVfsQEGl0&list=PLBTZqjSKn0IeKBQDjLmzisazhqQy4iGkb&index=11&ab_channel=AnkitBansal

create table spending 
(
user_id int,
spend_date date,
platform varchar(10),
amount int
);

insert into spending values(1,'2019-07-01','mobile',100),(1,'2019-07-01','desktop',100),(2,'2019-07-01','mobile',100)
,(2,'2019-07-02','mobile',100),(3,'2019-07-01','desktop',100),(3,'2019-07-02','desktop',100);


/* User purchase platform.
-- The table logs the spendings history of users that make purchases from an online shopping website which has a desktop 
and a mobile application.
-- Write an SQL query to find the total number of users and the total amount spent using mobile only, desktop only 
and both mobile and desktop together for each date.
*/

select * from spending order by spend_date;

with cte as (
    select spend_date, user_id,  max(platform) as platform, sum(amount) as total_amt
    from spending 
    group by spend_date, user_id having count(distinct platform) = 1
    
    union all
    
    select spend_date, user_id,  'both' as platform, sum(amount) as total_amt
    from spending 
    group by spend_date, user_id having count(distinct platform) = 2
    
    union all -- inserting dummy record for 2nd july 
    
    select distinct spend_date, null as user_id, 'both' as platform, '0' as amount
    from spending
)
select spend_date, platform, sum(total_amt) as total_amt, count(distinct user_id) as total_users
from cte
group by spend_date, platform;

-- I need platform in final output, but I cannot add that as it is, bcoz then then I would have to add that in group by clause as well
-- and the problem with that is each group (spend_date, user_id, platform) will always contain 1 distinct platform. Hence using max(platform) to avoid adding it in group by clause

-- spend_date, platform, total_amount, total_users
