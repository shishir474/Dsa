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


EXTRACT()

Syntax
EXTRACT( <date_or_time_part> FROM <date_time_or_timestamp_expr> )
EXTRACT( <date_or_time_part> , <date_time_or_timestamp_expr> )

Extracts the specified date or time part from a date, time, or timestamp.

Tip

To extract the date from a timestamp, use the TO_DATE function.

-- DATE_PART() function is primarily used to extracts specific parts from date or timestamp values.
-- The following are some commonly used date and time parts that can be extracted using the DATE_PART() function:

-- NOTE: DATE_PART() and EXTRACT() functions are functionally equivalent and can be used interchangeably to achieve the same result.

Date parts

day, week, month, quarter, year, dayofweek, dayofyear, weekiso, dayofweek_iso


Time parts

hour, minute, second, millisecond, microsecond, nanosecond


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


DATE_TRUNC()

-- Truncates a DATE, TIME, or TIMESTAMP value to the specified precision. 
-- For example, truncating a timestamp down to the quarter returns the timestamp corresponding to midnight of the first day of the original timestamp’s quarter.

-- Truncation is not the same as extraction. For example:

--     Truncating a timestamp down to the quarter using this function returns the timestamp corresponding to midnight of the first day of the quarter for the input timestamp.

--     Extracting the quarter date part from a timestamp using the EXTRACT function returns the quarter number of the year in the timestamp.


Syntax
DATE_TRUNC( <date_or_time_part>, <date_or_time_expr> )


SELECT mydate AS "DATE",
       DATE_TRUNC('year', mydate) AS "TRUNCATED TO YEAR",
       DATE_TRUNC('month', mydate) AS "TRUNCATED TO MONTH",
       DATE_TRUNC('week', mydate) AS "TRUNCATED TO WEEK",
       DATE_TRUNC('day', mydate) AS "TRUNCATED TO DAY"
  FROM test_date_trunc;

+------------+-------------------+--------------------+-------------------+------------------+
| DATE       | TRUNCATED TO YEAR | TRUNCATED TO MONTH | TRUNCATED TO WEEK | TRUNCATED TO DAY |
|------------+-------------------+--------------------+-------------------+------------------|
| 2024-05-09 | 2024-01-01        | 2024-05-01         | 2024-05-06        | 2024-05-09       |
+------------+-------------------+--------------------+-------------------+------------------+

SELECT mytimestamp AS "TIMESTAMP",
       DATE_TRUNC('hour', mytimestamp) AS "TRUNCATED TO HOUR",
       DATE_TRUNC('minute', mytimestamp) AS "TRUNCATED TO MINUTE",
       DATE_TRUNC('second', mytimestamp) AS "TRUNCATED TO SECOND"
  FROM test_date_trunc;

+-------------------------+-------------------------+-------------------------+-------------------------+
| TIMESTAMP               | TRUNCATED TO HOUR       | TRUNCATED TO MINUTE     | TRUNCATED TO SECOND     |
|-------------------------+-------------------------+-------------------------+-------------------------|
| 2024-05-09 08:50:57.891 | 2024-05-09 08:00:00.000 | 2024-05-09 08:50:00.000 | 2024-05-09 08:50:57.000 |
+-------------------------+-------------------------+-------------------------+-------------------------+


-- Contrast the DATE_TRUNC function with the EXTRACT function:

SELECT DATE_TRUNC('quarter', mytimestamp) AS "TRUNCATED", -- brings down to the first day of the quarter
       EXTRACT('quarter', mytimestamp) AS "EXTRACTED"   -- extracts the quarter number of the fiscal year
  FROM test_date_trunc;
+-------------------------+-----------+
| TRUNCATED               | EXTRACTED |
|-------------------------+-----------|
| 2024-04-01 00:00:00.000 |         2 |
+-------------------------+-----------+


Core date functions 

DATEADD

DATEDIFF

DATE_PART / EXTRACT

DATE_TRUNC

LAST_DAY




Supporing date functions 

Dayname()

    Syntax
    DAYNAME( <date_or_timestamp_expr> )

    Extracts the three-letter day-of-week name from the specified date or timestamp.

    SELECT DAYNAME(TO_DATE('2024-04-01')) AS DAY;
    +-----+
    | DAY |
    |-----|
    | Mon |
    +-----+


MONTHNAME
    Returns the three-letter month name for the specified date or timestamp.

    Syntax
    MONTHNAME( <date_or_timestamp_expr> )

    SELECT MONTHNAME(TO_DATE('2025-01-01')) AS month;
    +-------+
    | MONTH |
    |-------|
    | Jan   |
    +-------+


LAST_DAY()

Returns the last day of the specified date part for a date or timestamp.

Syntax:
LAST_DAY( <date_or_timetamp_expr> [ , <date_part> ] )

By default returns the last day of the month.

SELECT TO_DATE('2025-05-08T23:39:20.123-07:00') AS "DATE",
       LAST_DAY("DATE") AS "LAST DAY OF MONTH";
+------------+-------------------+
| DATE       | LAST DAY OF MONTH |
|------------+-------------------|
| 2025-05-08 | 2025-05-31        |
+------------+-------------------+

-- passed the date part as year in second argument - this gives us the last day of the year
SELECT TO_DATE('2024-05-08T23:39:20.123-07:00') AS "DATE",
       LAST_DAY("DATE", 'year') AS "LAST DAY OF YEAR";


-- some supporting functions -- can be implemented via extract()
YEAR(), MONTH(), WEEK(), DAY()

NOTE: You can use these functions or use extract/date_part functions to get the same results.
extract(year from TO_DATE('2024-04-08'))  == YEAR(TO_DATE('2024-04-08'))
extract(month from TO_DATE('2024-04-08')) == MONTH(TO_DATE('2024-04-08'))
extract(week from TO_DATE('2024-04-08'))  == WEEK(TO_DATE('2024-04-08'))
extract(day from TO_DATE('2024-04-08'))   == DAY(TO_DATE('2024-04-08')) 





-- examples

select current_date(), current_date, 
    sysdate(), -- follows utc time zone
    current_timestamp(), -- follows utc time zone
    dateadd(day, 7, current_date) as next_wk_dt,  dayname(dateadd(day, 7, current_date)) as day_nm,
    dateadd(month, 1, current_date) as next_mon_dt, monthname(dateadd(month, 1, current_date)) as mon_nm,
    datediff(day, current_date, dateadd(week, 1, current_date)) as diff_days,
    extract(year from current_date),
    extract(month from current_date), monthname(current_date),
    extract(quarter from current_date),
    extract(week from current_date),
    extract(day from current_date), -- gives the day of month
    extract(dayofweek from current_date),
    extract(dayofyear from current_date),
    ;


-- you can pass date in any format (yyyy-mm-dd , mm-dd-yyyy , dd-mm-yyyy etc) but make sure to specify the correct format in the second argument
-- default format is yyyy-mm-dd
SELECT DATEDIFF(year, current_date, TO_DATE('14-06-2002', 'dd-mm-yyyy' ));
-- NOTE: 'dd-mm-yyyy' string is case insensitive - you can pass in uppercase as well

SELECT  TO_DATE('06-14-2002', 'mm-dd-yyyy' );
SELECT  TO_DATE('14-06-2002', 'dd-mm-yyyy' );