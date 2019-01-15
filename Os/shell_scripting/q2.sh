#!/bin/bash
echo “Enter two integers!!”
read -p "enter number one: " n1
read -p "enter number two: " n2
if [ -z $n1 ] || [ -z $n2 ]
then 
echo "Show error"
else 
var1=$[ $n1 + $n2 ]
echo $var1
fi


