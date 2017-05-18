/*
* Dice Project Beta Version
* Created by Matthew Martin
*/

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include "pindefine.h"


uint8_t i = 0;
uint8_t dice[6]={0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D};
uint8_t die1;
uint8_t die2;




int main(void){

  // -------- Inits --------- //
  //Set outputs
  DDRB = 0x7F;
  DDRD = 0x7F;
  //pull PC5 high using internal pull up resistors
  PORTC |= (1<<PC5);

  srand ();

  // ------ Event loop ------ //

  while (1)
	  {
//Roll the dice
	  if ((PINC & (1<<PC5)) == 0)
	{
		while(i < 10){   //Flash lights to make you think it's thinking.  Also acts as a test to make sure all LEDs are functioning.
		  DICE1 |= 0x7f;
	   	  _delay_ms(30);
	   	  DICE2 |= 0x7F;
 	  	  _delay_ms(30);
	  	  DICE1 = ~DICE1;
	  	  _delay_ms(30);
 	  	  DICE2 = ~DICE2;
 	  	  _delay_ms(30);
 	  	  i ++;
 	  	  die1 = rand() %6;
 	  	  die2 = rand() %6;
		}
	}

	  else {
		  	  i = 0; //reset roll counter
		  	  //display dice
		  	  DICE1 = dice[die1];
		  	  DICE2 = dice[die2];
		   }
	  }
	                                                    /* End event loop */
  
  return 0;                            				/* This line is never reached */
  }
