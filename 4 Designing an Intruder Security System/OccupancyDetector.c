/*
 * OccupancyDetector.c
 *
 * 2023
 * Author: Elise Heim
 Version 1.0
 */


#include <msp430.h>

int main() {
//no init func 
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // make sure MSP can be programmed, unlock it 

    P1DIR |= BIT0; //set 1.0 as output
    P1OUT &= ~BIT0; //clear red led, 1.0 

    P6DIR |= BIT6; // set 6.6 as output
    P6OUT &= ~BIT6; // clear green led, 6.6

    P4DIR &= ~BIT1; // set 4.1 as input
    P4REN |= BIT1; // enable the pull up/down resistor for 4.1
    P4OUT |= BIT1;  // as input, 4.1 controls up or down


#define ARMED_STATE 0
#define WARNING_STATE 1
#define ALERT_STATE 2

// Put some initialization here
//I will be using a made up sensor. Sorry
char sensor; //will act as sensor data
char time;
char state = ARMED_STATE;

while(1)
{
  switch (state) 
  {
    case ARMED_STATE:
    {
               if (sensor == 1) //sensor is alarmed
                   {
                     time = 0; // reset time to 0
                     state = WARNING_STATE; //move to warning state
                   }
                else
                   { 
                     P1OUT &= ~BIT0; //turn off red led, 1.0 
                     P6OUT ^= BIT6; // blink green led, 6.6
                     __delay_cycles(3000000); // 3 sec
                     time = 0; // reset time to 0
                   }
               break;
    }
    case WARNING_STATE:
    {
            P1OUT &= ~BIT0; //turn off red led, 1.0 

      if (sensor == 1) //sensor is alarmed
                   {
                     time = 0; // reset time to 0
                     P1OUT ^= BIT0; // blink red led, 1.0
                     __delay_cycles(500000); // .5 sec
                     time ++; //add time 
                   }

             if (time == 19) //if time counts to ten sec
                   {
                     time = 0; // reset time to 0
                     state = ARMED_STATE; //move to armed state
                      __delay_cycles(500000); // .5 sec
                      time ++; //add time 
                   }

                   }
                else
                   { 
                     state = ARMED_STATE; //move to armed state
                   }

               break;
    }
    case ALERT_STATE:
    {
               if (!(P4IN & BIT10) //if button 4.1 press
                   {
                     state = ARMED_STATE; //move to armed state
                   }

               P1OUT |= BIT0; //turn on red led, 1.0 

               break;
    }
  }
}





