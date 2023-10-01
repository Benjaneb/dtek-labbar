#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

// Gets states of toggle switches
int getsw( void )
{
    return (PORTD >> 8) & 0xF;
}

// Gets states of buttons
int getbtns(void)
{
    return (PORTD >> 5) & 0x7;
}