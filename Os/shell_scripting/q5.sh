#!/bin/bash
read -p "enter number one: " n1
read -p "enter number two: " n2
read -p "enter number three: " n3
if [ -z $n1 ] || [ -z $n2 ] || [ -z $n3 ]
then
echo "show error"
else
var1=$[ $n1 + $n2 + $n3 ]
echo $var1
fi


