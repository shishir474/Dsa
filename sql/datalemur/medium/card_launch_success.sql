-- calculate the issued_amount for each category of card in their launch month. So essentially first I've to get
-- records for each card category for their launch month that can easily be done using rank() = 1
-- rank() bcoz there can be multiple rows for the same card in its launch month 
-- once you have rank = 1 data for all categories of card, just aggregate the issued amount
with ranked_monthly_cards as (
SELECT *, rank() over(partition by card_name order by issue_year, issue_month) rn
FROM monthly_cards_issued
)
select card_name, sum(issued_amount) as issued_amount
from ranked_monthly_cards where rn = 1
group by card_name
order by issued_amount desc;

select *, make_date(issue_year, issue_month, 1) from monthly_cards_issued;


-- All the date time functions and operators are present in the below doc
-- https://www.postgresql.org/docs/current/functions-datetime.html

select current_date, CURRENT_TIME, CURRENT_TIMESTAMP;