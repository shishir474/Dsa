https://docs.snowflake.com/en/user-guide/functions-window-using
https://docs.snowflake.com/en/sql-reference/functions-window-syntax

Read this 


Window Functions

General Functions 

SUM( DISTINCT <expr> ) OVER([ PARTITION BY <expr2> ] [ ORDER BY <expr3> [ ASC | DESC ] [ <window_frame> ] ])
AVG( [ DISTINCT ] <expr1> ) OVER( [ PARTITION BY <expr2> ] [ ORDER BY <expr3> [ ASC | DESC ] [ <window_frame> ] ])
COUNT( [ DISTINCT ] <expr1> [ , <expr2> ... ] ) OVER( [ PARTITION BY <expr2> ] [ ORDER BY <expr3> [ ASC | DESC ] [ <window_frame> ] ])  
MIN(<expr> ) OVER([ PARTITION BY <expr2> ] [ ORDER BY <expr3> [ ASC | DESC ] [ <window_frame> ] ])
MAX(<expr> ) OVER([ PARTITION BY <expr2> ] [ ORDER BY <expr3> [ ASC | DESC ] [ <window_frame> ] ]) 

default value of window_frame is: RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW


Ranking Functions

-- used to assign rank within a partition
RANK() OVER( [PARTITION BY <expr1>] ORDER BY <expr2> [ASC | DESC ] [ <window_frame> ] )
DENSE_RANK() OVER( [PARTITION BY <expr1>] ORDER BY <expr2> [ASC | DESC ] [ <window_frame> ] )

-- used to assign unique sequential numbers to rows within a partition
ROW_NUMBER() OVER( [PARTITION BY <expr1,>] ORDER BY <expr2> [ASC | DESC ] [ <window_frame> ] )

-- used to retrieve specific values from ordered set of rows within a partition
NTH_VALUE(<col_expr>, <n>) OVER( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] [ <window_frame> ] )

-- used to retrieve first and last values from ordered set of rows within a partition
FIRST_VALUE(<col_expr>) OVER( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] [ <window_frame> ])
LAST_VALUE(<col_expr>) OVER( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] [ <window_frame> ])

-- used to retrieve values from subsequent or preceding rows within a partition
LEAD(<col_expr>, <offset>, <default>) OVER( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] [ <window_frame> ])
LAG(<col_expr>, <offset>, <default>) OVER( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] [ <window_frame> ])

-- used to divide ordered data set into specified number of buckets
-- constant value specifies number of buckets
NTILE(<constant_value>) OVER([ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] [ <window_frame> ])



DENSE_RANK()

    -- Returns the rank of a value within a group of values, without gaps in the ranks.
    -- The rank value starts at 1 and continues up sequentially.
    -- If two values are the same, they have the same rank.

Syntax
DENSE_RANK() OVER ( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ ASC | DESC ] [ <window_frame> ] )

Arguments
None.

-- The function itself takes no arguments because it returns the rank (relative position) of the current row within the window, which is ordered by <expr2>. 
-- The ordering of the window determines the rank, so there is no need to pass an additional parameter to the DENSE_RANK function.

IMP POINTS ABOUT DENSE_RANK(): 
    1. DENSE_RANK() accepts no arguments because it operates on the ordering of the rows defined by the ORDER BY clause within the OVER() clause.
    2. PARTITION BY clause is optional. If omitted, the function treats all rows in the result set as a single partition.
    3. ORDER BY clause is mandatory as it defines the order of rows within each partition for ranking.
    4. If there are ties, DENSE_RANK assigns the same rank to tied rows and the next rank is the immediate next integer (no gaps).
        This is the main difference between RANK() and DENSE_RANK().
    5. So you will never see gaps in the ranking sequence when using DENSE_RANK(). But you can get multiple rows with the same rank(if there are ties).
    6. Wheareas RANK() can produce gaps in the ranking sequence when there are ties. Also you can get multiple rows with the same rank(if there are ties) - this behaviour remains same in both rank() and dense_rank().
    7. Ties are handled by both RANK() and DENSE_RANK() by assigning the same rank to tied rows. The main difference is in the gaps that are generated in the ranking sequence in case of rank().


