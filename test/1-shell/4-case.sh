#!/bin/bash 

read score

score=`expr $score / 10`

case $score in
	10)
		echo "A"
		;;
	9)
		echo "A"
		;;
	8)
		echo "B"
		;;
	7)
		echo "C"
		;;
	6)
		echo "D"
		;;
	*)
		echo "E"
		;;
esac

