-- https://www.youtube.com/watch?v=9Kh7EnZlhUg&list=PLBTZqjSKn0IeKBQDjLmzisazhqQy4iGkb&index=13&ab_channel=AnkitBansal
create table orders
(
order_id int,
customer_id int,
product_id int,
);

insert into orders VALUES 
(1, 1, 1),
(1, 1, 2),
(1, 1, 3),
(2, 2, 1),
(2, 2, 2),
(2, 2, 4),
(3, 1, 5);

create table products (
id int,
name varchar(10)
);
insert into products VALUES 
(1, 'A'),
(2, 'B'),
(3, 'C'),
(4, 'D'),
(5, 'E');


select * from orders o1
inner join orders o2 on o1.order_id = o2.order_id
where o1.order_id = 1;      -- let's just do it for 1 order id, we can remove this filter later on 

select * from products;  

-- uses the concept of self join to generate all possible pairs
-- good candidate of self join, since I have to create pairs within the same table
 select o1.order_id, o1.customer_id, o1.product_id as p1, o2.product_id as p2
    from orders o1
    inner join orders o2 on o1.order_id =  o2.order_id
    where o1.product_id != o2.product_id and o1.product_id < o2.product_id;

    
select o1.product_id as p1, o2.product_id as p2, count(distinct o1.customer_id) as purchase_freq
    from orders o1
    inner join orders o2 on o1.order_id =  o2.order_id
    where o1.product_id != o2.product_id and o1.product_id < o2.product_id
    group by o1.product_id , o2.product_id;


    -- join with the products table to get the name
select pr1.name as p1, pr2.name as p2, count(distinct o1.customer_id) as purchase_freq
from orders o1
inner join orders o2 on o1.order_id =  o2.order_id
inner join products pr1 on pr1.id = o1.product_id 
inner join products pr2 on pr2.id = o2.product_id 
where o1.product_id != o2.product_id and o1.product_id < o2.product_id
group by pr1.name, pr2.name;


select concat(pr1.name, ' ', pr2.name) as product_pair, count(distinct o1.customer_id) as purchase_freq
from orders o1
inner join orders o2 on o1.order_id =  o2.order_id
inner join products pr1 on pr1.id = o1.product_id 
inner join products pr2 on pr2.id = o2.product_id 
where o1.product_id != o2.product_id and o1.product_id < o2.product_id
group by pr1.name, pr2.name;