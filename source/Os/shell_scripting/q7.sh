#!/bin/bash
read -p "first no: " n1
read -p "second no: " n2

echo "enter a for addition"
echo "enter b for subtraction"
echo "etter c for multiply"
echo "enter d for division"

read option

case $option in

a)
echo $[ $n1 + $n2 ];;

b)
echo $[ $n1 - $n2 ];;

c)
echo $[ $n1 * $n2 ];;

d)
echo $[ $n1 / $n2 ];;

*)
echo invalid operation;;

esac

