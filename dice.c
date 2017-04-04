/*
* Dice Project Beta Version
* Created by Matthew Martin
*/

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */


int main(void) {

  // -------- Inits --------- //
  //Use all bits in DDRB as outputs
  DDRB = 0xff;    
  //All Segments on
  PORTB = 0xFF;                             

  // ------ Event loop ------ //
  while (1) {
   
    //just a lazy countown test to play with code.
    PORTB = PORTB;
    _delay_ms(1000);
    PORTB = PORTB -1;
  }                                                  /* End event loop */
  return 0;                            /* This line is never reached */
}
