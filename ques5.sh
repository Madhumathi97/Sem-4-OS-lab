#!/bin/bash
a=$1
b=$2
sum=`expr $a + $b`
sub=`expr $a - $b`
mult=`expr $a \* $b`
echo sum is $sum
echo difference is $sub
echo multipliction is $mult
