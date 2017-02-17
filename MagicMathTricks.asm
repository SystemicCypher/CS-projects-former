	.globl phoneReq
	.globl addFourfifty
	.globl addItself
	.globl subTen
	.globl subTwenty
	.globl multEighty
	.globl divFour
	.globl divEight
	.globl divFive

	.data
phoneReq:	.asciiz "What are the first 3 digits of your phone number?  "
addFourfifty:	.asciiz "\nAdd 450 \n"
addItself:	.asciiz "\nAdd it to itself \n"
subTen:		.asciiz "\nSubtract 10 \n"
subTwenty:	.asciiz "\nSubtract 20 \n"
multEighty:	.asciiz "\nMultiply by 80 \n"
divFour:	.asciiz "\nDivide by 4 \n"
divEight:	.asciiz "\nDivide by 8 \n"
divFive:	.asciiz "\nDivide by 5 \n"

	.text
main:
	li $v0, 4
	la $a0, phoneReq
	syscall

	li $v0, 5
	syscall

	or $a0, $zero, $v0
	li $v0, 1
	syscall

	or $s0, $zero, $a0
	la $a0, addItself
	li $v0, 4
	syscall

	or $a0, $zero, $s0
	add $a0, $a0, $s0
	or $s0, $zero, $a0
	li $v0, 1
	syscall

	
	la $a0, multEighty
	li $v0, 4
	syscall
	
	li $t0, 80
	mult $s0, $t0
	mflo $s0
	or $a0, $zero, $s0
	li $v0, 1
	syscall

	la $a0, addFourfifty
	addi $s0, $s0, 450
	li $v0, 4
	syscall

	or $a0, $zero, $s0
	li $v0, 1
	syscall

	la $a0, divFive
	li $t0, 5
	div $s0, $t0
	mflo $s0
	li $v0, 4
	syscall

	li $v0, 1
	or $a0, $zero, $s0
	syscall

	la $a0, subTen
	li $v0, 4
	syscall

	li $t0, 10
	sub $s0, $s0, $t0
	li $v0, 1
	or $a0, $zero, $s0
	syscall

	la $a0, divFour
	li $v0, 4
	syscall

	srl $s0, $s0, 2
	li $v0, 1
	or $a0, $zero, $s0
	syscall

	la $a0, subTwenty
	li $v0, 4
	syscall

	li $t0, 20
	sub $s0, $s0, $t0
	or $a0, $zero, $s0
	li $v0, 1
	syscall

	la $a0, divEight
	li $v0, 4
	syscall

	srl $s0, $s0, 3
	or $a0, $zero, $s0
	li $v0, 1
	syscall

	li $v0, 10
	syscall
	
	
	
	
