##############################################
# Program Name: Assignment 2 Keyboard shift
# Programmer: Max Waldt
# Date 03/12/15
###########################################
# Replacement a letter with
# the letter to its left on the keyboard
# I am only using alphabetical characters
# I don't want my head to explode
###########################################

	.data	# Data declaration section
test: .asciiz "EPTF"
GOODKEY: .asciiz "QAZWSXEDCRFVTGBYHNUJMIKOLP"
BADKEY: .asciiz	 "WSXEDCRFVTGBYHNUJMIK<OLP:{"
CAPS: .asciiz	"\n Turn on capslock, it will be easier...\n\n"
INPT: .asciiz	"\n Input an upper-case string: "
OUTP: .asciiz	"\n Input string: "
FIXD: .asciiz	"\n Fixed string: "

TERM: .asciiz	"\n\n Program Terminating..."

buffer: .space 20
compare: .space 20

STR1:	.asciiz "\nInput = "
STR2:	.asciiz "\nOutput = "
	.globl	main
	.text
	
###########################################
main:		# Start of code section
	jal			caps
	jal			readInput
	jal			printInput
	move		$t3, $t0
	jal			countInputLength
#	sub			$t8, $t8, 1				#to remove the carriage return char in index count
	jal			fixString
	jal			printFixed
	b 			Exit
	
###########################################
caps:
	li			$v0, 4
	la			$a0, CAPS
	syscall	
	jr			$ra
	
###########################################
readInput:
#####prompt
	li			$v0, 4
	la			$a0, INPT
	syscall	
	li 			$v0, 8
####read in
	#la			$t0, test
	la			$a0, buffer
	li 			$a1, 20
	move 		$t0, $a0
	move		$s0, $t0
	syscall
####return
	jr			$ra
###########################################
printInput:
####text
	li			$v0, 4
	la			$a0, OUTP
	syscall
####repeat input string
	la			$a0, buffer
	move		$a0, $s0
	li			$v0, 4
	syscall
	
####return
	jr			$ra

###########################################
fixString:
	#compares user input to value in bad string
	#gets a number
	#index to that number in the good string
	#append that to the outstring
	la			$a0, compare
	li			$a1, 20
	move		$t6, $a0				#address of manipulated string
	move		$s1, $t6
	move		$t7, $t0				#copy of initial input
	li			$t3, 0					#to be used to compare to good/bad keyboard
	li			$t4, 0					#outer counter, for fix loop
	li			$t5, 0					#outer char at index
	
fixLoop:
	lb			$t9, 0($t7)
	li			$t1, 0					#inner index counter, to find index of good/bad chars in arrays
	la			$t3, BADKEY				#load bad string
	la			$s7, countCharBad		#finding what index the bad char is at
	jalr		$s8, $s7
	la			$t3, GOODKEY			#load good string
	la			$s7, returnCharGood		#returning good char at that index
	jalr		$s8, $s7
	
	beqz		$t8, fixEnd				#if we have accounted for all characters
	sub			$t8, $t8, 1				#decrement count of remaining chars
	add			$t7, 1
	add			$t6, 1
	b			fixLoop					#else repeat loop
	
fixEnd:
	li			$s2, 10
	sb			$s2, ($t6)
	jr			$ra

###########################################
countCharBad:							#method will be great for counting how long a string is
	lb			$t2, 0($t3)
	beq			$t2, $t9, countCharBadEnd
	add			$t3, 1					#increment address
	add			$t1, $t1, 1				#increment counter
	b			countCharBad
	
countCharBadEnd:
	jr			$s8

###########################################
returnCharGood:							#method will be great for counting how long a string is
	lb			$t2, 0($t3)
	beqz		$t1, countCharGoodEnd
	add			$t3, 1					#increment address
	sub			$t1, $t1, 1				#decrement counter
	
	b			returnCharGood
	
countCharGoodEnd:
	sb			$t2, ($t6)
	jr			$s8

###########################################
countInputLength:
	lb			$t2, 0($t3)
	beqz		$t2, countInputLengthEnd
	add			$t3, 1					#increment address
	add			$t8, $t8, 1				#increment counter
	b			countInputLength
	
countInputLengthEnd:
	jr			$ra

###########################################
printFixed:
####text
	li			$v0, 4
	la			$a0, FIXD
	syscall
	
####print fixed input string
	li			$v0, 4
	la			$a0, compare
	move		$a0, $s1
	syscall
	
####return
	jr			$ra

###########################################
Exit:
	li		$v0, 4
	la		$a0, TERM
	syscall
	
	li			$v0, 10
	syscall
# END OF PROGRAM
