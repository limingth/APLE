#! /bin/sh
#SRC="1.c 2.c 3.c"
SRC=`ls *.c`
LINES=`wc -l hello.c | awk '{ print $1 ;}'`
ROOT=$PWD
echo $1
echo $ROOT
DIR=$ROOT/$1
echo target dir is $DIR
cd $DIR
SRC=`ls`
#exit

echo $SRC
echo $LINES

SUM=0
FILES=0


recursive()
{
	SRC=`ls`
	for FILE in $SRC; do
		if [ -f $FILE ]; then
			echo -n - $FILE 
			CFILE=`echo $FILE | grep ".c$"`
			if [ -n "$CFILE" ]
			then
				#echo  '\t\t' is c file
				LINES=`wc -l $FILE | awk '{ print $1 ;}'`
				echo  '\t\t'$LINES
				SUM=$(($SUM + $LINES))
				FILES=$(($FILES + 1))
			else
				#echo  '\t\t' not c file
				echo  '\t\t'.
			fi
		fi

		if [ -d $FILE ]; then
			echo + $FILE 
			cd $FILE
				recursive
			cd ..
		fi
	done
}

recursive
echo total files is $FILES
echo total lines is $SUM

exit 

for FILE in $SRC; do
	#echo $FILE
	[ -d $FILE ]
	#echo $FILE is $?

	if [ -d $FILE ]; then
		echo + $FILE 
		cd $FILE
		ls
		cd ..
	fi

	if [ -f $FILE ]; then
		echo -n - $FILE 
		CFILE=`echo $FILE | grep ".c$"`
		if [ -n "$CFILE" ]
		then
			#echo  '\t\t' is c file
			LINES=`wc -l $FILE | awk '{ print $1 ;}'`
			echo  '\t\t'$LINES
			SUM=$(($SUM + $LINES))
		else
			#echo  '\t\t' not c file
			echo  '\t\t'.
		fi
	fi 
done

echo total lines is $SUM
