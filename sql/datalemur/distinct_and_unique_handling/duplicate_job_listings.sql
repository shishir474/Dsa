-- objective is to count the number of companies which have duplicate job listings
-- duplicate job listing is defined as having same title and description

count(distinct title, description) --> This is not valid syntax in SQL

COUNT(DISTINCT ...) only accepts one expression.

count(distinct concat(title, '-', description)) --> This is valid syntax
or 
count(distinct (title,description)) --> also valid


-- use concat if you want to pass more than 1 column to count(distinct ...)

-- logic : if count of all job listings mathces count of distinct job listings for a company -- then there are no duplicates


with cte as (
  select company_id, case when count(distinct concat(title, '-', description)) != count(*) then 1 else 0 end as dup_flg
  -- count(*) as total_jobs, count(distinct concat(title, '-' description)) 
  from job_listings
  group by 1
)
select sum(dup_flg) from cte;