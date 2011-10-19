#!/bin/bash
i=1
while [ $i -le 2 ]
do
  pid=`ps -ef | grep init | grep -v grep | awk '{ print $2 }'`
  pstack $pid
  sleep 10
done
