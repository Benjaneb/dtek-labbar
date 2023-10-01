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
  volatile uint8_t *trise = 0xbf886100;
  *trise = 0; // Set as output

  volatile uint16_t *trisd = TRISD;
  *trisd |= 0x7F0; // 0111 1111 0000

  volatile uint16_t *pr2 = PR2;
  *pr2 = 10;

  *IFSCLR(0) = 0x0100;
  *T2CONSET = 0x10;
  
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

  // Update clock when timer clocks
  if (IFS(0) & 0x0100)
  {
    *IFSCLR(0) = 0x0100;

    time2string( textstring, mytime );
    display_string( 3, textstring );
    display_update();
    tick( &mytime );
    display_image(96, icon);
  }

  passedTicks++;
}
