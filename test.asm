	.data
vari:	.asciiz "Print me"
rtn:	.asciiz "\n"
	
	.text
main:
	li $t0, 1
	li $t1, 3
	addu $t3, $t0, $t1
	add $a0, $t3, $zero
	li $v0, 1
	syscall

	la $a0, rtn
	li $v0, 4
	syscall

	la $a0, vari
	syscall

	la $a0, rtn
	syscall

	

	li $v0, 10
	syscall
