-- given a customer's sales table containing product_id, sales across 3 years. 
According to paretos principle roughly 20% of the products gives you 80% of the sales. We have to find these products 

--first aggregate the sale for each product and also calculate what is the 80% of total sale value

-- first calculate aggregated sales for each product and then apply window function in the next cte to calculate the running_sales
select sum(sales)*0.8 from orders;  

select product_id, sum(sales)
from orders
group by product_id

-- Now I have to calculate running_sales or (cumulative sales) on the above result
with product_wise_sales as (
    select product_id, sum(sales) as product_sales
    from orders
    group by product_id
),
calc_sales(
    select product_id,
        product_sales,  -- aggregated product sales in prev cte
        sum(product_sales) over(order by product_sales desc rows between unbounded preceding and 0 preceding) as running_sales,  -- running_total
        0.8*sum(product_sales) over() as total_sales -- 80% of total_sales
    from product_wise_sales
)
select * from calc_sales where running_sales <= total_sales;        -- gives you list of products that generates 80% of sales 