-- across each department you have to find top 3 employees with higest salaries
with cte as (
SELECT e.*, dense_rank() over(partition by e.department_id order by e.salary desc) as rn, d.department_name
FROM employee e
inner join department d on e.department_id = d.department_id
)
select department_name,  name,  salary from cte 
where rn <= 3 
order by department_name asc, salary desc, name asc;


-- used dense_rank() bcoz dense_rank() assign consecutive ranks and ensures that ties don't create gaps in the ranking SEQUENCE
-- whereas rank() might leave gaps when there are ties 
