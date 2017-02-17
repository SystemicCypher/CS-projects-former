# xSpim MedianNumbers.asm program
# 
#

#  Data Area - allocate and initialize variables
.data

	# TODO: Complete these declarations / initializations

next:	.asciiz "Enter the next number:\n"

median:	.asciiz "Median: "
	
test:	.asciiz "TEST\n"
	
array:	.word 0, 0, 0


#Text Area (i.e. instructions)
.text


main:

	# TODO: Write your code here
	la $s0, array
	li $t0, 3
	li $t1, 1
loop:
	beq $t0, $zero, findmed
	li $v0, 4
	la $a0, next
	syscall

	li $v0, 5
	syscall

	
	sw $v0, ($s0)
	addi $s0, $s0, 4
	sub $t0, $t0, $t1
	j loop

findmed:
	la $s0, array
	lw $t0, ($s0)
	lw $t1, 4($s0)
	lw $t2, 8($s0)
	
	slt $s3, $t0, $t1
	slt $s4, $t1, $t2

	beq $s3, $s4, mid

	bgt $s3, $s4, chk

	slt $s5, $t0, $t2
	
	beq $s5, $zero, last
	j first

chk:	
	slt $s5, $t0, $t2
	beq $s5, $zero, first
	j last

mid:
	lw $t0, 4($s0)
	j med
	
last:
	lw $t0, 8($s0)
	j med
	
first:
	lw $t0, ($s0)
	j med
	
med:
	li $v0, 4
	la $a0, median
	syscall

	move $a0, $t0
	li $v0, 1
	syscall


exit:

	# Exit
	ori     $v0, $0, 10
	syscall

