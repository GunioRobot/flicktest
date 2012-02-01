pid=`ps -ef | grep init | grep -v grep | awk '{ print $2 }'`
echo "pid is $pid"


lsof -p $pid
tree /proc/$pid/

echo 9 > /proc/sysrq-trigger
echo t > /proc/sysrq-trigger

