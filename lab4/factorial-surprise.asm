.text
	addi	$a0,$zero,8	# n: number to calculate factorial of
	beq	$a0,$zero,stop	# Special case if n=0
	addi    $a1, $a0, -1
factorial_loop:
	beq	$a1,$zero,stop
	mul	$a0,$a0,$a1
	addi	$a1,$a1,-1			# Decrement a1
	beq	$zero,$zero,factorial_loop	# Multiply n-1 with previous
stop:
	addi	$v0,$a0,0
	beq	$zero,$zero,stop
