#!/bin/bash

awk -F ',' '{
	name=$1
	value=$2
	price=$3

	if (value !~ /^[0-9]+$/ || price !~ /^[0-9]+(\.[0-9]+)?$/) {
		print "Ошибка в строке:", $0
		exit 1
	}
	
	total_value[name] += value
	total_price[name] += value*price
}

END {
	printf "%-20s%-15s%-15s%-15s\n", "Name", "Average Value", "Average Price", "Total price"
	for (name in total_value) {
		avg_price = total_price[name] / total_value[name]
		printf "%-20s%-15d%-15.2f%-15.2f\n", name, total_value[name], avg_price, total_price[name]
	}
}' table.csv
