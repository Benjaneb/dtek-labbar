.text
	addi	$a0,$zero,8	# n: number to calculate factorial of
	beq	$a0,$zero,stop	# Special case if n=0
	addi    $a1, $a0, -1
factorial_loop:
	beq	$a1,$zero,stop
	addi	$a2,$a1,0	# Addition counter
multiply_loop:
	add	$a3,$a3,$a0	# Increment temp with a0, a1 times
	addi	$a2,$a2,-1
	beq	$a2,$zero,stop_multiply	# Stop adding when counter reaches a1
	beq	$zero,$zero,multiply_loop
stop_multiply:
	addi	$a1,$a1,-1			# Decrement a1
	addi	$a0,$a3,0			# Move temp to a0
	add	$a3,$zero,$zero			# Reset a3
	beq	$zero,$zero,factorial_loop	# Multiply n-1 with previous
stop:
	addi	$v0,$a0,0
	beq	$zero,$zero,stop