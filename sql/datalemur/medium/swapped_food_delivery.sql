-- we need to know the total number of orders in the order table using count() function 
-- Knowing total number of orders is important to determine whethere there are an odd or even number of orders 
-- now to access the total number of orders in the main query, we are performing a cartesian product or cross join between orders and order_counts cte.
-- These means every row in orders is paired with single row from the order_counts.
-- we need this to determine if the current order_id is the last one and to apply the correct swapping logic

WITH order_counts AS (
  SELECT COUNT(order_id) AS total_orders 
  FROM orders
)
SELECT 
-- order_id,        -- 2 cases for odd order id and 1 case for even order_id
case when order_id%2=1 and order_id != total_orders then order_id + 1
    when order_id%2=1 and order_id = total_orders then order_id
    else order_id - 1
end as corrected_order_id, item
FROM orders cross join order_counts
order by corrected_order_id;


-- solution 2:
select 
-- order_id,
case when order_id%2 = 1 and order_id = (select max(order_id) from orders) then order_id 
    when order_id%2 = 1 then order_id + 1
    else order_id - 1
end as corrected_order_id, item
FROM orders 
order by corrected_order_id;


--- solution 3
-- using lead(item) and lag(item)
select 
order_id as corrected_order_id, 
COALESCE(case 
  when order_id%2 = 1 then lead(item) over(order by order_id) 
  when order_id%2 = 0 then lag(item) over(order by order_id)
end, item) as item
from orders;
