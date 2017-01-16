#!/bin/bash
echo "enter 4 integers"
read a
read b
read c
read d
sum=`expr $a + $b + $c + $d`
product=`expr $a \* $b \* $c \* $d`
average=`expr $sum / 4`
echo " the sum of 4 integers is $sum"
echo " the product of 4 integers is $product"
echo " the average is $average"

