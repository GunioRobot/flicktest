pid=`ps -ef | grep init | grep -v grep | awk '{ print $2 }'`
strace -vTtt -p $pid
