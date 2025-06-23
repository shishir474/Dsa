-- calculate rolling avg over the last 3 days for each USER
-- output user_id, date, rolling_average

-- 🧮 Example from your data (user_id = 111):
-- tweet_date	tweet_count	3-day rolling average
-- 06/01/2022	2	2.00 (only 1 day data)
-- 06/02/2022	1	(2+1)/2 = 1.50
-- 06/03/2022	3	(2+1+3)/3 = 2.00
-- 06/04/2022	4	(1+3+4)/3 = 2.67
-- 06/05/2022	5	(3+4+5)/3 = 4.00

-- ✅ Note: For early rows (less than 3 days available), average is taken using as many days as are present.


-- 📌 Explanation of window clause:
-- PARTITION BY user_id → compute rolling average per user

-- ORDER BY tweet_date → respect the order of tweets over time

-- ROWS BETWEEN 2 PRECEDING AND CURRENT ROW → includes current row and 2 before it (i.e., 3-day window)


-- solution query
SELECT user_id, tweet_date, round(avg(tweet_count) over(
      partition by user_id order by tweet_date rows between 2 PRECEDING and CURRENT ROW), 2) rolling_avg_3d
FROM tweets;




-- some play around stuff

-- calculating running sum for each user
select *, sum(tweet_count) over(partition by user_id order by tweet_date) 
from tweets;

-- calculating running sum over past 3 days for each user
select *, sum(tweet_count) over(partition by user_id order by tweet_date rows between 2 PRECEDING and CURRENT ROW) 
from tweets;

-- running average 
select *, avg(tweet_count) over(partition by user_id order by tweet_date) 
from tweets;


-- teaches how to calculate cumulative sum and cumulative sum over last 3 days