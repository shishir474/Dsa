-- You are given a table with timestamped measurement values collected multiple times per day by a Google sensor. For each day, you need to:
-- Assign an order to the measurements based on the time they were taken.
-- Sum the values from odd-numbered positions (1st, 3rd, 5th, etc.).
-- Sum the values from even-numbered positions (2nd, 4th, 6th, etc.).
-- Output both sums in two separate columns for each day.


-- FINAL QUERY
-- Window functions can't be referenced in the same SELECT clause directly in other expressions like rn in your CASE statements.
with ranked_cte as (
SELECT *,cast(measurement_time as DATE) as measurement_day,
  row_number() over(partition by cast(measurement_time as DATE) order by measurement_time asc) rn
FROM measurements
)
select measurement_day, 
sum(case when rn%2 = 1 then measurement_value else 0 end) as odd_sum,
sum(case when rn%2 = 0 then measurement_value else 0 end) as even_sum
from ranked_cte
group by measurement_day;

-- learnings 
--1. how to extract/get date from timestamp -- simple just cast the timestamp column to DATE
    --  cast(transactoin_date as DATE) or transaction_date::DATE
    -- x::DATE also performs typecasting 

-- if you want to get year,month,day values, use extract(year from transaction_date) 

-- I was able to assign row_number within each group properly, but the next step was to calculate even and odd sum within each group
-- for this we can use sum(case when rn%2 == 0 then value else 0 end) --> this will give even sum
-- similarly we can get odd sum. but note that we cannot derive row_number and calculate the conditional sum in the same select clause 
-- hence used a cte. ranked_cte calculates the row_number within each day(we arrange record based on timestamp value)
-- and the aggregate the value at day level to get final output