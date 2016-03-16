##############################################
# Program Name: Lab 4
# Programmer: Max Waldt
# Date 02/3/15
#############################################
# $t0 will be what is shifted and logically anded to determine what is in a set
# $t1 will be the copy of a set
# $t9 for printing values
#############################################
# Cross References:
# v0: N,
# fp8: Sum
###########################################

	.data	# Data declaration section
SET1: .asciiz	"\n Set1 = 0xaaaaaaaa "
SET2: .asciiz	"\n Set2 = 0x24924924 "
BSET: .asciiz	"\n { "
SPCE: .asciiz	", "
ESET: .asciiz	" } "
UNIO: .asciiz   "\n The union of sets 0xaaaaaaaa and 0x24924924: "
INTS: .asciiz	"\n The intersection of sets 0xaaaaaaaa and 0x24924924: "
TERM: .asciiz	"\n Program Terminating..."

	.globl	main
	.text
	
###########################################
main:		# Start of code section

	li		$s0, 0xaaaaaaaa
	li		$s1, 0x24924924
	li		$t0, 1
	jal		Init
	la		$t8, InitPrint
	jalr	$t9, $t8
	
#Element in Set Ops
	la		$t8, ElementInSet
	li		$t3, 2
	jalr	$t9, $t8
	
	li		$t3, 6
	jalr	$t9, $t8
	
	li		$t3, 9
	jalr	$t9, $t8
	
#Union
	la		$t8, Union
	jalr	$t9, $t8
	
#Intersection
	la		$t8, Intersection
	jalr	$t9, $t8
	
	
	b		Exit
###########################################
InitPrint:
#Print Set 1
	li		$v0, 4					#print set1 string
	la		$a0, SET1
	syscall
	
#Handle Set 1
	jal		Init
	move	$s2, $s0				#bring set1 to the set to be modified
	jalr	$t7, $t6 				#print set call

#Print Set 2
	li		$v0, 4					#print set2 string
	la		$a0, SET2
	syscall
	
#Handle Set 2
	jal		Init
	move	$s2, $s1				#bring set2 to the set to be modified
	jalr	$t7, $t6 				#print set call
	
#Return from Section
	jr		$t9
###########################################
ElementInSet:
	la		$t6, FindNum
	move	$t2, $t0
	jalr	$t7, $t6
	
	move	$t2, $t1
	jalr	$t7, $t6

###########################################
Union:
	li		$v0, 4					#print Union text
	la		$a0, UNIO
	syscall
	
	jal		Init
	or		$s2, $s1, $s0
	jalr	$t7, $t6
	
	jr		$t9
###########################################
Intersection:
	li		$v0, 4					#print Interesction Text
	la		$a0, INTS
	syscall
	
	jal		Init
	and		$s2, $s1, $s0
	jalr	$t7, $t6
	
	jr		$t9
###########################################
Init:
	li 		$s3, 1					#set up value to 0x00000001
	li		$s4, 1					#set up index in for loop
	li		$s5, 33					#set up end point in for loop
	la		$t6, PrintSet			#save PrintSet address
	jr		$ra
	
###########################################
PrintSet:
	li		$v0, 4					#print set bracket start
	la		$a0, BSET
	syscall
	
	#Loop Part
	la 		$t4, ShiftLoop			#Set Loop address
	jalr	$t5, $t4				#Set Return from loop
	
	li		$v0, 4					#print set bracket end
	la		$a0, ESET
	syscall
	jr		$t7
	
###########################################
PrintNum:
	li		$v0, 1
	move	$a0, $s4
	syscall
	
	li		$v0, 4
	la 		$a0, SPCE
	syscall
	
	b		IndexUp

###########################################
ShiftLoop:
	li		$s6, 0					#reinitialize variable
	and 	$s6, $s2, $s3			#s2 will be the original set, s3 will be after ands
	mul		$s3, $s3, 2				#increase checking position in $t0
	
	bgtz	$s6, PrintNum
	b		IndexUp
###########################################
IndexUp:
	addi	$s4, $s4, 1				#increment index
	bne		$s5, $s4, ShiftLoop
	jr		$t5
	
###########################################	
FindNum:
	li		$s3, 1
	li		$s4, 1
	li
	la		$t4, FindLoop

###########################################	
FindNum:
	
###########################################	
Exit:
	li		$v0, 4
	la		$a0, TERM
	syscall
	
	li			$v0, 10				#terminate program run and
	syscall							#return control to the system
# END OF PROGRAM
