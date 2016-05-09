hold=90
threshold2=95

freemem=$(($(free -m |awk 'NR==2 {print $3}') * 100))

usage=$(($freemem / 512))

if [[ "$usage" -gt "$threshold"]];

then

/etc/init.d/service_name restart

     if [ "$usage" -gt "$threshold2" ]

     then

     echo "The memory usage has reached $usage% on $HOSTNAME." | mail -s "High Memory Usage Alert" rick.mercado0629@gmail.com


     fi
fi
