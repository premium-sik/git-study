	.file	"hello.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.section	.rodata
.LC0:
	.string	"%d : %lld %llx\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$100, -44(%rbp)
	movl	$200, -40(%rbp)
	movl	$999, -36(%rbp)
	movl	$100, -32(%rbp)
	movl	$200, -28(%rbp)
	movl	$300, -24(%rbp)
	movl	$400, -20(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	sumArray3@PLT
	movl	%eax, -36(%rbp)
	movq	stdout(%rip), %rax
	leaq	-32(%rbp), %rsi
	leaq	-32(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	movq	%rsi, %r8
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	-32(%rbp), %esi
	movl	-32(%rbp), %ecx
	movl	-32(%rbp), %edx
	movq	stdout(%rip), %rax
	movl	%esi, %r8d
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movq	stdout(%rip), %rax
	leaq	-32(%rbp), %rsi
	leaq	-32(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	movq	%rsi, %r8
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	-24(%rbp), %edx
	movq	stdout(%rip), %rax
	leaq	-32(%rbp), %rcx
	leaq	8(%rcx), %rsi
	leaq	-32(%rbp), %rcx
	addq	$8, %rcx
	movq	%rsi, %r8
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	-16(%rbp), %edx
	movq	stdout(%rip), %rax
	leaq	-32(%rbp), %rcx
	leaq	16(%rcx), %rsi
	leaq	-32(%rbp), %rcx
	addq	$16, %rcx
	movq	%rsi, %r8
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
