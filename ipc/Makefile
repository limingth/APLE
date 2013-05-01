all:
	gcc p1.c -o p1
	gcc p2.c -o p2

t1:
	cat f2 | ./p1 > f1 

t2:
	cat f1 | ./p2 > f2

test:
	cat f2 | ./p1 > f1 &
	cat f1 | ./p2 > f2
