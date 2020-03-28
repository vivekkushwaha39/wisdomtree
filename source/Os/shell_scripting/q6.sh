#!/bin/bash
echo “Enter two integers!!”
read -p "enter number one: " n1
read -p "enter number two: " n2
read -p "enter number three: " n3
if [ -z $n1 ] || [ -z $n2 ] || [ -z $n3 ]
then
echo "Show error"
elif [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
echo "$n1 is greater"
elif [ $n2 -gt $n3 ]
then 
echo "$n2 is greater"

else
echo "$n3 is greater"
fi
