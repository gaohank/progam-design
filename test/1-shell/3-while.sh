#!/bin/bash 

i=0
while [ $i -lt 10 ]
do
	echo $i
	i=`expr $i + 1`
done

echo $((100 * 100))
echo `expr 100 \* 100`
