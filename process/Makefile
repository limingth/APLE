all:
	gcc argv.c
	-rm add sub
	ln -s a.out add
	ln -s a.out sub
	gcc exec.c -o exec
	./exec

test:
	-./a.out
	echo upper a.out is ok!
