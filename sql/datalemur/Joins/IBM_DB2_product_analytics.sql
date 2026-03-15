-- https://datalemur.com/questions/sql-ibm-db2-product-analytics

with cte as (
-- first step is to filter queries executed specifically in 3rd qtr
SELECT employee_id, count(distinct query_id)
FROM queries 
WHERE extract(MONTH from query_starttime) IN ('7','8','9') 
and extract(YEAR from query_starttime) = '2023'
GROUP BY employee_id
),
cte2 as (
-- now we also need to get those employees who didn't execute any query 
-- cte give us emp_id, count(distinct queries) that emp executed 
select distinct e.employee_id, 0 as count  from employees e
left join cte c
ON e.employee_id = c.employee_id
WHERE c.employee_id IS NULL -- post left join if c.employee_id is NULL then that e.employee_id didn't execute any query 

UNION ALL   -- to combine the results with cte 

SELECT * FROM CTE
)
select count, count(distinct employee_id) 
from cte2
group by count;

;


-- simplified version 

-- step 1 to get emp_id, count(distinct queries) that emp_id executed 
SELECT 
  employee_id, 
  count(distinct query_id) as unique_queries_count
FROM queries 
WHERE 
  extract(MONTH from query_starttime) IN ('7','8','9') 
and extract(YEAR from query_starttime) = '2023'
GROUP BY 
  employee_id
  
-- step2 Now I need to include all employees 
-- so left join employees with queries on emp_id and query_starttime should be in 3rd qtr
SELECT 
  e.employee_id,
  COALESCE(count(distinct q.query_id), 0) as unique_queries
FROM employees e 
LEFT JOIN queries q 
  ON e.employee_id = q.employee_id
  and extract(MONTH from q.query_starttime) IN ('7','8','9') 
  and extract(YEAR from q.query_starttime) = '2023'
GROUP BY 
  e.employee_id
  
  
-- step 3: wrap this in a cte 
with employee_queries as (
SELECT 
  e.employee_id,
  COALESCE(count(distinct q.query_id), 0) as unique_queries
FROM employees e 
LEFT JOIN queries q 
  ON e.employee_id = q.employee_id
  and extract(MONTH from q.query_starttime) IN ('7','8','9') 
  and extract(YEAR from q.query_starttime) = '2023'
GROUP BY 
  e.employee_id
)

SELECT unique_queries, count(employee_id)
FROM employee_queries
GROUP BY unique_queries
ORDER BY unique_queries

