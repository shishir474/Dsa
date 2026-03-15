ANY_VALUE()
    aggregation function: any_value(expr)
    window function : any_value(expr1) over(partition by expr2)
        NOTE: does not support order by clause in window function 


AVG
--    Returns the average of non-NULL records. If all records inside a group are NULL, the function returns NULL.

--    Syntax
--     Aggregate function

--     AVG( [ DISTINCT ] <expr1> )
   
--     Window function

--     AVG( [ DISTINCT ] <expr1> ) OVER (
--                                     [ PARTITION BY <expr2> ]
--                                     [ ORDER BY <expr3> [ ASC | DESC ] [ <window_frame> ] ]
--                                     )

--     Arguments
--         expr1 - This is an expression that evaluates to a numeric data type (INTEGER, FLOAT, DECIMAL, etc.).

--         expr2 - This is the optional expression to partition by.

--         expr3 - This is the optional expression to order by within each partition.



--     When passed a VARCHAR expression, this function implicitly casts the input to floating point values. If the cast cannot be performed, an error is returned.

--     When this function is called as a window function with an OVER clause that contains an ORDER BY clause: A window frame is required. If no window frame is specified explicitly, the following implied window frame is used:

--     RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW

    CREATE OR REPLACE TABLE avg_example(int_col int, d decimal(10,5), s1 varchar(10), s2 varchar(10));
    
    INSERT INTO avg_example VALUES
    (1, 1.1, '1.1','one'), 
    (1, 10, '10','ten'),
    (2, 2.4, '2.4','two'), 
    (2, NULL, NULL, 'NULL'),
    (3, NULL, NULL, 'NULL'),
    (NULL, 9.9, '9.9','nine');

-- Calculate the average of the columns that are numeric or that can be converted to numbers:

    SELECT * 
    FROM avg_example 
    ORDER BY int_col, d;
+---------+----------+------+------+
| INT_COL |        D | S1   | S2   |
|---------+----------+------+------|
|       1 |  1.10000 | 1.1  | one  |
|       1 | 10.00000 | 10   | ten  |
|       2 |  2.40000 | 2.4  | two  |
|       2 |     NULL | NULL | NULL |
|       3 |     NULL | NULL | NULL |
|    NULL |  9.90000 | 9.9  | nine |
+---------+----------+------+------+

    SELECT AVG(int_col), AVG(d)
    FROM avg_example;
+--------------+---------------+
| AVG(INT_COL) |        AVG(D) |
|--------------+---------------|
|     1.800000 | 5.85000000000 |
+--------------+---------------+

-- Combine AVG with GROUP BY to calculate the averages of different groups:

SELECT int_col, AVG(d), AVG(s1) 
    FROM avg_example 
    GROUP BY int_col
    ORDER BY int_col;
+---------+---------------+---------+
| INT_COL |        AVG(D) | AVG(S1) |
|---------+---------------+---------|
|       1 | 5.55000000000 |    5.55 |
|       2 | 2.40000000000 |    2.4  |
|       3 |          NULL |    NULL |
|    NULL | 9.90000000000 |    9.9  |
+---------+---------------+---------+

-- Use as a simple window function:

    SELECT 
       int_col,
       AVG(int_col) OVER(PARTITION BY int_col) 
    FROM avg_example
    ORDER BY int_col;
+---------+-----------------------------------------+
| INT_COL | AVG(INT_COL) OVER(PARTITION BY INT_COL) |
|---------+-----------------------------------------|
|       1 |                                   1.000 |
|       1 |                                   1.000 |
|       2 |                                   2.000 |
|       2 |                                   2.000 |
|       3 |                                   3.000 |
|    NULL |                                    NULL |
+---------+-----------------------------------------+



-- COUNT
-- Returns either the number of non-NULL records for the specified columns, or the total number of records.

-- Syntax

Aggregate function

-- you can include multiple columns, to count the number of unique combinations
    COUNT( [ DISTINCT ] <expr1> [ , <expr2> ... ] )

    COUNT(*) 
        -- * is the wild card that represents all columns. 
        -- You can use ILIKE or EXCLUDE to filter the columns to be considered for counting with wildcard.

        -- Returns the total number of records.
        -- ILIKE filters for column names that match the specified pattern. Only one pattern is allowed. 
        (* ILIKE 'col1%')

        -- EXCLUDE filters out column names that don’t match the specified column or columns. 
        (* EXCLUDE 'col1', 'col2')

        -- The ILIKE and EXCLUDE keywords can’t be combined in a single function call.
        -- If you specify an unqualified and unfiltered wildcard (*), the function returns the total number of records, including records with NULL values.

        -- If you specify a wildcard with the ILIKE or EXCLUDE keyword for filtering, the function excludes records with NULL values.


    COUNT(<alias>.*)
        -- Returns the number of records that don’t contain any NULL values. 

