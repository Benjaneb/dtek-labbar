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

  volatile int16_t *trisd = TRISD;
  *trisd |= 0x7F0; // 0111 1111 0000


  // Set prescaling to 1
  volatile int16_t *t2conset = T2CONSET;
  *t2conset = 0x12;
  
  // Clear timer
  volatile int16_t *tmr2 = TMR2;
  *tmr2 = 0;

  // Set period
  volatile int16_t *pr2 = PR2;
  *pr2 = 10;

  // Reset timer2 interrupt
  volatile int16_t *ifs0clr = IFSCLR(0);
  *ifs0clr = 0x0100;
  
  return;
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
  volatile int32_t *ifs0 = IFS(0);
  if (*ifs0 & 0x0100)
  {
    // Reset timer2 interrupt
    volatile int16_t *ifs0clr = IFSCLR(0);
    *ifs0clr = 0x0100;

    time2string( textstring, mytime );
    display_string( 3, textstring );
    display_update();
    tick( &mytime );
    display_image(96, icon);
  }

  passedTicks++;
}
