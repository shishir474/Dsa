CONCAT , ||
Concatenates one or more strings. The || operator provides alternative syntax for CONCAT and requires at least two arguments.

Syntax
CONCAT( <expr> [ , <expr> ... ] )

<expr> || <expr> [ || <expr> ... ]

Returns
The data type of the returned value is the same as the data type of the input value(s).

NOTE: If any input value is NULL, returns NULL.

SELECT CONCAT('George Washington ', 'Carver');
+----------------------------------------+
| CONCAT('GEORGE WASHINGTON ', 'CARVER') |
|----------------------------------------|
| George Washington Carver               |
+----------------------------------------+