-- ranking farmers based on their corn production in bushels

-- notice that: we have not parititoned the data based on any column - so all rows are treated as a single partition
SELECT state, bushels,
        RANK() OVER (ORDER BY bushels DESC),
        DENSE_RANK() OVER (ORDER BY bushels DESC)
    FROM corn_production;
+--------+---------+-------------------------------------+-------------------------------------------+
| STATE  | BUSHELS | RANK() OVER (ORDER BY BUSHELS DESC) | DENSE_RANK() OVER (ORDER BY BUSHELS DESC) |
|--------+---------+-------------------------------------+-------------------------------------------|
| Kansas |     130 |                                   1 |                                         1 |
| Kansas |     120 |                                   2 |                                         2 |
| Iowa   |     110 |                                   3 |                                         3 |
| Iowa   |     100 |                                   4 |                                         4 |
+--------+---------+-------------------------------------+-------------------------------------------+


-- partitioned by state (so within each state ranking will be done separately)
SELECT state, bushels,
        RANK() OVER (PARTITION BY state ORDER BY bushels DESC),
        DENSE_RANK() OVER (PARTITION BY state ORDER BY bushels DESC)
    FROM corn_production;
+--------+---------+--------------------------------------------------------+--------------------------------------------------------------+
| STATE  | BUSHELS | RANK() OVER (PARTITION BY STATE ORDER BY BUSHELS DESC) | DENSE_RANK() OVER (PARTITION BY STATE ORDER BY BUSHELS DESC) |
|--------+---------+--------------------------------------------------------+--------------------------------------------------------------|
| Iowa   |     110 |                                                      1 |                                                            1 |
| Iowa   |     100 |                                                      2 |                                                            2 |
| Kansas |     130 |                                                      1 |                                                            1 |
| Kansas |     120 |                                                      2 |                                                            2 |
+--------+---------+--------------------------------------------------------+--------------------------------------------------------------+

-- handling ties - notice the difference in RANK() and DENSE_RANK() output
-- both functions assign same rank to tied rows, but RANK() leaves gaps in ranking sequence whereas DENSE_RANK() does not leave any gaps
SELECT state, bushels,
        RANK() OVER (ORDER BY bushels DESC),
        DENSE_RANK() OVER (ORDER BY bushels DESC)
    FROM corn_production;
+--------+---------+-------------------------------------+-------------------------------------------+
| STATE  | BUSHELS | RANK() OVER (ORDER BY BUSHELS DESC) | DENSE_RANK() OVER (ORDER BY BUSHELS DESC) |
|--------+---------+-------------------------------------+-------------------------------------------|
| Kansas |     130 |                                   1 |                                         1 |
| Kansas |     120 |                                   2 |                                         2 |
| Iowa   |     110 |                                   3 |                                         3 |
| Iowa   |     110 |                                   3 |                                         3 |
| Iowa   |     100 |                                   5 |                                         4 |
+--------+---------+-------------------------------------+-------------------------------------------+


ROW_NUMBER() 

-- Returns a unique row number for each row within a window partition.
-- The row number starts at 1 and continues up sequentially.

Syntax
ROW_NUMBER() OVER (
  [ PARTITION BY <expr1> [, <expr2> ... ] ]
  ORDER BY <expr3> [ , <expr4> ... ] [ { ASC | DESC } ]
  )

IMP POINTS ABOUT ROW_NUMBER():
    1. Just like DENSE_RANK(), ROW_NUMBER() also takes no arguments because it generates a unique sequential number for each row based on the ordering defined in the ORDER BY clause within the OVER() clause.
    2. Passing PARTITION BY clause is optional. If omitted, all rows are treated as a single partition.
    3. Passing ORDER BY clause is mandatory as it defines the order of rows within each partition for assigning row numbers.

Comparison of RANK(), DENSE_RANK(), and ROW_NUMBER()

Gaps: 
    RANK() can produce gaps in the ranking sequence when there are ties.
    DENSE_RANK() does not produce gaps; it assigns the next immediate rank after ties.
    ROW_NUMBER() does not produce gaps; it assigns a unique sequential number to each row.

