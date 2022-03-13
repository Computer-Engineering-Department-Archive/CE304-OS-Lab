#!/bin/bash

while true; do
	sd=0
	rev=0
	sum=0

	read -p 'Enter a number: ' num
	while [ $num -gt 0 ]
	do
		sd=$(( $num % 10 ))
		rev=$(( $rev * 10 + $sd ))
		sum=$(( $sd + $sum ))
		num=$(( $num / 10 ))
	done

	echo "Reverse number is: $rev"
	echo "Sum of digits is: $sum"	
done

