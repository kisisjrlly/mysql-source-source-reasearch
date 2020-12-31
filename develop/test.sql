
DROP DATABASE IF EXISTS test;
CREATE DATABASE test;
USE test;
CREATE TABLE t1 (c1 INT PRIMARY KEY, c2 TEXT NOT NULL);

DELIMITER //
 
DROP PROCEDURE if EXISTS ‘T’;    # 如果存在test存储过程则删除
CREATE procedure T() # 创建无参存储过程，名称为test
BEGIN
DECLARE i INT;  # 申明变量
SET i = 0;  # 变量赋值
WHILE i<100000 DO # 结束循环的条件: 当i大于5时跳出while循环
INSERT INTO t1 VALUES(i+11,'test');  # 往test表添加数据
DELETE FROM t1 WHERE c1 = i+11;
SET i = i+1;    # 循环一次,i加1
END WHILE;  # 结束while循环
SELECT * FROM t1; # 查看test表数据
END
//  # 结束定义语句
CALL T();
DELIMITER ;