Ties: 
    RANK() assigns the same rank to tied rows, and the next rank is incremented by the number of tied rows.
    DENSE_RANK() assigns the same rank to tied rows, but the next rank is the immediate next integer.
    ROW_NUMBER() assigns a unique sequential number to each row, regardless of ties ( so ties are not handled here ).

PARTITION BY clause:
    optinonal in all three functions. If omitted, all rows are treated as a single partition.

ORDER BY clause:
    mandatory in all three functions as it defines the order of rows within each partition for ranking or

window spec:
    optional in all three functions. If omitted, the entire partition is treated as a single window.


When to use which function:
    If you want to handle ties / assign same rank to tied rows
        use dense_rank() -- since it handles ties and also does not leave gaps in ranking sequence.
    If you want to assign unique sequential numbers to each row
        use row_number() -- since it assigns unique sequential numbers to each row.
        row_number() is useful when you need to uniquely identify each row in a result set, such as for pagination or when you need a unique identifier for each record.


-- example of ROW_NUMBER()

-- as you can see, ROW_NUMBER() always assigns unique sequential numbers to each row, regardless of ties
SELECT
    symbol,
    exchange,
    shares,
    ROW_NUMBER() OVER (PARTITION BY exchange ORDER BY shares) AS row_number
  FROM trades;
+------+--------+------+----------+
|SYMBOL|EXCHANGE|SHARES|ROW_NUMBER|
+------+--------+------+----------+
|SPY   |C       |   250|         1|
|AAPL  |C       |   250|         2|
|AAPL  |C       |   300|         3|
|SPY   |N       |   100|         1|
|AAPL  |N       |   300|         2|
|SPY   |N       |   500|         3|
|QQQ   |N       |   800|         4|
|QQQ   |N       |  2000|         5|
|YHOO  |N       |  5000|         6|
+------+--------+------+----------+


FIRST_VALUE()

Returns the first value within an ordered group of values.

Syntax

FIRST_VALUE( <expr> ) [ { IGNORE | RESPECT } NULLS ]
  OVER ( [ PARTITION BY <expr1> ] ORDER BY <expr2>  [ { ASC | DESC } ] [ <window_frame> ] )

{ IGNORE | RESPECT } NULLS
    -- Whether to ignore or respect NULL values when an expr contains NULL values:

    -- IGNORE NULLS returns the first non-NULL value.

    -- RESPECT NULLS returns a NULL value if it is the first value in the expression.

    -- Default: RESPECT NULLS

Arguments: 
    accepts a single argument <expr> which is the expression whose first value you want to retrieve within the specified window.

-- PARTIBTION BY clause is optional. If omitted, all rows are treated as a single partition.
-- ORDER BY clause is mandatory as it defines the order of rows within each partition for determining the first value.
-- The optional window_frame specifies the subset of rows within the window for which the function is calculated. If no window_frame is specified, the default is the entire window:
--     ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
-- Note that this deviates from the ANSI standard, which specifies the following default for window frames:
--     RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW


-- Its a window function, So it must specify a window. A window clause consists of the following subclauses:
--     PARTITION BY expr1 subclause (optional).
--     ORDER BY expr2 subclause (required). For details about additional supported ordering options (sort order, ordering of NULL values, and so on), see the documentation for the ORDER BY clause, which follows the same rules.
--     window_frame subclause (optional).

-- The ORDER BY clause inside the OVER clause controls the order of rows only within the window, not the order of rows in the output of the entire query. To control output order, use a separate ORDER BY clause at the outermost level of the query.

SELECT column1,
       column2,
       FIRST_VALUE(column2) OVER (PARTITION BY column1 ORDER BY column2 NULLS LAST) AS column2_first
  FROM VALUES
    (1, 10), (1, 11), (1, null), (1, 12),
    (2, 20), (2, 21), (2, 22)
  ORDER BY column1, column2;
