# Explain how you have implemented the control signals for the beq instruction. Why is this a correct solution?
We checked for the OP code being 4 and in that case enabled Branch and chose 110 as ALUControl instead of 010.

# Be prepared to explain why the RegDst control signal or the AluSrc signal is hooked up to certain signals. You should be prepared to explain this using the following figure.
We didn't hook up RegDst or AluSrc to the signal indicating the beq instruction. It doesn't matter what RegDst is since we're not writing to any register and ALUSrc must be 0 to read the second register into the ALU.