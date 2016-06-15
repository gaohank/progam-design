#!/bin/bash 

echo "input passwd:"
read passwd

if [ $passwd = "score" ]
then 
	echo "this is correct"
else 
	echo "passwd is wrong"
	exit 1
fi

echo "input your score:"
read score

if [ $score -gt 100 -o $score -lt 0 ]
then
	echo "score is error"
	exit 1
fi

if [ $score -gt 90 -a $score -le 100 ] 
then
	echo "very good!"
else 
	if (($score < 60))
	then
		echo "not good"
	fi
fi
