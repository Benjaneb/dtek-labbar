  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
.text
.globl delay
.globl time2string
hexasc:
	andi	$v0,$a0,0xF	# Bit mask 4 least significant bits
	slti	$t0,$v0,10	# Check if value is 0-9
	
	addi	$v0,$v0,48	# Increment to ASCII 0-9
	bne	$t0,$zero,return# Only increment more if value is greater than 9
	nop
	addi	$v0,$v0,7	# Increment to ASCII A-F
return:	jr	$ra
	nop

# Adds a delay of $a0 milliseconds
delay:
	addi	$a0,$a0,-1		# Decrement ms counter
	li	$t0,0			# Innerloop counter (make 0 for safety)
	blt	$a0,1,delayfinish		# Loop while $a0 > 0
	nop
innerloop:
	addi	$t0,$t0,1		# Decrement innerloop counter
	blt	$t0,550,innerloop	# Continue looping while $t0 < 0 (imm=930 on desktop)
	nop
	
	j	delay
	nop
delayfinish:
	jr $ra
	nop

# Converts a hexadecimal time code to a string
time2string:
	PUSH	$ra		# Save return address
	PUSH	$s0
	PUSH	$s1
	move	$s0,$a0		# Save memory address for result	
	andi	$s1,$a1,0xFF	# Save time data with bit mask of 16 least significant bits
	
	srl	$a0,$s1,12	# Shift 1st digit to four least significant bits
	jal	hexasc
	nop
	sb	$v0,0($s0)	# Save 1st ascii digit
	
	srl	$a0,$s1,8	# Shift 2nd digit to four least significant bits
	jal	hexasc
	nop
	sb	$v0,1($s0)	# Save 2nd ascii digit
	
	li	$t0,0x3A
	sb	$t0,2($s0)	# Save colon
	
	srl	$a0,$s1,4	# Shift 3rd digit to four least significant bits
	jal	hexasc
	nop
	sb	$v0,3($s0)	# Save 3rd ascii digit
	
	move	$a0,$s1		# 4th digit already at four least significant bits
	jal	hexasc
	nop
	sb	$v0,4($s0)	# Save 4th ascii digit
	
	sb	$zero,5($s0)	# Store null character
	
	POP	$s1
	POP	$s0
	POP	$ra
	jr	$ra
	nop
	