#!/bin/bash

colnum=$(cat ./run.sh | wc -l)
if [ $colnum -gt 10 ];
then
    # method-1
    # grep -n "" ./run.sh | grep 10 | cut -d: -f2
    # method-2
    # sed -n '10,22p' ./run.sh
    # method-3
    awk '{if(NR==10){print $0}}' ./run.sh
else
    echo "less than 10 line"
fi
