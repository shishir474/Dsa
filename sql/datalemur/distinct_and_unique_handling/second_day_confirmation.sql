-- 2 requirements
-- users need to confirm on the second DAY -- so datediff(t.action_date, e.signup_date) = 1
-- The texts received must say 'Confirmed'

-- first step : join emails & texts table * interpret the results

-- note: dateadd(day, 1 , current_date) function is available in postgresql 
-- use + INTERVAL 'n units' instead.


-- we need to fetch unique user IDs
SELECT DISTINCT e.user_id
FROM emails e
INNER JOIN texts t 
  ON e.email_id = t.email_id
WHERE e.signup_date + INTERVAL '1 day' = t.action_date
AND t.signup_action = 'Confirmed'