#!/bin/bash	

	TOTAL_MEMORY=$(free  | grep Mem: | awk '{print $2}')
        echo " Total Memory is $TOTAL_MEMORY "
        TOTAL_USED=$(free  | grep Mem: | awk '{print $3}')
        echo " Total Used Memory is $TOTAL_USED "
        freespace=$(free  | grep Mem: | awk '{print $3/$2 *100}')
        p=${freespace%%.*}
        echo " Percentage used space is $freespace "
        if [[ $p -ge 90 ]]; then
        tenprocess=$(ps aux | head -1 ; ps aux | sort -nk +4 | tail -7)
        echo "$(hostname)::  Memory almost out of space Date: $(date)"
        echo " Top 10 Processes that consume memory are :: " 
        echo  "$tenprocess"
#        message= "Critical : Memory limit exceeded 90 percent"
        mail -s '$(hostname) ::  Memory check critical' rick.mercado0629@gmail.com <<< "Critical : Memory limit exceeded 90 percent Date: $(date) current value is $p and the top ten processes that consume memory are $tenprocess"
        fi
        if [[ $p -gt 60 && $p -lt  90 ]]; then
        echo "$(hostname):: Warning memory between 60 to 90 percent today $(date)"
#        message1="Warning : Memory limit is between 60 to 90 percent"
        mail -s '$(hostname) ::  Memory check warning' rick.mercado0629@gmail.com <<< "Warning : Memory limit is between 60 to 90 percent Date: $(date) current value is $p"
        fi
        if [[ $p -lt 60 ]]; then
        echo "Memory check below 60 percent"
fi


