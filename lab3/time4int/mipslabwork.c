/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;
int prime = 1234567;
int timeoutcount = 0;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  timeoutcount++;
  IFSCLR(0) = 0x0100; // Reset timer2 interrupt

  if (timeoutcount >= 10)
  {
    timeoutcount = 0;
    time2string( textstring, mytime );
    display_string( 3, textstring );
    display_update();
    tick( &mytime );
  }
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  volatile int8_t *trise = 0xbf886100;
  *trise = 0; // Set as output

  TRISD |= 0x7F0; // 0111 1111 0000

  // Initialize timer2

  T2CON = 0;    // Set prescaling to 1:1, stop timer
  
  TMR2 = 0;           // Clear timer
  
  PR2 = 10;           // Set period

  IPCSET(2) = 0xC;    // Priority level 3
  IPCSET(2) = 0x1;    // Subpriority level 1
  
  IFSCLR(0) = 0x0100; // Reset timer2 interrupt
  
  IECSET(0) = 0x100;  // Enable interrupts for timer2

  enable_interrupt();

  T2CONSET = 0x8000;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  prime = nextprime( prime );
  display_string( 0, itoaconv( prime ) );
  display_update();
}
