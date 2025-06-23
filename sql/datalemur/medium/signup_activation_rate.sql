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
SELECT  round(1.0*count(t.email_id)/count(e.email_id), 2) as confirm_rate
FROM emails e 
left join texts t on e.email_id = t.email_id and t.signup_action = 'Confirmed'


-- Why LEFT JOIN is Necessary in this Query?

-- Now, it's important to note that not every email_id in the emails table will have a matching value in the texts table, and this is where the LEFT JOIN comes into play.

-- When we perform a LEFT JOIN, all the rows from the left table (emails in this case) are returned along with matching rows from the right table (texts in this case). If there is no match for a particular row in the right table, then the columns from the right table will be NULL.

-- If we were to use an INNER JOIN, only the matching rows between the two tables would be returned, effectively filtering out any email_id values from the emails table that do not have a corresponding match in the texts table.

