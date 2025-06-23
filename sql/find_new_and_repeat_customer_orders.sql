create table customer_orders (
order_id integer,
customer_id integer,
order_date date,
order_amount integer
);

insert into customer_orders values(1,100,'2022-01-01',2000),(2,200,'2022-01-01',2500),(3,300,'2022-01-01',2100)
,(4,100,'2022-01-02',2000),(5,400,'2022-01-02',2200),(6,500,'2022-01-02',2700)
,(7,100,'2022-01-03',3000),(8,400,'2022-01-03',1000),(9,600,'2022-01-03',3000);

-- order_date, no_of_new_customers, no_of_repeat_customers on this day --> this is what we need to find

-- first find the first order date of each customer. If the first_order_date is same as order date, then it is a new customer else it is a repeat customer

with first_visit as (
    select customer_id, min(order_date) as first_visit_date
    from customer_orders
    group by customer_id
),
visit_flag as (
  select co.*, fv.first_visit_date,
  case when order_date == first_visit_date then 1 else 0 end as new_cust_flag,
  case when order_date != first_visit_date then 1 else 0 end as repeat_cust_flag
  from first_visit fv inner join customer_orders co on fv.customer_id = co.customer_id)
  
  select order_date, sum(new_cust_flag) as new_customers, sum(repeat_cust_flag) as repeat_customers
  from visit_flag
  group by order_date
  order by order_date;


-- we can reduce the query (use sum with case expressions)
-- optimised version 
with first_visit as (
select customer_id, min(order_date) as first_visit_date
from customer_orders
  group by customer_id)
  
select co.order_date, 
  sum(case when order_date == first_visit_date then 1 else 0 end) as new_customers,
  sum(case when order_date != first_visit_date then 1 else 0 end) as repeat_customers
  from first_visit fv inner join customer_orders co on fv.customer_id = co.customer_id
  group by co.order_date;



-- extension problem: also find the order amount of new customer and repeat customer on each day
-- order_date, no_of_new_customers, no_of_repeat_customers on this day, order_amount by new_cust, order_amount by repeat_customers --> this is what we need to find

-- first find the first order date of each customer. If the first_order_date is same as order date, then it is a new customer else it is a repeat customer

with first_visit as (
  select customer_id, min(order_date) as first_visit_date
  from customer_orders
  group by customer_id
),
visit_flag as (
  select co.order_date, 
    sum(case when order_date == first_visit_date then 1 else 0 end) as new_customer_flag, -- no of new customer
    sum(case when order_date != first_visit_date then 1 else 0 end) as repeat_customer_flag,	-- no of repeat customers
    sum(case when order_date == first_visit_date then order_amount else 0 end) as new_customer_total, -- order_amount of new customers
    sum(case when order_date != first_visit_date then order_amount else 0 end) as repeat_customer_total, -- order amount of repeat customers
    sum(co.order_amount)    -- total order amount of this day
  from first_visit fv inner join customer_orders co on fv.customer_id = co.customer_id
  group by 1
)
select * from visit_flag;