-- Window function
    COUNT( [ DISTINCT ] <expr1> [ , <expr2> ... ] ) OVER (
                                                     [ PARTITION BY <expr3> ]
                                                     [ ORDER BY <expr4> [ ASC | DESC ] [ <window_frame> ] ]
                                                     )

    -- expr3 - column to partition on, if you want the result to be split into multiple windows.


    CREATE TABLE basic_example (i_col INTEGER, j_col INTEGER);
    INSERT INTO basic_example VALUES
    (11,101), (11,102), (11,NULL), (12,101), (NULL,101), (NULL,102);

    SELECT *
    FROM basic_example
    ORDER BY i_col;

    +-------+-------+
| I_COL | J_COL |
|-------+-------|
|    11 |   101 |
|    11 |   102 |
|    11 |  NULL |
|    12 |   101 |
|  NULL |   101 |
|  NULL |   102 |
+-------+-------+

    SELECT COUNT(*) AS "All",   -- includes nulls
       COUNT(* ILIKE 'i_c%') AS "ILIKE", -- does not include nulls
       COUNT(* EXCLUDE i_col) AS "EXCLUDE", -- -- does not include nulls
       COUNT(i_col) AS "i_col",     -- does not include nulls
       COUNT(DISTINCT i_col) AS "DISTINCT i_col", -- does not include nulls
       COUNT(j_col) AS "j_col",     -- does not include nulls
       COUNT(DISTINCT j_col) AS "DISTINCT j_col" -- does not include nulls
    FROM basic_example;

    +-----+-------+---------+-------+----------------+-------+----------------+
| All | ILIKE | EXCLUDE | i_col | DISTINCT i_col | j_col | DISTINCT j_col |
|-----+-------+---------+-------+----------------+-------+----------------|
|   6 |     4 |       5 |     4 |              2 |     5 |              2 |
+-----+-------+---------+-------+----------------+-------+----------------+

-- Conclusion:
-- The All column in this output shows that when an unqualified and unfiltered wildcard is specified for COUNT, the function returns the total number of rows in the table, including rows with NULL values.
--  The other columns in the output show that when a column or a wildcard with filtering is specified, the function excludes rows with NULL values.


-- The next query uses the COUNT function with the GROUP BY clause:
    SELECT i_col, COUNT(*), COUNT(j_col)
    FROM basic_example
    GROUP BY i_col
    ORDER BY i_col;

    +-------+----------+--------------+
| I_COL | COUNT(*) | COUNT(J_COL) |
|-------+----------+--------------|
|    11 |        3 |            2 |
|    12 |        1 |            1 |
|  NULL |        2 |            2 |
+-------+----------+--------------+

-- The following example shows that COUNT(alias.*) returns the number of rows that don’t contain any NULL values. The basic_example table has a total of six rows, but three rows have at least one NULL value, and the other three rows have no NULL values.

-- if you are using alias -- it does not consider rows with nulls
SELECT COUNT(n.*) 
    FROM basic_example AS n;

+------------+
| COUNT(N.*) |
|------------|
|          3 |
+------------+

-- The following example shows that JSON null (VARIANT NULL) is treated as SQL NULL by the COUNT function.

CREATE OR REPLACE TABLE count_example_with_variant_column (
  i_col INTEGER, 
  j_col INTEGER, 
  v VARIANT);

BEGIN WORK;

INSERT INTO count_example_with_variant_column (i_col, j_col, v) 
  VALUES (NULL, 10, NULL);
INSERT INTO count_example_with_variant_column (i_col, j_col, v) 
  SELECT 1, 11, PARSE_JSON('{"Title": null}');
INSERT INTO count_example_with_variant_column (i_col, j_col, v) 
  SELECT 2, 12, PARSE_JSON('{"Title": "O"}');
INSERT INTO count_example_with_variant_column (i_col, j_col, v) 
  SELECT 3, 12, PARSE_JSON('{"Title": "I"}');

COMMIT WORK;

-- v is a variant column. Variant columns are essentially JSON values
SELECT i_col, j_col, v, v:Title
    FROM count_example_with_variant_column
    ORDER BY i_col;

+-------+-------+-----------------+---------+
| I_COL | J_COL | V               | V:TITLE |
|-------+-------+-----------------+---------|
|     1 |    11 | {               | null    |       -- JSON NULL
|       |       |   "Title": null |         |
|       |       | }               |         |
|     2 |    12 | {               | "O"     |
|       |       |   "Title": "O"  |         |
|       |       | }               |         |
|     3 |    12 | {               | "I"     |
|       |       |   "Title": "I"  |         |
|       |       | }               |         |
|  NULL |    10 | NULL            | NULL    |           -- sql NULL
+-------+-------+-----------------+---------+


-- COUNT function treats both the NULL and the JSON null (VARIANT NULL) values as NULLs. 
-- 
SELECT COUNT(v:Title)
FROM count_example_with_variant_column;

+----------------+
| COUNT(V:TITLE) |
|----------------|
|              2 |
+----------------+



COUNT IF 
-- Returns the number of records that satisfy a condition or NULL if no records satisfy the condition.

Aggregate function

COUNT_IF( <condition> )

Window function

COUNT_IF( <condition> )
    OVER ( [ PARTITION BY <expr1> ] [ ORDER BY <expr2> [ ASC | DESC ] [ <window_frame> ] ] )


