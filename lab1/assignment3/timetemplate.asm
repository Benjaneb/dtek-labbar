  # timetemplate.asm
  # Written 2015 by F Lundevall
  # Copyright abandonded - this file is in the public domain.

.macro	PUSH (%reg)
	addi	$sp,$sp,-4
	sw	%reg,0($sp)
.end_macro

.macro	POP (%reg)
	lw	%reg,0($sp)
	addi	$sp,$sp,4
.end_macro

	.data
	.align 2
mytime:	.word 0x5957
timstr:	.ascii "text more text lots of text\0"
	.text
main:
	# print timstr
	la	$a0,timstr
	li	$v0,4
	syscall
	nop
	# wait a little
	li	$a0,10000
	jal	delay
	nop
	# call tick
	la	$a0,mytime
	jal	tick
	nop
	# call your function time2string
	la	$a0,timstr
	la	$t0,mytime
	lw	$a1,0($t0)
	jal	time2string
	nop
	# print a newline
	li	$a0,10
	li	$v0,11
	syscall
	nop
	# go back and do it all again
	j	main
	nop
# tick: update time pointed to by $a0
tick:	lw	$t0,0($a0)	# get time
	addiu	$t0,$t0,1	# increase
	andi	$t1,$t0,0xf	# check lowest digit
	sltiu	$t2,$t1,0xa	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x6	# adjust lowest digit
	andi	$t1,$t0,0xf0	# check next digit
	sltiu	$t2,$t1,0x60	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa0	# adjust digit
	andi	$t1,$t0,0xf00	# check minute digit
	sltiu	$t2,$t1,0xa00	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x600	# adjust digit
	andi	$t1,$t0,0xf000	# check last digit
	sltiu	$t2,$t1,0x6000	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa000	# adjust last digit
tiend:	sw	$t0,0($a0)	# save updated result
	jr	$ra		# return
	nop

  # you can write your code for subroutine "hexasc" below this line

# Converts a hexadecimal digit to an ASCII coded digit
hexasc:
	andi	$v0,$a0,0xF	# Bit mask 4 least significant bits
	slti	$t0,$v0,10	# Check if value is 0-9
	
	addi	$v0,$v0,48	# Increment to ASCII 0-9
	bne	$t0,$zero,return# Only increment more if value is greater than 9
	addi	$v0,$v0,7	# Increment to ASCII A-F
return:	jr	$ra

# Adds a delay of $a0 milliseconds
delay:
	addi	$a0,$a0,-1		# Decrement ms counter
	li	$t0,0			# Innerloop counter (make 0 for safety)
	blt	$a0,1,delayfinish		# Loop while $a0 > 0
innerloop:
	addi	$t0,$t0,1		# Decrement innerloop counter
	blt	$t0,930,innerloop	# Continue looping while $t0 < 0
	
	j	delay
delayfinish:
	jr $ra
	nop

# Converts a hexadecimal time code to a string
time2string:
	PUSH($ra)		# Save return address
	PUSH($s0)
	PUSH($s1)
	move	$s0,$a0		# Save memory address for result	
	andi	$s1,$a1,0xFF	# Save time data with bit mask of 16 least significant bits
	
	srl	$a0,$s1,12	# Shift 1st digit to four least significant bits
	jal	hexasc
	sb	$v0,0($s0)	# Save 1st ascii digit
	
	srl	$a0,$s1,8	# Shift 2nd digit to four least significant bits
	jal	hexasc
	sb	$v0,1($s0)	# Save 2nd ascii digit
	
	li	$t0,0x3A
	sb	$t0,2($s0)	# Save colon
	
	srl	$a0,$s1,4	# Shift 3rd digit to four least significant bits
	jal	hexasc
	sb	$v0,3($s0)	# Save 3rd ascii digit
	
	move	$a0,$s1		# 4th digit already at four least significant bits
	jal	hexasc
	sb	$v0,4($s0)	# Save 4th ascii digit
	
	sb	$zero,5($s0)	# Store null character
	
	POP($s1)
	POP($s0)
	POP($ra)
	jr	$ra
	
	
