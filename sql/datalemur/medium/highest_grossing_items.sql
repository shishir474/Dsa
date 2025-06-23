-- top 2 grossing products within each category in 2022

with cte as (
SELECT category, product, sum(spend) as total_spend
FROM product_spend
where extract(year from transaction_date) = 2022
group by category, product
-- where year(transaction_date) = 2022;
),
ranked_cte as (
select *, row_number() over(partition by category order by total_spend desc) rn
from cte
)
select category, product, total_spend from ranked_cte
where rn <= 2;

-- to extract year from timestamp column, 2 appraoches
-- 1. year(transaction_date) = 2022 --works in snowflake, mysql etc
-- 2. extract(year from transaction_date) = 2022 -- works in postgressql


-- teaches how to extract year from timestamp column 