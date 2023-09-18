## How did you represent the marking of 'prime' and 'not a prime' in the memory array?
We allocated a char array with those chars at their respective indices being marked with 1 only if they where composite numbers.

## Which are the main steps in the algorithm? How have you implemented these steps?
First, every number had to be set to zero, which in the stack allocated version was done by manually looping through the array and in the heap allocated version done by simply using calloc. The actual sieve iterates over potential divisors (2 to sqrt(n)) and marking every multiple of those numbers as composite numbers by setting them to 1.

## What is the largest prime number that you can print within 2 seconds of computation? What is the largest number you can print within 10 seconds? Is it the same for print_prime.c,sieves.c, and sieves-heap.c? Why or why not?
With our implementation, both sieves.c and sieves-heap.c can calculate primes up to 2 000 000 in around a tenth of a second but sieves.c crashes with any higher input as it is not possible to allocate any bigger array on the stack.
print_prime.c could only print primes up to 1 000 000 in 2 seconds and 3 500 000 in 10 seconds.

print_prime.c takes a longer time because it doesn't save any of the previous results, like the other two programs do in an array.