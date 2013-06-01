#! /bin/sh
TEST="hello world"
COUNT=100
echo $TEST
echo ${TEST}liming! 
echo $COUNT+1
echo your name is $LIMING
echo total argc = $#
echo argv $@

CNT=0
ALL=$#
SUM=0
while [ "$CNT" -lt $ALL ]; do
	CNT=$(($CNT+1))
	SUM=$(($SUM+$1))
	echo argv[$CNT] : $1
	shift
done

echo sum is $SUM
