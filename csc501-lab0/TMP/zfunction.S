	.text
	.globl	zfunction
	.type	zfunction, @function
zfunction:
	pushl	%ebp
	movl	%esp, %ebp
        pushl   %ebx
        sub     $0xc,%esp
        movl    0x8(%ebp),%ebx
        andl    $0xfff00fff,%ebx
        pushl   %ebx
        push    $0x0
        sarl    $0x4,%ebx
        add     $0x8,%esp
        pushl   %ebx
        pushl   $0x0
	movl    %ebx,%eax
        and     $0xfffffff,%eax
	mov     0xfffffffc(%ebp),%ebx
	leave
	ret
