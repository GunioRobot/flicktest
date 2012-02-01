#!/bin/bash
i=1
while [ $i -le 2 ]
do
  ps -Leo lstart,wchan,nwchan,ppid,tid,user,group,stat,%cpu,cputime,cmd
  sleep 1
done
