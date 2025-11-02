CURRENT_DATE(), CURRENT_TIME(), CURRENT_TIMESTAMP()

SELECT CURRENT_DATE(), CURRENT_TIME(), CURRENT_TIMESTAMP();


SYSDATE()

Returns the current timestamp for the system in the UTC time zone.


This function is similar to CURRENT_TIMESTAMP, except that:

    It returns the current timestamp in the UTC time zone, whereas CURRENT_TIMESTAMP returns the timestamp in the local time zone.

    Its return value is TIMESTAMP_NTZ, whereas CURRENT_TIMESTAMP returns TIMESTAMP_LTZ.

    It requires parentheses (SYSDATE()), whereas CURRENT_TIMESTAMP can be called without parentheses.


ALTER SESSION SET TIMESTAMP_NTZ_OUTPUT_FORMAT = 'YYYY-MM-DD HH24:MI:SS.FF4';
ALTER SESSION SET TIMESTAMP_LTZ_OUTPUT_FORMAT = 'YYYY-MM-DD HH24:MI:SS.FF4';

ALTER SESSION SET TIMEZONE = 'America/Los_Angeles';

SELECT SYSDATE(), CURRENT_TIMESTAMP();

+--------------------------+--------------------------+
| SYSDATE()                | CURRENT_TIMESTAMP()      |
|--------------------------+--------------------------|
| 2024-04-17 22:47:54.3520 | 2024-04-17 15:47:54.3520 |
+--------------------------+--------------------------+