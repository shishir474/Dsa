-- across each department you have to find top 3 employees with higest salaries

-- used dense_rank() bcoz dense_rank() assign consecutive ranks and ensures that ties don't create gaps in the ranking SEQUENCE
-- whereas rank() might leave gaps when there are ties 

with cte as (
  SELECT *, DENSE_RANK() OVER(PARTITION BY department_id ORDER BY salary DESC) rn
FROM employee
)
SELECT d.department_name, c.name, c.salary FROM cte c
LEFT JOIN department d 
  ON c.department_id = d.department_id
WHERE rn <= 3
ORDER BY 
  d.department_name,
  c.salary desc,
  c.name;

-- the questions asks us to handle ties -- we need to assign same rank to employees with same salary and there should be no gaps - HENCE dense_rank()
-- unique ranks/sequential no -- use row_number()
-- handle ties but leave gaps -- use rank() (very rarely used)

-- One imp point to note is with window functions we cannot use WHERE clause to filter the results based on the window function output
-- we have to use a CTE or subquery to first compute the window function and then filter on it