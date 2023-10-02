## When the time-out event-flag is a "1", how does your code reset it to "0"?
IFS0 is set to register a time out event. To reset it we use the IFSCLR register access. The IFSCLR access is a special "clear" register access, which clears the bits in the register. Any bit set to 1 in the IFSCLR register will clear the bits in IFS0 register.

##  What would happen if the time-out event-flag was not reset to "0" by your code? Why?
The next time the code checks for the timeout event flag (in iterations of 'labwork'), it would still find the flag set to 1, meaning the code thinks a time out has occured without it happening.

## From which part of the code is the function user_isr called? Why is it called from there?
The function is an Interupt Service Routine. It is not directly called from the main program like other regular functions. It is rather invoked in response to specific hardware events and interrupts. When Timer 2 time-outs, it triggers an interrupt and thereby invokes user_isr.

## Why are registers saved before the call to user_isr? Why are only some registers saved?
The purpose of saving the register is to ensure that in case an interuppt occurs and the ISR handels the interrupt it dose not influnce the state of the program that was interrupted. 

The distinction between caller-saved and callee-saved registers balance efficiency and safety. Not all registers need to be saved and restored for every function call or interrupt, which would be time-consuming and wasteful. By categorizing registers and establishing conventions about their use, the system can minimize overhead while ensuring that functions and ISRs don't inadvertently step on each other's toes.

## Which device-register (or registers), and which processor-register (or registers) must be written to enable interrupts from the timer? Describe the functions of the relevant registers.
IEC (interrupt enable control), which enables interrupts for different timers depending on which bit is set to 1.
IPC (interrupt priority control), which sets the priority levels for the respective timers.