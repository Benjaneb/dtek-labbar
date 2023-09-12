## What is the effect of the assembler directive .global? Why is the directive particularly
important in this assignment? The teachers will help you with this if necessary.
.globl makes a label accessible outside a file. In this assignment it's important because the C files call the delay and time2string subroutines. When compiling without .globl, the compiler will comlain about these undefined symbols.
