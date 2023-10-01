## Test pressing BTN3 and BTN2 at the same time. What happens? Why?
We check the status of all buttons in seperate if-statements that check each bit corresponding to each button. If BTN2 & BTN3 are pressed the result would be 0b011. The status of the switches SW4 through SW1 is retrieved by calling getsw. The condition (buttons & 0x2) checks if BTN3 is pressed. Since it is, the value of the switches (SW4 to SW1) is inserted into the second most significant digit of mytime. The same is done with BTN2 and  (buttons & 0x1), it is then inserted in the third most significant digit of mytime. Thus, when BTN3 and BTN2 are pressed simultaneously, both the second and third most significant digits of mytime are updated with the value of the switches.

## Three device-registers for input/output control are TRISE, TRISESET, and TRISECLR. Their functions are related. How? What are the differences?
Relation: 
In PIC32 microcontrollers, registers are often accompanied by SET and CLR counterpart registers to facilitate easy manipulation of individual bits without affecting other bits. All three registers (TRISE, TRISESET, and TRISECLR) manipulate the data direction of port E pins. They work on the same base memory but provide different mechanisms to manipulate it.

Differences:

TRISE provides direct read/write access to configure port E pins. TRISESET only sets specific bits in TRISE without affecting others. TRISECLR only clears specific bits in TRISE without affecting others.

TRISE:
    This is the data direction register for port E. If a bit in TRISE is set (1), the corresponding pin on port E is configured as an input. Writing to TRISE directly changes the configuration of port E pins.
TRISESET:
    This register is used to set specific bits in the TRISE register without affecting other bits. Writing a '1' to a particular bit position of TRISESET will set the corresponding bit in TRISE (thus, setting the corresponding port E pin as an input). Writing a '0' to a bit position has no effect.

TRISECLR:
    This register is used to clear specific bits in the TRISE register without affecting other bits. Writing a '1' to a particular bit position of TRISECLR will clear the corresponding bit in TRISE (thus, setting the corresponding port E pin as an output). Writing a '0' to a bit position has no effect.

## In the generated assembly code, in which MIPS register will the return values from functions getbtns and getsw be placed in. You should be able to answer this question without debugging the generated assembly code.
For both getbtns and getsw functions which return an int, the return value will be placed in the $v0 register in the generated assembly code.
In the MIPS calling convention, the return value from a function is placed in the $v0 register.

## In this exercise, we explained which bits that should be used in Port D and Port E. How can you find this information in the PIC32 and ChipKIT manuals? Be prepared to demonstrate how to find this information in the manuals. Advice: check the lecture slides from lecture 5 for ideas.
In section 4 of the PIC32 data sheet the memory organisation is presented. Here you can find the register you're looking for and see in the table what virtual address it's located at as well as which bits are used. (Port E is on page 73)
http://ww1.microchip.com/downloads/en/DeviceDoc/61143H.pdf