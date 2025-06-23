-- write a query to return the date of the nth sunday 

select case when dayofweek(TO_DATE('2022-01-01')) = 7 then dateadd(week,2,TO_DATE('2022-01-02')) -- if it's a sunday
            else dateadd(week,1,dateadd(day, 7 - dayofweek(TO_DATE('2022-01-01')), TO_DATE('2022-01-01')))
        end as nth_sunday_date;


-- reviit ;; try to use only the core functions datepart and dateadd
-- https://www.youtube.com/watch?v=6XQAokp4UCs&list=PLBTZqjSKn0IeKBQDjLmzisazhqQy4iGkb&index=7&ab_channel=AnkitBansal