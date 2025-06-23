-- https://www.youtube.com/watch?v=ewmEHQSQYRM&list=PLBTZqjSKn0IeKBQDjLmzisazhqQy4iGkb&index=12&ab_channel=AnkitBansal
create table sales (
product_id int,
period_start date,
period_end date,
average_daily_sales int
);

insert into sales values(1,'2019-01-25','2019-02-28',100),(2,'2018-12-01','2020-01-01',10),(3,'2019-12-01','2020-01-31',1);

-- uses recursive cte logic

-- sample rec_cte code
with rec_cte as (
    select 1 as num

    union all

    select num + 1 as num from rec_cte 
    where num < 6
)
select * from rec_cte;




select *, datediff(day, period_start, period_end) from sales;


-- explode table - one record per date
with rec_cte as (
    select min(period_start) as dates, max(period_end) as max_date from sales

    union all 

    select dateadd(day,1,dates) as dates, max_date from rec_cte
    where dates < max_date
)
select * from rec_cte
inner join sales on dates between period_start and period_end
order by product_id, dates;


-- just aggregating the avg daily sales on year and product id
with rec_cte as (
    select min(period_start) as dates, max(period_end) as max_date from sales

    union all 

    select dateadd(day,1,dates) as dates, max_date from rec_cte
    where dates < max_date
)
select product_id, year(dates) as year, sum(average_daily_sales) from rec_cte
inner join sales on dates between period_start and period_end
group by product_id, year(dates)
order by product_id, year(dates);
