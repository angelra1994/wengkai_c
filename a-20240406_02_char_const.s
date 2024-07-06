	.file	"20240406_02_char_const.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "a=%d\12\0"
.LC1:
	.ascii "b=%d\12\0"
.LC2:
	.ascii "u=%d\12\0"
.LC3:
	.ascii "v=%d\12\0"
.LC4:
	.ascii "\350\257\267\350\276\223\345\205\245\346\260\264\347\232\204\345\244\270\350\204\261\346\225\260>:\0"
.LC5:
	.ascii "%d\0"
.LC6:
	.ascii "\346\260\264\347\232\204\345\244\270\350\204\261\346\225\260\357\274\214num=%d\12\0"
	.align 8
.LC8:
	.ascii "%d\345\244\270\350\204\261\347\232\204\346\260\264\346\234\211%e\344\270\252\346\260\264\345\210\206\345\255\220\12\0"
.LC9:
	.ascii "\350\257\267\350\276\223\345\205\245\345\234\206\347\232\204\345\215\212\345\276\204>:\0"
.LC10:
	.ascii "\345\234\206\347\232\204\345\215\212\345\276\204\357\274\214r=%d\12\0"
	.align 8
.LC12:
	.ascii "\345\215\212\345\276\204\344\270\272%d\347\232\204\345\234\206\357\274\214\345\221\250\351\225\277\346\230\257c=%f\351\235\242\347\247\257\346\230\257s=%f\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movb	$70, -1(%rbp)
	movb	$67, -2(%rbp)
	movb	$98, -3(%rbp)
	movb	$66, -4(%rbp)
	movsbl	-1(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movsbl	-2(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movsbl	-3(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movsbl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-20(%rbp), %eax
	imull	$950, %eax, %eax
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC7(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -8(%rbp)
	pxor	%xmm0, %xmm0
	cvtss2sd	-8(%rbp), %xmm0
	movl	-20(%rbp), %eax
	movq	%xmm0, %rdx
	movq	%rdx, %rcx
	movq	%rcx, %xmm0
	movapd	%xmm0, %xmm2
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-24(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-24(%rbp), %edx
	movl	-24(%rbp), %eax
	imull	%edx, %eax
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%eax, %xmm1
	movsd	.LC11(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -12(%rbp)
	movl	-24(%rbp), %eax
	addl	%eax, %eax
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%eax, %xmm1
	movsd	.LC11(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	pxor	%xmm1, %xmm1
	cvtss2sd	-12(%rbp), %xmm1
	pxor	%xmm0, %xmm0
	cvtss2sd	-16(%rbp), %xmm0
	movl	-24(%rbp), %eax
	movq	%xmm1, %rdx
	movq	%rdx, %rcx
	movq	%rcx, %xmm1
	movq	%rdx, %rcx
	movq	%xmm0, %rdx
	movq	%rdx, %r8
	movq	%r8, %xmm0
	movapd	%xmm1, %xmm3
	movq	%rcx, %r9
	movapd	%xmm0, %xmm2
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	.LC12(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC7:
	.long	1879967165
	.long	994189894
	.align 8
.LC11:
	.long	1293080650
	.long	1074340347
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
