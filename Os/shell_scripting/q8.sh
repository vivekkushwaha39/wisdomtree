#!/bin/bash

var=$[ cat /etc/passwd | grep $noida ]
if [ -z $var ]
then 
echo "noida not found"
else
echo "noida found : $var"
fi

