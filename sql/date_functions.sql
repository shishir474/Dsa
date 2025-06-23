-- datepart(interval, date), dateadd(interval, no_to_add, date), datediff(interval, start_date datetime, end_date datetime)

-- interval can be [day, month, year, hour, quarter, day_of_week, day_of_year, minute]

-- supported by SQL Server
select datepart('day', '2022-01-23');

-- supported by snowflake, postgres, 
select EXTRACT(day from TO_DATE('2022-01-13'));

-- supported by MySQL
select year('2022-01-23') 



-- select EXTRACT(DAY FROM TO_DATE('2022-01-23'));
select dateadd(day, 2, TO_DATE('2020-02-01'));

-- calculate the difference between 2 dates
select datediff(day, TO_DATE('2020-02-01'), TO_DATE('2021-02-01'));


Summary Table
SQL Dialect	Alternative to DATEPART()
MySQL       ->	YEAR(), MONTH(), DAY() etc.
PostgreSQL  -> 	EXTRACT(field FROM date)
Snowflake	-> EXTRACT(), YEAR(), MONTH()
Oracle	    ->  EXTRACT() or TO_CHAR(date, fmt)
BigQuery	-> EXTRACT()
SQLite	    -> strftime('%Y', date) etc.
SQL Server	-> DATEPART() (native)

common date functions: 

interval can be [day, month, year, hour, quarter, day_of_week, day_of_year, minute] --> there are some more intervals which are allowed --> Google it
1. datepart(interval, date)
2. dateadd(interval, value, date)
3. datediff(interval, start_date, end_date)       -- calculates the differences between 2 datetime objects
4. year(string_literal), month()  --> common in snowflake                 -- NOTE: some functions allow date to be passed as string literal, some need strict datetime object
5. extract(interval from date)



-- 1st Question

-- find the no of days between order_date and shipped_date from order table. Assume you have 2 columns order_date and ship_date

-- I can simply use datediff function

-- what if I have to find the no of business days(sat-sun not considered)
-- first I'll find the no of weeks between order_date and shipped_date. no_of_weeks*2 is the no of weekend days
-- subtract the weekend days from the actual date difference
select order_date, shipped_date, datediff(day,order_date,shipped_date) as actual_days_difference,
	datediff(week,order_date,shipped_date) week_diff,
	datediff(day,order_date,shipped_date) - 2*datediff(week,order_date,shipped_date) business_days 
from orders;


-- 2nd question

-- given the birth date of the customer, find the age

-- again I can use the datediff function between the current_date and birth_date and get the years
-- GETDATE() returns today's date
select datediff(year, birth_date, GETDATE()) as age;

--
