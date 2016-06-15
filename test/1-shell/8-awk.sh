#!/bin/bash 
#awk 'option1{action1}option2{action2}...'
#NR -- 当前处理的是第几行数据
#NF -- 每行所有的字段数
#FS -- 分割符号，默认空格
cat /etc/passwd | awk 'BEGIN{FS=":"}{print $1}' | head -n 5
