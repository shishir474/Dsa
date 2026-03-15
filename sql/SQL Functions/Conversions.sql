CAST , ::

Converts a value of one data type into another data type. 
The semantics of CAST are the same as the semantics of the corresponding TO_ datatype conversion functions.
If the cast is not possible, an error is raised.

The :: operator provides alternative syntax for CAST.

Syntax
CAST( <source_expr> AS <target_data_type> )
  [ RENAME FIELDS | ADD FIELDS ]

<source_expr> :: <target_data_type>

CREATE OR REPLACE TABLE test_data_type_conversion (
  varchar_value VARCHAR,
  number_value NUMBER(5, 4),
  timestamp_value TIMESTAMP);

INSERT INTO test_data_type_conversion VALUES (
  '9.8765',
  1.2345,
  '2024-05-09 14:32:29.135 -0700');

SELECT * FROM test_data_type_conversion;

+---------------+--------------+-------------------------+
| VARCHAR_VALUE | NUMBER_VALUE | TIMESTAMP_VALUE         |
|---------------+--------------+-------------------------|
| 9.8765        |       1.2345 | 2024-05-09 14:32:29.135 |
+---------------+--------------+-------------------------+

use the SYSTEM$TYPEOF function to show the data type of the converted value.

-- using CAST() function
SELECT CAST(varchar_value AS NUMBER(5,2)) AS varchar_to_number1,
       SYSTEM$TYPEOF(varchar_to_number1) AS data_type
  FROM test_data_type_conversion;

-- using :: operator
SELECT varchar_value::NUMBER(6,5) AS varchar_to_number2,
       SYSTEM$TYPEOF(varchar_to_number2) AS data_type
FROM test_data_type_conversion;

SELECT CAST(timestamp_value AS DATE) AS timestamp_to_date,
    SYSTEM$TYPEOF(timestamp_to_date) AS data_type
FROM test_data_type_conversion;

+-------------------+-----------+
| TIMESTAMP_TO_DATE | DATA_TYPE |
|-------------------+-----------|
| 2024-05-09        | DATE[SB4] |
+-------------------+-----------+



TRY_CAST
A special version of CAST , :: that is available for a subset of data type conversions.
It performs the same operation (i.e. converts a value of one data type into another data type), but returns a NULL value instead of raising an error when the conversion can not be performed.

TRY_CAST( <source_expr> AS <target_data_type> )

TRY_CAST() is a safer alternative to CAST() when converting data that may not be clean or well-formed.
TRY_CAST() returns NULL for invalid conversions instead of raising an error, allowing queries to complete successfully even when some data cannot be converted.

target_data_type must be one of the following:

    VARCHAR (or any of its synonyms)

    NUMBER (or any of its synonyms)

    DOUBLE

    BOOLEAN

    DATE

    TIME

    TIMESTAMP, TIMESTAMP_LTZ, TIMESTAMP_NTZ, or TIMESTAMP_TZ




SELECT TRY_CAST('05-Mar-2016' AS TIMESTAMP);
+--------------------------------------+
| TRY_CAST('05-MAR-2016' AS TIMESTAMP) |
|--------------------------------------|
| 2016-03-05 00:00:00.000              |
+--------------------------------------+

SELECT TRY_CAST('05/16' AS TIMESTAMP);
+--------------------------------+
| TRY_CAST('05/16' AS TIMESTAMP) |
|--------------------------------|
| NULL                           |
+--------------------------------+


TRY_CHAR(), TRY_NUMBER(), TRY_DATE(), TRY_TIMESTAMP()

-- all the below versions allow you to specify format as optional second argument
TO_VARCHAR( <expr> )
TO_VARCHAR( <numeric_expr> [, '<format>' ] )
TO_VARCHAR( <date_or_time_expr> [, '<format>' ] )
TO_VARCHAR( <binary_expr> [, '<format>' ] )

SELECT TO_VARCHAR('2024-04-05 01:02:03'::TIMESTAMP, 'mm/dd/yyyy, hh24:mi hours');
+---------------------------------------------------------------------------+
| TO_VARCHAR('2024-04-05 01:02:03'::TIMESTAMP, 'MM/DD/YYYY, HH24:MI HOURS') |
|---------------------------------------------------------------------------|
| 04/05/2024, 01:02 hours                                                   |
+---------------------------------------------------------------------------+

-- Convert a DATE value to a string in the default format:
SELECT TO_VARCHAR('03-April-2024'::DATE);

+-----------------------------------+
| TO_VARCHAR('03-APRIL-2024'::DATE) |
|-----------------------------------|
| 2024-04-03                        |
+-----------------------------------+


-- Convert a DATE value to a string in the specified format:

SELECT TO_VARCHAR('03-April-2024'::DATE, 'yyyy.mm.dd');

+-------------------------------------------------+
| TO_VARCHAR('03-APRIL-2024'::DATE, 'YYYY.MM.DD') |
|-------------------------------------------------|
| 2024.04.03                                      |
+-------------------------------------------------+


-- has error-handling support so that the function returns NULL if the conversion can’t be performed.

TRY_TO_DECIMAL( <string_expr> [, '<format>' ] [, <precision> [, <scale> ] ] )

TRY_TO_NUMBER( <string_expr> [, '<format>' ] [, <precision> [, <scale> ] ] )

TRY_TO_NUMERIC( <string_expr> [, '<format>' ] [, <precision> [, <scale> ] ] )