+---------+---------+---------------+
| COLUMN1 | COLUMN2 | COLUMN2_FIRST |
|---------+---------+---------------|
|       1 |      10 |            10 |
|       1 |      11 |            10 |
|       1 |      12 |            10 |
|       1 |    NULL |            10 |
|       2 |      20 |            20 |
|       2 |      21 |            20 |
|       2 |      22 |            20 |
+---------+---------+---------------+


SELECT partition_col, order_col, i,
       FIRST_VALUE(i)  OVER (PARTITION BY partition_col ORDER BY order_col
         ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING) AS FIRST_VAL,
       NTH_VALUE(i, 2) OVER (PARTITION BY partition_col ORDER BY order_col
         ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING) AS NTH_VAL,
       LAST_VALUE(i)   OVER (PARTITION BY partition_col ORDER BY order_col
         ROWS BETWEEN 1 PRECEDING AND 1 FOLLOWING) AS LAST_VAL
  FROM demo1
  ORDER BY partition_col, i, order_col;
+---------------+-----------+---+-----------+---------+----------+
| PARTITION_COL | ORDER_COL | I | FIRST_VAL | NTH_VAL | LAST_VAL |
|---------------+-----------+---+-----------+---------+----------|
|             1 |         1 | 1 |         1 |       2 |        2 |
|             1 |         2 | 2 |         1 |       2 |        3 |
|             1 |         3 | 3 |         2 |       3 |        4 |
|             1 |         4 | 4 |         3 |       4 |        5 |
|             1 |         5 | 5 |         4 |       5 |        5 |
|             2 |         1 | 1 |         1 |       2 |        2 |
|             2 |         2 | 2 |         1 |       2 |        3 |
|             2 |         3 | 3 |         2 |       3 |        4 |
|             2 |         4 | 4 |         3 |       4 |        4 |
+---------------+-----------+---+-----------+---------+----------+



LEAD
Accesses data in a subsequent row in the same result set without having to join the table to itself.

Syntax
LEAD ( <expr> [ , <offset> , <default> ] ) [ { IGNORE | RESPECT } NULLS ]
  OVER ( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] )


-- offset
-- The number of rows forward from the current row from which to obtain a value. For example, an offset of 2 returns the expr value with an interval of 2 rows.
-- Note that setting a negative offset has the same effect as using the LAG function.
-- Default is 1. 

-- default
-- The expression to return when the offset goes out of the bounds of the window. Supports any expression whose type is compatible with expr.

-- Default is NULL.


-- { IGNORE | RESPECT } NULLS
-- Whether to ignore or respect NULL values when an expr contains NULL values:
-- IGNORE NULLS excludes any row whose expression evaluates to NULL when offset rows are counted.
-- RESPECT NULLS includes any row whose expression evaluates to NULL when offset rows are counted.

-- Default: RESPECT NULLS


Important points regarding LEAD() 
    1. It allows you to get values from subsequent rows in the result set without needing to perform a self-join.
    2. The function takes three arguments:
        a. expr: The expression whose value you want to retrieve from a subsequent row.
        b. offset (optional): The number of rows forward from the current row to retrieve the value. Default is 1.
        c. default (optional): The value to return if the offset goes beyond the bounds of the window. Default is NULL.
    3. The PARTITION BY clause is optional. If omitted, all rows are treated as a single partition.
    4. The ORDER BY clause is mandatory as it defines the order of rows within each partition for determining the subsequent rows.
    5. The function can be useful for tasks such as calculating differences between current and next row values, or for comparing values across rows in a time series.


-- partitioned by emp_id and ordered by year - I'm essentially trying to retrieve the revenue of the next year for each employee
SELECT emp_id,
       year,
       revenue,
       LEAD(revenue) OVER (PARTITION BY emp_id ORDER BY year) - revenue AS diff_to_next
  FROM sales
  ORDER BY emp_id, year;
+--------+------+----------+--------------+
| EMP_ID | YEAR |  REVENUE | DIFF_TO_NEXT |
|--------+------+----------+--------------|
|      0 | 2010 |  1000.00 |       500.00 |
|      0 | 2011 |  1500.00 |     -1000.00 |
|      0 | 2012 |   500.00 |       250.00 |
|      0 | 2013 |   750.00 |         NULL |
|      1 | 2010 | 10000.00 |      2500.00 |
|      1 | 2011 | 12500.00 |      2500.00 |
|      1 | 2012 | 15000.00 |      5000.00 |
|      1 | 2013 | 20000.00 |         NULL |
|      2 | 2012 |   500.00 |       300.00 |
|      2 | 2013 |   800.00 |         NULL |
+--------+------+----------+--------------+

