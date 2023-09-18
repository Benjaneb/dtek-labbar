## Explain how you get the pointer addresses to the two char arrays (text1 and text2) and the counter variable (count) in function work().
test1 and text2 are already pointers to char arrays so they could be passed directly but counter was declared as an integer so the pointer address was received by prefixing with an ampersand (&).

## What does it mean to increment a pointer? What is the difference between incrementing the pointer that points to the ASCII text string, and incrementing the pointer that points to the integer array? In what way is the assembler code and the C code different?
When incrementing a pointer, the byte adress gets incremented by the size of the type. With the string (char array) it increments the pointer by 1 and with the integer array with 4, just like with the assembler code. The difference is that it needs to be done deliberately in assembler code, and not in C.

## What is the difference between incrementing a pointer and incrementing a variable that a pointer points to? Explain how your code is incrementing the count variable.
When incrementing a pointer it is the memory address that gets incremented while when incrementing a variable it is the value that gets incremented. Our code first dereferences the count pointer and then increments the value.

## Explain a statement in your code where you are dereferencing a pointer. What does this mean? Explain by comparing with the corresponding assembler code.
while(*source != '\0')
In this statement, *source dereferences the source pointer. We are checking the value that source points to and comparing it to the null terminator.

lb	$t0,0($a0)
This assembly instruction loads the byte from address contained in register $a0 (which corresponds to source) into register $t0, which is equivelent to the derefrencing in C.

## Is your computer using big-endian or little-endian? How did you come to your conclusion? Is there any benefit of using either of the two alternatives?
Our computers are little endian, which could be verified with the endian_proof function that printed the count variable with the least LSB in the beginning.
With little endian, certain mathematical operations might be slightly faster since the least significant byte is processed first.
Big endian can be more intuitive for humans to read and understand since it follows our regular number system.
