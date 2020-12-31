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

