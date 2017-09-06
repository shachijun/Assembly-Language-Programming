.globl nCr
	.type	nCr, @function
nCr:	
	movl 0x04(%esp),%eax 	#eax = n
	cmp $13,%eax
	jnl .return0
	movl 0x08(%esp),%ebx  	#ebx = r
	movl %eax,%ecx		#ecx = eax = n
	subl %ebx,%eax		#eax = n-r
	pushl %eax		
	pushl %ecx
	call Factorial
	popl %ecx
	movl %eax,%ecx		#ecx = n!
	pushl %ebx
	call Factorial
	popl %ebx
	movl %eax,%ebx		#ebx = r!
	call Factorial		#eax = (n-r)!
	imul %ebx,%eax		#eax = r!*(n-r)!
	movl $0,%edx
	movl %eax,%ebx		#ebx = eax = r!*(n-r)!
	movl %ecx,%eax		#eax = ecx = n!
	div %ebx		#eax = n!/(n-r)!/r!
	popl %ebx
	ret	

.return0:
	movl $0,%eax	
	ret

.globl Factorial
	.type	Factorial, @function
Factorial:
	movl 0x04(%esp),%edx
	movl $1,%eax

.loop:
	cmp $0,%edx
	je .exit0
	imul %edx,%eax		#eax = eax*edx
	sub $1,%edx		#edx--
	jmp .loop

.exit0:
	ret



	
