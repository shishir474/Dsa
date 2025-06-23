-- SELECT TO_CHAR(date, 'MONTH'), extract(year from date) 
-- FROM stock_prices LIMIT 10;


-- this will give me max and min open prices across all the rows in the table.
-- I want one row per ticker
-- select ticker, date, max(open) over(partition by ticker) highest_open, 
-- min(open) over(PARTITION by ticker) as lowest_open
-- from stock_prices

-- this gives the max and min open price for each ticker
-- select ticker, max(open) highest_open, 
-- min(open) as lowest_open
-- from stock_prices
-- group by ticker

-- Now I have to get the corresponding date as well for each max and min value 
-- join with the main table stock_prices on cte.ticker and cte.highest_open 
-- to get the highest_month 
-- and again join with another instance of stock_prices on cte.ticker and cte.lowest_open 
-- to get the lowest from stock_prices

-- to_char(date, month) 
-- substr(string column, start_position, length) - indexing starts from 1 in sql strings

-- month_nbr - (1 to 12)
-- month_nm - (January to december
-- day_nm - (Monday to Sunday)
-- day_nbr = (1 to 31)
select date, to_char(date, 'month') as month_nm, extract(month from date) as month_nbr,
  extract(year from date) as year, substring(to_char(date,'day'),1,3) as day_nm,
  extract(day from date) as day_nbr
from stock_prices;


-- final query
with cte as (
select ticker, max(open) highest_open, 
min(open) as lowest_open
from stock_prices
group by ticker
)
select c.ticker, TO_CHAR(sp1.date,'Mon-YYYY') as highest_month,
  c.highest_open, TO_CHAR(sp2.date,'Mon-YYYY') as lowest_mth, c.lowest_open
from cte c
inner join stock_prices sp1 on c.ticker = sp1.ticker and c.highest_open = sp1.open
inner join stock_prices sp2 on c.ticker = sp2.ticker and c.lowest_open = sp2.open
order by c.ticker;

