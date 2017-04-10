/*
* Dice Project Beta Version
* Created by Matthew Martin
*/

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include "pindefine.h"
#include "stdlib.h"

uint8_t i = 0;
uint8_t dice[6]={0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D};
int die1;
int die2;

rand(void);

int main(void){

  // -------- Inits --------- //
  //Set outputs
  DDRB = 0x7F;
  DDRD = 0x7F;
  die1 = rand() %6;
  die2 = rand() %6;


  // ------ Event loop ------ //

  while (1)
	  {

	  while(i < 10){
		  DICE1 |= 0x7f;
	   	  _delay_ms(75);
	   	  DICE2 |= 0x7F;
 	  	  _delay_ms(75);
	  	  DICE2 = ~DICE2;
	  	  _delay_ms(75);
 	  	  DICE1 = ~DICE1;
 	  	  _delay_ms(75);
 	  	  i ++;
	  }

	  DICE1 = dice[die1];
	  DICE2 = dice[die2];

	  }                                                  /* End event loop */
  
  return 0;                            				/* This line is never reached */
}
