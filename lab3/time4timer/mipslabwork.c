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

char textstring[] = "text, more text, and even more text!";
int timeoutcount = 0;

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  volatile int8_t *trise = 0xbf886100;
  *trise = 0; // Set as output

  // Initialize timer2

  T2CON = 0;          // Set prescaling to 1:1, stop timer
  
  TMR2 = 0;           // Clear timer
  
  T2CONSET = 0x70;    // Prescaling 256:1

  PR2 = 80000000 / 256 * 0.1; // Set period 

  IPCSET(2) = 0xC;    // Priority level 3
  IPCSET(2) = 0x1;    // Subpriority level 1
  
  IFSCLR(0) = 0x0100; // Reset timer2 interrupt
  
  IECSET(0) = 0x100;  // Enable interrupts for timer2

  T2CONSET = 0x8000;  // Start timer
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  static int passedTicks = 0;
  volatile char *porte = 0xbf886110;

  *porte = passedTicks;

  // Set clock digits to switch value on button presses
  int btnStates = getbtns();
  if (btnStates)
  {
    int swStates = getsw();

    if (btnStates & 0x4) // BTN4
      mytime = (mytime & 0x0FFF) | (swStates << 12);
    if (btnStates & 0x2) // BTN3
      mytime = (mytime & 0xF0FF) | (swStates << 8);
    if (btnStates & 0x1) // BTN2
      mytime = (mytime & 0xFF0F) | (swStates << 4);
  }

  // Update clock when there's an interrupt from timer2
  if (IFS(0) & 0x0100)
  {
    timeoutcount++;
    IFSCLR(0) = 0x0100; // Reset timer2 interrupt

    if (timeoutcount >= 10)
    {
      time2string( textstring, mytime );
      display_string( 3, textstring );
      display_update();
      tick( &mytime );
      display_image(96, icon);
      timeoutcount = 0;
    }
  }

  passedTicks++;
}
