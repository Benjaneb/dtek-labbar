# Explain if the read operation or the write operation, or both operations are clocked (updated at the clock edge). Why is it implement this way?
Only the write operation is clocked since you want to make sure you're only writing to the registers when you actually want to. Minimizing the time slot this is possible minimizes the risk of accidental writes.

# Explain the semantics of reading from and writing to $0, and how you implemented this behavior.
$0 is a read-only register that always returns the value 0. Any attempts to write to it are ignored, ensuring its value remains unchanged.
We didn't make an actual register but instead just connected a constant to the line where the register would've been.

# How many bits of data can this register file store? If the address width was the same size as for a complete 32-bits MIPS processor, how many bits would in such a case such register file store?
7*32=224
31*32=992