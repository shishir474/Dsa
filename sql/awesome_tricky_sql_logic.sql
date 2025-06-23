-- https://www.youtube.com/watch?v=WrToXXN7Jb4&list=PLBTZqjSKn0IeKBQDjLmzisazhqQy4iGkb&index=10&ab_channel=AnkitBansal
create table tasks (
date_value date,
state varchar(10)
);

insert into tasks  values ('2019-01-01','success'),('2019-01-02','success'),('2019-01-03','success'),('2019-01-04','fail')
,('2019-01-05','fail'),('2019-01-06','success');


select * from tasks;

-- output 
--start_date, end_date, state

-- first we need to bring these records to the same base. If we subtract date_value - row_number --> each group records will eventually get merged to one single date
-- then  for each group, we just need to find the start and end date which is min and max date_value of each group
with group_date as (
select *, row_number() over(partition by state order by date_value asc) as rn,
dateadd(day, -1*row_number() over(partition by state order by date_value asc), date_value) as group_date
from tasks
)
select min(date_value) as start_date, max(date_value) as end_date, state
from group_date
group by group_date, state
order by start_date;