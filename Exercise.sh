#!/bin/bash

	TOTAL_MEMORY=$(free  | grep Mem: | awk '{print $2}')
	echo " Total Memory is $TOTAL_MEMORY "
	TOTAL_USED=$(free  | grep Mem: | awk '{print $3}')
	echo " Total Used Memory is $TOTAL_USED "
	freespace=$(free  | grep Mem: | awk '{print $3/$2 *100}')
	echo " Percentage free space is $freespace "
	if [[ "$freespace" -ge 90 ]]; then
	message= "Critical:  Memory limit exceeded"
	echo -e "$message" | mail -s " Memory usage monitoring" rick.mercado0629@gmail.com
	if [[ "$freespace" -gt 60]] && [[ "$freespace" -lt 90]];then
	message="Warning: Memory limit is between 60 to 90 percent"
	echo -e "$message" | mail -s " Memory usage monitoring" rick.mercado0629@gmail.com
	fi
fi
