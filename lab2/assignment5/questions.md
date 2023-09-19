## Consider AM18, AM19, and AF1. Explain why gv ends up with the incremented value, but m does not.
 - gv ends up with the incremented value because the 'fun' function directly assigns the incremented param to it.
 - m does not get further incremented inside the 'fun' function because m is passed by value, so any changes to param (the local copy of m in fun) don't affect the original m in main().

## Pointer cp is a character pointer that points to a sequence of bytes. What is the size of the cp pointer itself?
On a 32 bit system, the size of all pointers, whether they are char pointers, int pointers, or any other data type pointers, is typically 4 bytes.


## Explain how a C string is laid out in memory. Why does the character string that cp points to have to be 9 bytes?
In C a string is represented as an array of characters ending with a null terminator (null byte). The string therefore has to be one more byte to fit this null terminator.

## Which addresses have fun and main? Which sections are they located in? What kind of memory are they stored in? What is the meaning of the data that these symbols points to?
Address of fun: 9D001180 (in section AM3)
Address of main: 9D0011D8 (in section AM4)
However, the actual memory addresses where the two functions will reside in will be determined at runtime. The data in fun and main are function pointers, which are addresses that point to where the functions are stored in memory.
