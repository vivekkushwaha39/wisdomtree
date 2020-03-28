#!/bin/bash
read -p "file name is: " filename

if [ -e $filename ]
then
if [ -s $filename ]
then
echo "file is not empty"
else 
echo "file is empty"
fi

else
echo "file does not exists"
fi

