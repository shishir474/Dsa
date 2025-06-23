-- not the correct approach. Below is the correct solution
-- first join with user_id to get the age_group
-- and then group by on age_group,activity_type and aggregate time_spent

-- This query works fine, it aggregates the time_spent at age_bucket and activity_type level
SELECT 
ab.age_bucket, a.activity_type, sum(time_spent) as time_spent
FROM activities a
inner JOIN
age_breakdown ab on a.user_id = ab.user_id
group by ab.age_bucket, a.activity_type;

-- now let's say I want to calculate sum(time_spent) over each window of age_bucket -- hence used window function sum()
-- requirement of group by clause is all the columns in select clause that are not aggregated must be mentioned in group by 
-- and since we are using sum(time_spent) as aggregation and window function, we'll have to aggregate the window function hence using sum(sum())
with cte as (
SELECT 
    ab.age_bucket, 
    a.activity_type, 
    sum(time_spent) as time_spent, 
    sum(sum(time_spent)) over(partition by age_bucket)
FROM activities a
inner JOIN
age_breakdown ab on a.user_id = ab.user_id
group by ab.age_bucket, a.activity_type
)
select * from cte;


-- ACTUAL SOLUTION
-- for each age_bucket, find send_total and open_total and then calculate percent in next step
with cte as (
SELECT 
ab.age_bucket, 
sum(case when activity_type = 'send' then time_spent else 0 end) as send_total,
sum(case when activity_type = 'open' then time_spent else 0 end) as open_total
FROM activities a
inner JOIN
age_breakdown ab on a.user_id = ab.user_id
group by ab.age_bucket
)
select age_bucket, round(1.0 * send_total/(send_total + open_total) * 100, 2) as send_perc,  round(1.0 * open_total/(send_total + open_total) * 100, 2) as open_perc
from cte;

-- teaches how to use window function with group by clause