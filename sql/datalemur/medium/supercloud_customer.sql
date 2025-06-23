-- below query gives the count of distinc prod_catg for each customer.
-- Now I have to compare this count with the count fo disintct prod_catg in products tables and show only those customer_id's whose count matches
-- move the count() to having clause and comapre it with count of disintct prod_catg in products tables
SELECT cc.customer_id,  count(distinct p.product_category)
FROM customer_contracts cc
left join products p on cc.product_id = p.product_id
group by cc.customer_id
order by cc.customer_id


-- Final query
-- returns a list of customer_id's who bought atleast one product from each product category
SELECT cc.customer_id
FROM customer_contracts cc
left join products p on cc.product_id = p.product_id
group by cc.customer_id
having count(distinct p.product_category) = (select count(distinct product_category) from products)
order by cc.customer_id
