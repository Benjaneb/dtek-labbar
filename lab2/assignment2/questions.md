## What does it mean when a function does not return a value? How do you state that in a program? How can then the function (or more precisely, the procedure) perform anything useful?
It means that the function performs some action but does not send back a result. In C this is declared by writing the return type as void. The reason it can still be useful is if has some side effect, like altering a global variable or having an output in I/O.

## How did you implement the side effect that is needed to make print_number behave correctly?
It prints to the standard output with printf.