-- <condition> : The condition is an expression that should evaluate to a BOOLEAN value (True, False, or NULL)
-- expr1: The column to partition on, if you want the result to be split into multiple windows.
-- expr2: The column to order by within each partition.

When this function is called as a window function with an ORDER BY clause, you must specify a window frame. If you do not specify a window frame, the following default frame is used:

RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW

CREATE TABLE basic_example (i_col INTEGER, j_col INTEGER);
INSERT INTO basic_example VALUES
    (11,101), (11,102), (11,NULL), (12,101), (NULL,101), (NULL,102);

SELECT *
    FROM basic_example
    ORDER BY i_col;


+-------+-------+
| I_COL | J_COL |
|-------+-------|
|    11 |   101 |
|    11 |   102 |
|    11 |  NULL |
|    12 |   101 |
|  NULL |   101 |
|  NULL |   102 |
+-------+-------+

SELECT COUNT_IF(j_col > i_col) FROM basic_example;

+-------------------------+
| COUNT_IF(J_COL > I_COL) |
|-------------------------|
|                       3 |
+-------------------------+

-- The count does not include rows with NULL values.
-- When any operand for a comparison operator is NULL, the result is NULL



Max

Syntax
Aggregate function

MAX( <expr> )

Window function

MAX( <expr> ) [ OVER ( [ PARTITION BY <expr1> ] [ ORDER BY <expr2> [ <window_frame> ] ] ) ]

SELECT k, MAX(d)
  FROM sample_table 
  GROUP BY k
  ORDER BY k;

| K    | MAX(D) |
|------+--------|
| 1    | 5      |
| 2    | 2      |
| 3    | NULL   |
| NULL | 7      |
+------+--------+

-- above query producces maximum d for each group of k


SELECT k, d, MAX(d) OVER (PARTITION BY k)
  FROM sample_table
  ORDER BY k, d;

+------+------+------------------------------+                                  
| K    | D    | MAX(D) OVER (PARTITION BY K) |
|------+------+------------------------------|
| 1    | 1    | 5                            |
| 1    | 3    | 5                            |
| 1    | 5    | 5                            |
| 2    | 2    | 2                            |
| 2    | NULL | 2                            |
| 3    | NULL | NULL                         |
| NULL | 1    | 7                            |
| NULL | 7    | 7                            |
+------+------+------------------------------+

-- NOTE: While using window function, we dont need GROUP BY clause. 

-- If you want to specify the window frame - then you need to use ORDER BY clause inside OVER()

-- default value of window frame when ORDER BY is specified is:
RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW


Main difference between aggregation and window function is aggregation function produces a single result for each group, whereas window function produces a result for each row in the group.

OVER() clause signifier window function
PARTITION BY clause divides the result set into partitions to which the window function is applied.
ORDER BY clause defines the logical order of the rows within each partition of a window function.
Window frame clause defines a subset of rows within a partition.

Passing no arguments to the OVER() clause means that the function is applied to all rows of the query result set as a single partition.

-- NOTE: Use a PARTITION BY clause to break the data into groups based on the value of k. 
-- This is similar to, but not identical to, using GROUP BY.
-- In particular, GROUP BY produces one output row per group, while PARTITION BY produces one output row per input row.



-- Use a windowing ORDER BY clause to create a sliding window two rows wide, and output the highest value within that window. 
-- (Remember that ORDER BY in the windowing clause is separate from ORDER BY at the statement level.) 
-- This example uses a single partition, so there is no PARTITION BY clause in the OVER() clause.

SELECT k, d, MAX(d) OVER (ORDER BY k, d ROWS BETWEEN 1 PRECEDING AND CURRENT ROW)
  FROM sample_table
  ORDER BY k, d;


-- Mode 

Returns the most frequent value for the values within expr1. NULL values are ignored. If all the values are NULL, or there are 0 rows, then the function returns NULL.

Syntax

Aggregate function

MODE( <expr1> )

Window function

MODE( <expr1> ) OVER ( [ PARTITION BY <expr2> ] )


create or replace table aggr(k int, v decimal(10,2));

INSERT INTO aggr (k, v) VALUES
    (1, 10), 
    (1, 10), 
    (1, 10), 
    (1, 10), 
    (1, 20), 
    (1, 21);


-- version 1: over the entire table
select mode(v) from aggr;
+---------+
| MODE(V) |
|---------|
|   10.00 |
+---------+

-- note that mode() ignores nulls

-- version 2: aggregation version
select k, mode(v) 
    from aggr 
    group by k
    order by k;
+---+---------+
| K | MODE(V) |
|---+---------|
| 1 |   10.00 |
| 2 |   20.00 |
| 3 |    NULL |
+---+---------+'


-- version 3: window function version
select k, v, mode(v) over (partition by k) 
    from aggr 
    order by k, v;


SUM

--Returns the sum of non-NULL records for expr. You can use the DISTINCT keyword to compute the sum of unique non-null values.

Syntax
Aggregate function

SUM( [ DISTINCT ] <expr1> )

Window function

SUM( [ DISTINCT ] <expr1> ) OVER (
                                 [ PARTITION BY <expr2> ]
                                 [ ORDER BY <expr3> [ ASC | DESC ] [ <window_frame> ] ]
                                 )