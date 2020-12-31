
#### mgr集群配置文件
[client]
socket = /usr/local/mysql/datas/s1/s1.sock
 
[mysqld]
socket = /usr/local/mysql/datas/s1/s1.sock
basedir = /usr/local/mysql
datadir = /usr/local/mysql/datas/s1/data



### Disable other storage engines

disabled_storage_engines="MyISAM,BLACKHOLE,FEDERATED,ARCHIVE,MEMORY"


### Replication configuration parameters

server_id=1
gtid_mode=ON
enforce_gtid_consistency=ON
binlog_checksum=NONE           # Not needed from 8.0.21


port=24801

### Group Replication configuration

plugin_load_add='group_replication.so'
group_replication_group_name="aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa"
group_replication_start_on_boot=off
group_replication_local_address= "127.0.0.1:24901"
group_replication_group_seeds= "127.0.0.1:24901,127.0.0.1:24902,127.0.0.1:24903"
group_replication_bootstrap_group= off


#### rm.sh 脚本

sudo rm -rf /usr/local/mysql/datas/s1/data
sudo rm -rf /usr/local/mysql/datas/s2/data
sudo rm -rf /usr/local/mysql/datas/s3/data

echo "rm data finished"

sudo /usr/local/mysql/bin/mysqld --defaults-file=/usr/local/mysql/datas/s1/s1.cnf --initialize-insecure --user=mysql
echo "--------------------------initialieze s1 over--------------------"
sudo /usr/local/mysql/bin/mysqld --defaults-file=/usr/local/mysql/datas/s2/s2.cnf --initialize-insecure --user=mysql
echo "--------------------------initialieze s2 over--------------------"
sudo /usr/local/mysql/bin/mysqld --defaults-file=/usr/local/mysql/datas/s3/s3.cnf --initialize-insecure --user=mysql
echo "--------------------------initialieze s3 over--------------------"



#### server集群初始化命令

cmake .. -DBUILD_CONFIG=mysql_release

sudo ./mysqld --defaults-file=/usr/local/mysql/datas/s1/s1.cnf --initialize-insecure --user=root
sudo ./mysqld --defaults-file=/usr/local/mysql/datas/s2/s2.cnf --initialize-insecure --user=root
sudo ./mysqld --defaults-file=/usr/local/mysql/datas/s3/s3.cnf --initialize-insecure --user=root



#### server集群gdb启动命令

sudo ./mysqld --defaults-file=/home/zhaoguodong/msBuild/install/datas/s1/s1.cnf --initialize-insecure --user=zhaoguodong
sudo ./mysqld --defaults-file=/home/zhaoguodong/msBuild/install/datas/s2/s2.cnf --initialize-insecure --user=zhaoguodong
sudo ./mysqld --defaults-file=/home/zhaoguodong/msBuild/install/datas/s3/s3.cnf --initialize-insecure --user=zhaoguodong


sudo gdb ./mysqld


sudo gdb --args ./mysqld --defaults-file=/usr/local/mysql/datas/s1/s1.cnf --user=root --gdb

sudo gdb --args ./mysqld --defaults-file=/usr/local/mysql/datas/s2/s2.cnf --user=root --gdb

sudo gdb --args ./mysqld --defaults-file=/usr/local/mysql/datas/s3/s3.cnf --user=root --gdb

--------

sudo ./mysqld --defaults-file=/usr/local/mysql/datas/s1/s1.cnf --user=root --gdb

sudo ./mysqld --defaults-file=/usr/local/mysql/datas/s2/s2.cnf --user=root --gdb

sudo ./mysqld --defaults-file=/usr/local/mysql/datas/s3/s3.cnf --user=root --gdb

#### client 连接命令

./mysql -u root -P 24801 -h 127.0.0.1
./mysql -u root -P 24802 -h 127.0.0.1
./mysql -u root -P 24803 -h 127.0.0.1


alter USER rpl_user@'%' IDENTIFIED WITH sha256_password BY 'password';
CREATE USER rpl_user@'%' IDENTIFIED WITH sha256_password BY 'password';


### 单主模式

#### primary上执行

SET SQL_LOG_BIN=0;
CREATE USER rpl_user@'%' IDENTIFIED WITH sha256_password BY 'password';
GRANT REPLICATION SLAVE ON *.* TO rpl_user@'%';
GRANT BACKUP_ADMIN ON *.* TO rpl_user@'%';
FLUSH PRIVILEGES;
SET SQL_LOG_BIN=1;

UNINSTALL PLUGIN group_replication;
INSTALL PLUGIN group_replication SONAME 'group_replication.so';

SET GLOBAL group_replication_bootstrap_group=ON;
START GROUP_REPLICATION USER='rpl_user', PASSWORD='password';
SET GLOBAL group_replication_bootstrap_group=OFF;

SELECT * FROM performance_schema.replication_group_members;

CREATE DATABASE test;
USE test;
CREATE TABLE t1 (c1 INT PRIMARY KEY, c2 TEXT NOT NULL);
INSERT INTO t1 VALUES (1, 'Luis');

SELECT * FROM t1;

SELECT * FROM test.t1;

SHOW BINLOG EVENTS;

#### slave 上执行

SET SQL_LOG_BIN=0;
CREATE USER rpl_user@'%' IDENTIFIED WITH sha256_password BY 'password';

