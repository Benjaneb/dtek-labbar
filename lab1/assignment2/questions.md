## Your subroutine hexasc is called with an integer-value as an argument in register $a0, and returns a return-value in register $v0. If the argument is 17, what is the return-value? Why?
17 becomes 1 because the bits of values above 15 overflow over the four most significant bits. Since the subroutine only deals with the four most significant bits, which in this case would be 0001, it returns 1.

## If your solution contains a conditional-branch instruction: which input values cause the instruction to actually branch to another location? This is called a taken branch.
Values below 10 cause the branch to be taken because the others get further incremented.