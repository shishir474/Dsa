-- we have to find the activation rate of the specified users in the emails table. 
-- find the activation rate of specific users in the emails table which may not include all users that could potentially be found in the texts table.
-- hence using left join
SELECT  *
FROM emails e 
left join texts t on e.email_id = t.email_id 
order by e.email_id


-- we'll only keep those users who succesfully signed up and received a confirmed text
SELECT  *
FROM emails e 
left join texts t on e.email_id = t.email_id and t.signup_action = 'Confirmed'

-- what adding conditions in join means
-- in left join --> it will return all the rows from the left table(emails in our case)
-- where there is a match, it will get values from the right table, and if there is no match for a particular row, then the columns from the right table would be NULL
-- for matching records, we are then filtering on signup_action = 'Confirmed'
-- so the final output will contain all matching rows with signup-action = 'Confirmed' and non matching rows



-- Signup Activation Rate = Number of users who confirmed their accounts / Number of users in the emails table

-- Final Query
-- count(t.email_id) will give us the number of users who confirmed their accounts
-- count(e.email_id) will give us the total number of users in the emails table
-- multiplying by 1.0 to avoid integer division
-- rounding off to 2 decimal places

SELECT  round(1.0*count(t.email_id)/count(e.email_id), 2) as confirm_rate
FROM emails e 
left join texts t on e.email_id = t.email_id and t.signup_action = 'Confirmed'


-- Why LEFT JOIN is Necessary in this Query?

-- Now, it's important to note that not every email_id in the emails table will have a matching value in the texts table, and this is where the LEFT JOIN comes into play.

-- When we perform a LEFT JOIN, all the rows from the left table (emails in this case) are returned along with matching rows from the right table (texts in this case). If there is no match for a particular row in the right table, then the columns from the right table will be NULL.

-- If we were to use an INNER JOIN, only the matching rows between the two tables would be returned, effectively filtering out any email_id values from the emails table that do not have a corresponding match in the texts table.


-- Solution on 2025-11-04

-- left join will produce 1:M rows for an email_id. I just need to check whether there exists any Confirmed status amongst all those many mappings for a given email id 
-- Using case I assigned 1/0 depending on the status & then used sum() to group all those many rows into 1
-- Once this grouping of mnay rows is done -- we know for sure if a user has activated his account or not using this flag 
-- activation rate : count_of_activated_users / total_number_of_users

with cte as (
  SELECT e.*, case when t.signup_action = 'Confirmed' then 1 else 0 end as flg
-- t.text_id, t.signup_action
FROM emails e
LEFT JOIN texts t 
  ON e.email_id = t.email_id 
GROUP BY 
  1,2,3
ORDER BY 
  e.user_id, e.email_id
)
select round(sum(flg) / count(*), 2) from cte 


    email_id user_id	signup_date	        flg
    433    	1052	2022-07-09 00:00:00	    0
    499	    2500	2022-08-08 00:00:00	    0
    555	    6633	2022-08-09 00:00:00	    0
    236	    6950	2022-07-01 00:00:00	    1
    125	    7771	2022-06-14 00:00:00	    1
    450	    8963	2022-08-02 00:00:00	    0