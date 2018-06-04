#include <hidef.h>            /* common defines and macros */
#include "derivative.h"       /* derivative-specific definitions */
#include "CAN.h"
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include <string.h>
#include "Segments.h"


extern unsigned char RxBuff;  //shares RxBuff


unsigned long SendID = ST_ID_201;  //change based on floor location


void main(void) {
  
  unsigned char errorflag = CAN_NO_ERROR;
  volatile unsigned char Floor_Call;
  unsigned char txbuff[1] = {0x01};

  DDRA = 0xFF;
  DDRB = 0x7F;
 
 
  
  
  CANInit();
   
  while (!(CANCTL0 & CAN_SYNC));       // Wait for MSCAN to synchronize with the CAN bus
  
  CANRFLG = 0xC3;                      // Enable CAN Rx interrupts
  CANRIER = 0x01;                      // Clear CAN Rx flag
  EnableInterrupts;

  //errorflag = CANTx(SendID, 0x00, 1, txbuff);       //sizeof(txbuff)-1        
  msDelay(250);
   
 while(1){
  
  Floor_Call = PORTB_BIT7;
   
    switch(RxBuff){
    case 0x01:{   //disabled, at floor 1
      PORTA = ONE;          
      break; 
    }
    case 0x02:{   //disabled, at floor 2
      PORTA = TWO;
      break;
    }
    case 0x03:{   //disabled, at floor 3 
      PORTA = THREE;     
      break;
    }
    case 0x05:{   //enabled, at floor 1
      PORTA = ONE;
      break;
    }
    case 0x06:{   //enabled, at floor 2 
      PORTA = TWO;   
      break;
    }
    case 0x07:{   //enabled, at floor 3
      PORTA = THREE;
      break;
    }
    default: {
      break;
    }
  }
  
  if(Floor_Call == 0){
   errorflag = CANTx(SendID, 0x00, 1, txbuff); 
  } 
  
 }
   
  
  for(;;) {
      msDelay(250);
      msDelay(250);
      msDelay(250);
      msDelay(250);
    
     
  
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
