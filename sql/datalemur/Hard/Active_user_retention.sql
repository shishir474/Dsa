-- The objective is to find monthly active users who were also active in the previous month

-- step1: find users who were active in the prev month
-- will create 2 aliases last_month, curr_month 2 table aliases

-- In order to find users who were acive in the prev month 
    1. Their user_ids should match between curr_month and last_month aliases
    2. extract(month from last_month.event_date) = 
          extract(month from curr_month.event_date - INTERVAL '1 month')

    In projection - select users_ids 

    Then in the outer query which corresponds to curr_month - we will filter for a specific month ( say July 2022) 
    and use EXISTS operator to check if the user exists in the subquery ( which corresponds to last_month alias)


-- EXISTS operator is used to check for users in the curr month who also exist in the subquery, 
-- which represents the active users in the previous month 


-- this is the correct version and works dynamically based on the filter 

select 
    extract(month from curr_month.event_date) as mth,
    count(distinct curr_month.user_id) as monthly_active_users
from user_actions as curr_month
where 
    EXISTS (
        select last_month.user_id
        from user_actions as last_month 
        where
        last_month.user_id = curr_month.user_id 
        AND extract(month from last_month.event_date) = 
            extract(month from curr_month.event_date - INTERVAL '1 month') 
    )
    and extract(month from curr_month.event_date) = 7
    and extract(year from curr_month.event_date) = 2022

GROUP BY 
    extract(month from curr_month.event_date) 
;

    