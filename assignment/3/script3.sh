#!/bin/bash

while true; do
	read -p 'Enter a number: ' number

	digit=0
	reverse=0
	digits_sum=0

	while [ $number -gt 0 ]
	do
		digit=$(( $number % 10 ))
		digits_sum=$(( $digit + $digits_sum))
		reverse=`expr $reverse \* 10 + $digit` 
		number=$(( $number / 10 ))
	done

	echo "Reverse number is: $reverse"
	echo "Sum of digits is: $digits_sum"	
done

