### Setup
--disable_warnings
DROP TABLE IF EXISTS t1;
--enable_warnings

### Create table
eval CREATE TABLE t1(c1 $numeric_type $sign_flag $null_flag $index_flag);

### Insert Values

# Values within range
eval INSERT INTO t1 VALUES
  ($min_val),
  (0),
  (0),
  (0),
  (0),
  ($mid_val - 2),
  ($mid_val - 1),
  ($mid_val),
  ($mid_val),
  ($mid_val + 1),
  ($mid_val + 2),
  ($max_val);

### Read table
SELECT * FROM t1 ORDER BY c1 ASC;
SELECT * FROM t1 ORDER BY c1 DESC;

eval SELECT * FROM t1 WHERE c1 >  $mid_val ORDER BY c1 ASC;
eval SELECT * FROM t1 WHERE c1 >= $mid_val ORDER BY c1 ASC;
eval SELECT * FROM t1 WHERE c1 <  $mid_val ORDER BY c1 ASC;
eval SELECT * FROM t1 WHERE c1 <= $mid_val ORDER BY c1 ASC;
eval SELECT * FROM t1 WHERE c1 =  $mid_val ORDER BY c1 ASC;

eval SELECT * FROM t1 WHERE c1 >  $mid_val ORDER BY c1 DESC;
eval SELECT * FROM t1 WHERE c1 >= $mid_val ORDER BY c1 DESC;
eval SELECT * FROM t1 WHERE c1 <  $mid_val ORDER BY c1 DESC;
eval SELECT * FROM t1 WHERE c1 <= $mid_val ORDER BY c1 DESC;
eval SELECT * FROM t1 WHERE c1 =  $mid_val ORDER BY c1 DESC;

### Update Values
eval UPDATE t1
  SET c1 = $mid_val
  WHERE c1 <= 0 + $epsilon AND c1 >= 0 - $epsilon
  ORDER BY c1 ASC
  LIMIT 2;

# Check updates
SELECT * FROM t1 ORDER BY c1;

### Delete values

eval DELETE FROM t1
  WHERE c1 <= 0 + $epsilon AND c1 >= 0 - $epsilon
  ORDER BY c1;

# Check deletes
SELECT * FROM t1 ORDER BY c1;

### Cleanup
DROP TABLE t1;

eval CREATE TABLE t1(c1 $numeric_type $sign_flag $null_flag, c2 $numeric_type $sign_flag $null_flag $multi_index_flag);
eval INSERT INTO t1 VALUES
  ($min_val, $min_val),
  (0, 0),
  (0, 0),
  (0, 0),
  (0, 0),
  ($mid_val, $mid_val - 2),
  ($mid_val, $mid_val - 1),
  ($mid_val, $mid_val),
  ($mid_val, $mid_val),
  ($mid_val, $mid_val + 1),
  ($mid_val, $mid_val + 2),
  ($max_val, $max_val);

### Read table
eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 > $mid_val ORDER BY c2 ASC;
eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 >= $mid_val ORDER BY c2 ASC;
eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 < $mid_val ORDER BY c2 ASC;
eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 <= $mid_val ORDER BY c2 ASC;

eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 > $mid_val ORDER BY c2 DESC;
eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 >= $mid_val ORDER BY c2 DESC;
eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 < $mid_val ORDER BY c2 DESC;
eval SELECT * FROM t1 WHERE c1 = $mid_val AND c2 <= $mid_val ORDER BY c2 DESC;

### Cleanup
DROP TABLE t1;
