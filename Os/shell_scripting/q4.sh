#!/bin/bash
read -p "enter number one: " n1
n2=1
until [ $n1 -lt $n2 ]
do
echo "$n2"
n2=$(( $n2+1 ))
done






