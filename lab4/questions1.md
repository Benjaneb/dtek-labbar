# Explain how each of the ALU functions are defined. In particular, you need to be able to explain how subtraction works, including the use of two's complement.
Subtraction is done by inverting the second signal and adding them with a carry in signal (adds 1). Two's complement of a number is found by inverting all the bits (one's complement) and then adding 1 to the result.

# How did you implement the logic for the Zero output port? Did you consider any alternatives? Be prepared to explain your design choices.
We used a 32:1 NOR gate. You could also use 5 layers of 2:1 NOR gates propagating the signal to 1 bit.

# What is the purpose of the ALU? Why are several functions grouped together into one component?
It's purpose is to perform mathematical operations on two inputs and compute the result. Through using the select bit we can optimize and choose over which gates are used and which operations take place.