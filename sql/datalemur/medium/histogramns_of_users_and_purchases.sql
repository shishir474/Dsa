-- SELECT user_id, max(transaction_date) as transaction_date, count(distinct product_id) as purchase_count
-- FROM user_transactions
-- group by user_id;

-- question is not cleear. We want to find details around the latest transaction performed by each user, like the user_id, latest_txn_date and the no of products bought
-- strategy: 

-- get the latest txn's for each user. Now there can be 2 or more entries in the table for the latest txn. We need all those entries, hence we'll have to use rank() over(partition by user_id order by transactoin_date desc)
-- rank() will assign rn = 1 for all the rows associated with the latest_txn
-- row_number() assigns different ranks 

-- I just want to get the records correspondint to the latest transaction_date, which mean rank = 1
-- if I use row_number it will always give unique ranks, 2 rows with the latest transactoin-date will be ranked 1 and 2 respectiely
-- but we want both the rows corresponding to latest transaction date. and since we only need to filter for rank = 1, we can either use rank() or dense_rank()
-- they both handle ties, only diff is in rank() the rankings are not consecutive whereas in dense_rank() they are 
with ranked_transactions as (
select *, rank() over(partition by user_id order by transaction_date desc) rn 
from user_transactions
)
select transaction_date, user_id, count(distinct product_id)
from ranked_transactions where rn = 1
group by transaction_date, user_id
order by transaction_date, user_id;