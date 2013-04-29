.data

msg:
	.ascii "hello, world\n"
	len = . - msg


	.global _start
.text	
_start:
	# write(1, msg, len)
	movl $len, %edx
	movl $msg, %ecx
	movl $1, %ebx
	movl $4, %eax
	int $0x80

	# exit(100);
	movl $144, %ebx
	movl $1, %eax
	int $0x80

