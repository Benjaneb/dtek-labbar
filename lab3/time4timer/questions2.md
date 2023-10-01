## When the time-out event-flag is a "1", how does your code reset it to "0"?
IFS0 is set to register a time out event. To reset it we use the IFSCLR register access. The IFSCLR access is a special "clear" register access, which clears the bits in the register. Any bit set to 1 in the IFSCLR register will clear the bits in IFS0 register.

##  What would happen if the time-out event-flag was not reset to "0" by your code? Why?
The next time the code checks for the timeout event flag (in iterations of 'labwork'), it would still find the flag set to 1, meaning the code thinks a time out has occured without it happening.

## Which device-register (or registers) must be written to define the time between time-out events? Describe the function of that register (or of those registers).
The device-register responsible for defining the time between time-out events for Timer 2 is PR2, which stands for Period Register 2.

## If you press BTN3 quickly, does the time update reliably? Why, or why not? If not, would that be easy to change? If so, how?
The reliability of detecting a button press depends on how frequently the button state is being checked. If BTN3 is pressed and released between two consecutive checks (polls), the press might go undetected.