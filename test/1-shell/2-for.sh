#!/bin/bash 

NAMES=("gao" "liu" "yang" "li")

echo "${NAMES[*]}"

for i in ${NAMES[@]} 
do
	echo "$i"
done

for ((i = 0; i < ${#NAMES[@]}; i++))
do
	echo "${NAMES[i]}"
done
