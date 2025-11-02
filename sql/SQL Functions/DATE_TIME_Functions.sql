DATE_FROM_PARTS

Creates a date from individual numeric components that represent the year, month, and day of the month.




DATE_PART()
Extracts the specified date or time part from a date, time, or timestamp.

Alternatives:
    EXTRACT , HOUR / MINUTE / SECOND , YEAR* / DAY* / WEEK* / MONTH / QUARTER

-- both the below syntaxes are supported
-- Just make sure that you are passing date or timestamp expression
Syntax
DATE_PART( <date_or_time_part> , <date_time_or_timestamp_expr> )
DATE_PART( <date_or_time_part> FROM <date_time_or_timestamp_expr> )


-- DATE_PART() function is primarily used to extracts specific parts from date or timestamp values.
-- The following are some commonly used date and time parts that can be extracted using the DATE_PART() function:

Date parts
1. year
2. month 
3. day 
4. dayofweek
5. dayofweek_iso
6. dayofyear
7. week
8. weekiso
9. quarter

Time parts
1. hour
2. minute
3. second
4. millisecond
5. microsecond
6. nanosecond

-- NOTE: The behavior of week-related functions in Snowflake is controlled by the WEEK_START and WEEK_OF_YEAR_POLICY session parameters.


SELECT DATE_PART(quarter, '2024-04-08'::DATE);
+----------------------------------------+
| DATE_PART(QUARTER, '2024-04-08'::DATE) |
|----------------------------------------|
|                                      2 |
+----------------------------------------+


-- NOTE: its not recommended to use the alias in the same select clause. In some engines it might support this, but we should always try to use the original expressions instead directly in the function calls
-- Best practice
SELECT 
  TO_TIMESTAMP('2024-04-08T23:39:20.123-07:00') AS "TIME_STAMP1",
  DATE_PART(year, TO_TIMESTAMP('2024-04-08T23:39:20.123-07:00')) AS "EXTRACTED YEAR";

+-------------------------+----------------+
| TIME_STAMP1             | EXTRACTED YEAR |
|-------------------------+----------------|
| 2024-04-08 23:39:20.123 |           2024 |
+-------------------------+----------------+


common date functions 

DATEADD

DATEDIFF

DATE_PART

DATE_TRUNC

LAST_DAY