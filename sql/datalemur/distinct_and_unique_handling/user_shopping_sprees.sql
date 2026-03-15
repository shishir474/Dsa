-- I essentially need to find users who have went on a shopping spree (which is defined as 3 or more consecutive days of shopping)

-- 2 self joins -- we want to check for consecutive days within the same table ( hence self join )

select distinct t1.user_id
from transactions t1 
join transactions t2 
  ON t1.user_id = t2.user_id 
  and t1.transaction_date + INTERVAL '1 day' = t2.transaction_date
join transactions t3
  ON t2.user_id = t3.user_id 
  and t2.transaction_date + INTERVAL '1 day' = t3.transaction_date
ORDER BY 1