GRANT REPLICATION SLAVE ON *.* TO rpl_user@'%';
GRANT BACKUP_ADMIN ON *.* TO rpl_user@'%';
FLUSH PRIVILEGES;
SET SQL_LOG_BIN=1;

UNINSTALL PLUGIN group_replication;
INSTALL PLUGIN group_replication SONAME 'group_replication.so';

CHANGE MASTER TO MASTER_USER='rpl_user', MASTER_PASSWORD='password' FOR CHANNEL 'group_replication_recovery';
START GROUP_REPLICATION USER='rpl_user', PASSWORD='password';

#### 查看状态

SELECT * FROM performance_schema.replication_group_members;
mysql> select * from performance_schema.replication_group_stats\G;
SELECT @@GLOBAL.gtid_executed;

#### 选主设置

show variables like 'group_replication_member_weight';

set global group_replication_primary_election_self_adaption=ON;

set global group_replication_member_weight = 200;

SELECT group_replication_set_as_primary('member_uuid');

set GLOBAL group_replication_group_name = 'aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaab';

set GLOBAL group_replication_group_name = 'aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa';


### 多主模式

run --defaults-file=/usr/local/mysql/datas/s3/s3.cnf --user=root --gdb

UNINSTALL PLUGIN group_replication;
INSTALL PLUGIN group_replication SONAME 'group_replication.so';


#### 停止组复制(所有节点执行)：
stop group_replication;
set global group_replication_single_primary_mode=OFF;
set global group_replication_enforce_update_everywhere_checks=ON;

#### 随便选择某个节点执行
SET GLOBAL group_replication_bootstrap_group=ON; 
START GROUP_REPLICATION; 
SET GLOBAL group_replication_bootstrap_group=OFF;

#### 其他节点执行
START GROUP_REPLICATION; 

#### 查看组信息，所有节点的 MEMBER_ROLE 都为 PRIMARY
SELECT * FROM performance_schema.replication_group_members;

select user, host from mysql.user;

show variables like '%group_replication_communication_debug_options%';

SET GLOBAL group_replication_communication_debug_options=  "XCOM_DEBUG_TRACE";


[ERROR] [MY-010901] [Server] Can't open shared library  undefined symbol: _Z17enough_live_nodesPK8site_def).

Certification_handler::handle_event (this=0x7fff08009190, pevent=0x7fff2c00bc40, cont=0x7fff2c0175e0)

### 测试

select @@global.gtid_executed;

#### 多线程复制配置

show variables like 'slave_parallel_type';
show variables like 'slave_parallel_workers';

set global slave_preserve_commit_order=ON;
set global slave_parallel_type='logical_clock';
set global slave_parallel_workers=8;

#### tpcc 测试

sudo ./tpcc_load -h 127.0.0.1 -P 24801 -d tpcc_test -u root -w 1 -p ""

./tpcc_start -h 127.0.0.1 -P 24801 -d tpcc_test -u root -p "" -w 1 -c 10 -r 60 -l 60



drop database tpcc_test;

create database tpcc_test;
use tpcc_test;
source /usr/local/src/tpcc-mysql/create_table.sql;
source /usr/local/src/tpcc-mysql/add_fkey_idx.sql;


SELECT column_name FROM INFORMATION_SCHEMA.`KEY_COLUMN_USAGE` WHERE table_name='history' AND constraint_name='PRIMARY';
select * from information_schema.`PROCESSLIST` where info is not null;

#### sysbench 测试

DROP DATABASE IF EXISTS sbtest;
create database sbtest;

 sysbench ./tests/include/oltp_legacy/oltp.lua --mysql-host=127.0.0.1  --mysql-user=root --mysql-password='' --oltp-test-mode=complex --oltp-tables-count=10 --oltp-table-size=100000 --threads=10 --time=120 --report-interval=10 prepare --mysql-port=24801

sysbench ./tests/include/oltp_legacy/oltp.lua --mysql-host=127.0.0.1 --mysql-user=root --mysql-password='' --oltp-test-mode=complex --oltp-tables-count=10 --oltp-table-size=100000 --threads=10 --time=120 --report-interval=10 run --mysql-port=24801

sysbench ./tests/include/oltp_legacy/oltp.lua --mysql-host=127.0.0.1 --mysql-user=root --mysql-password='' cleanup --mysql-port=24801

#### 火焰图
sudo perf record -F 99 -p 3072 -g -- sleep 30
sudo perf script -i perf.data &> perf.unfold
./stackcollapse-perf.pl perf.unfold &> perf.folded
./flamegraph.pl perf.folded > perf.svg

#### 查看端口

nmap -p 24903 localhost



#### mysql source change

强制走三阶段
threephase 0 ---> 1

// 0.5 秒向别的节点发送i am alive 变成 60秒
if (server_active(site, get_nodeno(site)) < sec - 0.5) { -----> if (server_active(site, get_nodeno(site)) < sec - 60)

#define MAX_SILENT 4 ----》 60 ：当一个节点4秒没有发生通信时就发送are you alive 变成 60秒

TIMED_TASK_WAIT(&detector_wait, 1.0); -----> 每1秒做一轮检查。检查节点是否还活着 变成 60秒

#define DETECTOR_LIVE_TIMEOUT 5.0   ---- 》 检测活着的标准原先是5秒没有通信，变成 62秒


