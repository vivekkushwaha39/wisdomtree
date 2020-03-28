#!/bin/bash
read -p "first string: " n1
read -p "second string: " n2

var1=$( echo $n1  |wc -m )
var2=$( echo $n2  |wc -m )

if [ $var1 -gt $var2 ]
then 
echo "string1 is greater"

elif [ $var1 -lt $var2 ]
then 
echo "string2 is greater"
 
else echo "both strings are equal"


fi




   
