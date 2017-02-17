# xSpim Demo Program
# 
#   CPE 315
#   fall 2001
#
# By: Dan Stearns
# Date:  
# Modifications: 
#	4/10/03 knico Tabbed code
#	4/10/03 knico Modified to use s registers instead of t registers
#           
#
# declare global so programmer can see actual addresses.

#  Data Area - allocate and initialize variables

	#not sure if I should leave what is above -Austin Loza
	#I just left it alone
.data

prompt:
	.asciiz "Enter the number:\n"
newline:
	.asciiz "\n"

#Text Area (i.e. instructions)
.text

main:
	#prompt input
	ori $v0, $zero, 4
	la $a0, prompt
	syscall
	#get user input
	ori $v0, $0, 5
	syscall
	#save user input	
	or $t0, $zero, $v0
	#accumulator
	ori $s0, $zero, 1
	#beginning of factorial loop
loop:
	#multiplies accumulator to n
	beq $t0, $zero, done
	mult $s0, $t0
	mflo $s0
	#sets up and prints number
	ori $v0, $zero, 1
	or $a0, $zero, $s0
	syscall
	#prints newline
	ori $v0, $zero, 4
	la $a0, newline
	syscall
	sub $t0, $t0, 1
	j loop

done:
	ori $v0, $zero, 1
	or $a0, $zero, $s0
	syscall
	ori $v0, $zero, 4
	la $a0, newline
	syscall


exit:

	# Exit
	ori     $v0, $0, 10
	syscall
