## If the argument value in register $a0 is zero, which instructions in your subroutine are
executed? How many times each? Why?
Only the first decrementation and the return instruction are executed because the branch checks if $a0 > 0 right at the start.

## Repeat the previous question for a negative number: -1.
The same.