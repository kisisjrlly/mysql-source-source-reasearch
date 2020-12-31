sudo rm -rf /home/zhaoguodong/msBuild/install/datas/s1/data
sudo rm -rf /home/zhaoguodong/msBuild/install/datas/s2/data
sudo rm -rf /home/zhaoguodong/msBuild/install/datas/s3/data

echo "rm data finished"

sudo /home/zhaoguodong/msBuild/install/bin/mysqld --defaults-file=/home/zhaoguodong/msBuild/install/datas/s1/s1.cnf --initialize-insecure --user=zhaoguodong
echo "--------------------------initialieze s1 over--------------------"
sudo /home/zhaoguodong/msBuild/install/bin/mysqld --defaults-file=/home/zhaoguodong/msBuild/install/datas/s2/s2.cnf --initialize-insecure --user=zhaoguodong
echo "--------------------------initialieze s2 over--------------------"
sudo /home/zhaoguodong/msBuild/install/bin/mysqld --defaults-file=/home/zhaoguodong/msBuild/install/datas/s3/s3.cnf --initialize-insecure --user=zhaogoudong
echo "--------------------------initialieze s3 over--------------------"