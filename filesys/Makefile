all:
	gcc mye2fs.c
	./a.out fs
#	./a.out fs2
#	./a.out fs4

init:
	dd if=/dev/zero of=fs count=1024 bs=1k
	dd if=/dev/zero of=fs2 count=1024 bs=2k
	dd if=/dev/zero of=fs4 count=1024 bs=4k
	mke2fs fs
	mke2fs -b 2048 fs2
	mke2fs -b 4096 fs4