-- If the precision isn’t specified, then it defaults to 38.

-- If the scale isn’t specified, then it defaults to 0.


-- The following example fails because the input string contains a dollar sign ($) and a comma to separate groups of digits, not just digits and decimal points. 
-- However, the format specifier for the last column doesn’t tell the TO_DECIMAL function to expect the dollar sign and comma:
SELECT column1 AS orig_string,
       TO_DECIMAL(column1, '$9,999.00') AS num,
       TO_DECIMAL(column1, '$9,999.00', 6, 2) AS num_with_scale,
       TO_DECIMAL(column1, 6, 2) AS num_with_format_err
  FROM VALUES ('$7,543.21');

-- 100038 (22018): Numeric value '$7,543.21' is not recognized


-- The following query is the same as the preceding query, except that it uses TRY_TO_DECIMAL rather than TO_DECIMAL, so it converts the input to NULL:
-- NOTE: here we have passed format specifier in the 2nd argument - This allows us to tell the function to expect the dollar sign and comma in the input string.
SELECT column1 AS orig_string,
       TRY_TO_DECIMAL(column1, '$9,999.00') AS num,
       TRY_TO_DECIMAL(column1, '$9,999.00', 6, 2) AS num_with_scale,
       TRY_TO_DECIMAL(column1, 6, 2) AS num_with_format_err
  FROM VALUES ('$7,543.21');

  +-------------+------+----------------+---------------------+
| ORIG_STRING |  NUM | NUM_WITH_SCALE | NUM_WITH_FORMAT_ERR |
|-------------+------+----------------+---------------------|
| $7,543.21   | 7543 |        7543.21 |                NULL |
+-------------+------+----------------+---------------------+



TO_DATE , DATE
Converts an input expression to a date:

For a VARCHAR expression, the result of converting the string to a date.

For a TIMESTAMP expression, the date from the timestamp.

TO_DATE( <string_expr> [, <format> ] )
TO_DATE( <timestamp_expr> )
TO_DATE( '<integer>' )
TO_DATE( <variant_expr> )

DATE( <string_expr> [, <format> ] )
DATE( <timestamp_expr> )
DATE( '<integer>' )
DATE( <variant_expr> )

-- Basic examples

-- converts a string to a date using the default format (YYYY-MM-DD)
SELECT TO_DATE('2024-05-10'), DATE('2024-05-10');

-- converts a timestamp to a date 
SELECT TO_DATE(ts) FROM date_from_timestamp;

-- Examples that use different input formats
-- convert a string(which uses 'YYYY.MM.DD') to a date 
SELECT TO_DATE('2024.05.10', 'YYYY.MM.DD'), DATE('2024.05.10', 'YYYY.MM.DD');
+-------------------------------------+----------------------------------+
| TO_DATE('2024.05.10', 'YYYY.MM.DD') | DATE('2024.05.10', 'YYYY.MM.DD') |
|-------------------------------------+----------------------------------|
| 2024-05-10                          | 2024-05-10                       |
+-------------------------------------+----------------------------------+

-- NOTE: The date format in the returned output is determined by the setting of the DATE_OUTPUT_FORMAT session parameter.
-- By default the DATE_OUTPUT_FORMAT is set to 'YYYY-MM-DD'. 

-- Since the DATE_OUTPUT_FORMAT is set as 'YYYY-MM-DD' by default, the output appears in that format.

SELECT TO_DATE('05/10/2024', 'MM/DD/YYYY'), DATE('05/10/2024', 'MM/DD/YYYY');
+-------------------------------------+----------------------------------+
| TO_DATE('05/10/2024', 'MM/DD/YYYY') | DATE('05/20/2024', 'MM/DD/YYYY') |
|-------------------------------------+----------------------------------|
| 2024-05-10                          | 2024-05-20                       |
+-------------------------------------+----------------------------------+

-- Examples that use different output formats

ALTER SESSION SET DATE_OUTPUT_FORMAT = 'DD-MON-YYYY';

-- convert a string(which uses 'YYYY-MM-DD') to a date 
SELECT TO_DATE('2024-05-10', 'YYYY-MM-DD'), DATE('2024-05-10', 'YYYY-MM-DD');
+-------------------------------------+----------------------------------+
| TO_DATE('2024-05-10', 'YYYY-MM-DD') | DATE('2024-05-10', 'YYYY-MM-DD') |
|-------------------------------------+----------------------------------|
| 10-May-2024                         | 10-May-2024                      |
+-------------------------------------+----------------------------------+

-- convert a string(which uses 'MM/DD/YYYY') to a date 
SELECT TO_DATE('05/10/2024', 'MM/DD/YYYY'), DATE('05/10/2024', 'MM/DD/YYYY');
+-------------------------------------+----------------------------------+
| TO_DATE('05/10/2024', 'MM/DD/YYYY') | DATE('05/10/2024', 'MM/DD/YYYY') |
|-------------------------------------+----------------------------------|
| 10-May-2024                         | 10-May-2024                      |
+-------------------------------------+----------------------------------+

-- Convert a date to a string, and specify a date output format of mon dd, yyyy.
-- date to varchar conversion
SELECT TO_VARCHAR('2024-04-05'::DATE, 'mon dd, yyyy');
+------------------------------------------------+
| TO_VARCHAR('2024-04-05'::DATE, 'MON DD, YYYY') |
|------------------------------------------------|
| Apr 05, 2024                                   |
+------------------------------------------------+
