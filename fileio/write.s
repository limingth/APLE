	.file	"write.c"
	.globl	msg
	.data
	.type	msg, @object
	.size	msg, 14
msg:
	.ascii	"hello, world!\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	$14, 8(%esp)
	movl	$msg, 4(%esp)
	movl	$1, (%esp)
	call	write
	movl	$0, (%esp)
	call	_exit
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
