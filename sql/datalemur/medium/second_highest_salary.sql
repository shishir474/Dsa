
-- SOLUTION 1:

with salary_ranking as (
SELECT *, row_number() over(order by salary desc) rn
FROM employee
)
select salary from salary_ranking 
where rn = 2;  -- second highest salary

-- -- why row_number() here? 
--   -- row_number() will always generate unique ranks even if there are duplicates which is what question wants
-- -- dense_rank() and rank() will generate same ranks for duplicates salaries records and if we filter on rn = 2, we might get more than 1 record, which is not wanted as per the problem statement


-- -- rank() -- assigns same rank if tie and skips those many records which has same salary
-- -- dense_rank() -- assigns same rank if tie but does not skip the next rank even if duplicates are there
-- -- row_number() -- always assign unique ranks even if there is a duplicate. Randomly orders the record in case of duplicates

-- -- so the only difference is in case of rank() and dense_rank() iff we have duplicates, both will assign same ranks, but rank() skips the next ranks, but dense_rank() does not SKIP
-- -- whereas row_nunmber only assigns unique rank and in case of duplicates randomly orders the record


-- SOLUTION 2:
select salary from employee
order by salary desc      -- arranges the salary in descending order and then use offset x to skip x records from the top
offset 1 limit 1;


-- teaches about offset that specifies the no of row to skip