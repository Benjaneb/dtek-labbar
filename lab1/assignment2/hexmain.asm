  # hexmain.asm
  # Written 2015-09-04 by F Lundevall
  # Copyright abandonded - this file is in the public domain.

	.text
main:
	li	$a0,17		# change this to test different values

	jal	hexasc		# call hexasc
	nop			# delay slot filler (just in case)	

	move	$a0,$v0		# copy return value to argument register

	li	$v0,11		# syscall with v0 = 11 will print out
	syscall			# one byte from a0 to the Run I/O window
	
stop:	j	stop		# stop after one run
	nop			# delay slot filler (just in case)

  # You can write your own code for hexasc here
  #

hexasc:
	andi	$v0,$a0,0xF	# Bit mask 4 least significant bits
	slti	$t0,$v0,10	# Check if value is 0-9
	
	addi	$v0,$v0,48	# Increment to ASCII 0-9
	bne	$t0,$zero,return # Only increment more if value is greater than 9
	addi	$v0,$v0,7	# Increment to ASCII A-F
return:
	jr	$ra