select * from orders;
select * from users;
select * from items;

-- find for each seller, whether the brand of the second item(by date) they sold is their favourite brand
-- if a seller sold less than 2 items, report ans for that seller as no

-- lets first filter out the second item from orders for each seller
-- users will be the driving table. Performing left join to get all the sellers
with ranked_orders as (
  select o.*, 	
rank() over(partition by seller_id order by order_date) as rn
from orders o
)
select ro.*, i.item_brand, u.favorite_brand,
case when item_brand = favorite_brand then 'yes' else 'no' end as second_item_fav
from ranked_orders ro
inner join items i on i.item_id = ro.item_id
inner join users u on u.user_id = ro.seller_id
where rn = 2;

-- these query contains the 2nd orders for each seller, but not all sellers. Users table will be our driving table. Hence we need to do left join with users table

with ranked_orders as (
  select o.*, 	
rank() over(partition by seller_id order by order_date) as rn
from orders o
)

select u.user_id, ro.*, i.item_brand, u.favorite_brand,
case when item_brand = favorite_brand then 'yes' else 'no' end as second_item_fav
from users u
left join ranked_orders ro on u.user_id = ro.seller_id and rn = 2 		-- this way you will be able to get the record for user 1
left join items i on i.item_id = ro.item_id

-- IMPORTANT
-- instead of applying filter using the where rn = 2 in the above cte this will give not give you user_id = 1 record
-- To get that do left join and apply condition on joining on user_id and rn = 2. So if there is a match you will get the item brand, else it will be null






