CASE statements 

-- Works like a cascading “if-then-else” statement.
-- In the more general form, a series of conditions are evaluated in sequence.
-- When a condition evaluates to TRUE, the evaluation stops and the associated result (after THEN) is returned. 
-- If none of the conditions evaluate to TRUE, then the result after the optional ELSE is returned, if present; otherwise NULL is returned.

CASE
    WHEN <condition1> THEN <result1>
  [ WHEN <condition2> THEN <result2> ]
  [ ... ]
  [ ELSE <result3> ]
END


COALESCE
Returns the first non-NULL expression among its arguments, or NULL if all its arguments are NULL.

SELECT column1, column2, column3, coalesce(column1, column2, column3)
FROM (values
  (1,    2,    3   ),
  (null, 2,    3   ),
  (null, null, 3   ),
  (null, null, null),
  (1,    null, 3   ),
  (1,    null, null),
  (1,    2,    null)
) v;

+---------+---------+---------+-------------------------------------+
| COLUMN1 | COLUMN2 | COLUMN3 | COALESCE(COLUMN1, COLUMN2, COLUMN3) |
|---------+---------+---------+-------------------------------------|
|       1 |       2 |       3 |                                   1 |
|    NULL |       2 |       3 |                                   2 |
|    NULL |    NULL |       3 |                                   3 |
|    NULL |    NULL |    NULL |                                NULL |
|       1 |    NULL |       3 |                                   1 |
|       1 |    NULL |    NULL |                                   1 |
|       1 |       2 |    NULL |                                   1 |
+---------+---------+---------+-------------------------------------+


NVL

If expr1 is NULL, returns expr2, otherwise returns expr1.
NVL( <expr1> , <expr2> )

NOTE: just an alternative of COALESCE with only two arguments.


IFF

Returns one of two values depending on whether a Boolean expression evaluates to true or false. This function is similar to a single-level if-then-else expression. It is similar to CASE, but only allows a single condition.

IFF( <condition> , <expr1> , <expr2> )

NOTE: just an alternative of CASE with only one condition.



NULLIF

Returns NULL if expr1 is equal to expr2, otherwise returns expr1.

Syntax
NULLIF( <expr1> , <expr2> )

SELECT a, b, NULLIF(a,b) FROM i;

--------+--------+-------------+
   a    |   b    | nullif(a,b) |
--------+--------+-------------+
 0      | 0      | [NULL]      |
 0      | 1      | 0           |
 0      | [NULL] | 0           |
 1      | 0      | 1           |
 1      | 1      | [NULL]      |
 1      | [NULL] | 1           |
 [NULL] | 0      | [NULL]      |
 [NULL] | 1      | [NULL]      |
 [NULL] | [NULL] | [NULL]      |
--------+--------+-------------+