-- no partition, calculating lead values for c2 based on ordering of c1 and ignoring nulls in c2
SELECT c1,
       c2,
       LEAD(c2) IGNORE NULLS OVER (ORDER BY c1)
  FROM t1;
+----+------+------------------------------------------+
| C1 | C2   | LEAD(C2) IGNORE NULLS OVER (ORDER BY C1) |
|----+------+------------------------------------------|
|  1 |  5   |                                        4 |
|  2 |  4   |                                        2 |
|  3 | NULL |                                        2 |
|  4 |  2   |                                        6 |
|  5 | NULL |                                        6 |
|  6 | NULL |                                        6 |
|  7 |  6   |                                     NULL |
+----+------+------------------------------------------+



NTH_VALUE
Returns the nth value (up to 1000) within an ordered group of values.

Syntax
NTH_VALUE( <expr> , <n> ) [ FROM { FIRST | LAST } ] [ { IGNORE | RESPECT } NULLS ]
  OVER ( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] [ <window_frame> ] )

FROM { FIRST | LAST }
Whether to ignore or respect NULL values when an expr contains NULL values:
    FROM FIRST starts from the beginning of the ordered list and moves forward.
    FROM LAST starts from the end of the ordered list and moves backward.

Default: FROM FIRST


{ IGNORE | RESPECT } NULLS
Whether to ignore or respect NULL values when an expr contains NULL values:
    IGNORE NULLS skips NULL values in the expression.
    RESPECT NULLS returns a NULL value if it is the nth value in the expression.

Default: RESPECT NULLS

Important points about NTH_VALUE:
    1. It allows you to retrieve the nth value from an ordered set of rows within a specified window.
    2. The function takes two main arguments:
        a. expr: The expression from which you want to retrieve the nth value.
        b. n: The position of the value you want to retrieve (must be between 1 and 1000).
    3. The optional FROM clause allows you to specify whether to count from the beginning (FIRST) or the end (LAST) of the ordered set.
    4. It is essentially a super set of FIRST_VALUE and LAST_VALUE functions, as it can retrieve any value in between the first and last based on the specified position.


NTILE 
    Divides an ordered data set equally into the number of buckets specified by constant_value.
    Buckets are sequentially numbered 1 through constant_value.

Syntax
NTILE( <constant_value> ) OVER ( [ PARTITION BY <expr1> ] ORDER BY <expr2> [ { ASC | DESC } ] )

Usecase of NTILE()
    It allows you to divide a result set into a specified number of approximately equal parts or buckets.
    So, if the data is partitioned, then the data is divided into buckets equally within each partition.
    For example, if the number of buckets is 3, and if the data is partitioned by province, then approximately 1/3 of the rows for each province are put into each bucket.


SELECT
    exchange,
    symbol,
    NTILE(4) OVER (PARTITION BY exchange ORDER BY shares) AS ntile_4
  FROM trades
  ORDER BY exchange, NTILE_4;
+--------+------+-------+
|exchange|symbol|NTILE_4|
+--------+------+-------+
|C       |SPY   |      1|
|C       |AAPL  |      2|
|C       |AAPL  |      3|
|N       |SPY   |      1|
|N       |AAPL  |      1|
|N       |SPY   |      2|
|N       |QQQ   |      2|
|N       |QQQ   |      3|
|N       |YHOO  |      4|
|Q       |MSFT  |      1|
|Q       |YHOO  |      1|
|Q       |MSFT  |      2|
|Q       |YHOO  |      2|
|Q       |QQQ   |      3|
|Q       |QQQ   |      4|
|P       |AAPL  |      1|
|P       |YHOO  |      1|
|P       |MSFT  |      2|
|P       |SPY   |      3|
|P       |MSFT  |      4|
+--------+------+-------+