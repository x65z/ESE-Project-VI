#include <hidef.h>            /* common defines and macros */
#include "derivative.h"       /* derivative-specific definitions */
#include "CAN.h"
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include <string.h>
#include "Segments.h"


extern unsigned char RxBuff;  //shares RxBuff


unsigned long SendID = ST_ID_200;  //change based on floor location


void main(void) {
  
  int Door_Status = 0;   //0 = closed, 1 = open
  int i = 0;
  int j = 0;
  
  unsigned char errorflag = CAN_NO_ERROR;
  volatile unsigned char Open_Button;
  volatile unsigned char Close_Button;
  volatile unsigned char Floor_1;
  volatile unsigned char Floor_2;
  volatile unsigned char Floor_3;
  volatile unsigned char Abort;
  
  unsigned char txbuff[1] = {0x00};
  
  DDRA = 0xFF;
  DDRB = 0x0F;
  DDRJ = 0x3F;
  
  
  
  CANInit();
   
  while (!(CANCTL0 & CAN_SYNC));       // Wait for MSCAN to synchronize with the CAN bus
  
  CANRFLG = 0xC3;                      // Enable CAN Rx interrupts
  CANRIER = 0x01;                      // Clear CAN Rx flag
  EnableInterrupts;

  //errorflag = CANTx(SendID, 0x00, 1, txbuff);       //sizeof(txbuff)-1    //mainline send message    
  msDelay(250);
  
  
  
 while(1) {
  Open_Button = PTJ_PTJ6;
  Close_Button = PTJ_PTJ7;
  
  Floor_1 = PORTB_BIT5;
  Floor_2 = PORTB_BIT6;
  Floor_3 = PORTB_BIT7;
  Abort   = PORTB_BIT4;
  
  
  
  switch(RxBuff){
    case 0x01:{   //disabled, at floor 1
     
      PORTA = ONE; 
      if(Open_Button == 0){
        
        Door_Status = 1;  
        
      }
      
      break; 
    }
    case 0x02:{   //disabled, at floor 2
     
      PORTA = TWO;
      if(Open_Button == 0){
        
        Door_Status = 1;  
        
      }
      
      break;
    }
    case 0x03:{   //disabled, at floor 3
      
      PORTA = THREE;
      if(Open_Button == 0){
      
        Door_Status = 1;  
        
      }
      
      break;
    }
    case 0x05:{   //enabled, at floor 1
      
      PORTA = ONE;
      if(Open_Button == 0){
        
        Door_Status = 1;  
        
      }
      
      break;
    }
    case 0x06:{   //enabled, at floor 2
     
      PORTA = TWO;
      if(Open_Button == 0){
      
        Door_Status = 1;  
        
      }
      
      break;
    }
    case 0x07:{   //enabled, at floor 3
      
      PORTA = THREE;
      if(Open_Button == 0){
      
        Door_Status = 1;    
        
      }
      
      break;
    }
    default: {
      break;
    }
  }
  
 
  while(Door_Status == 1){
   
   PORTA = OPEN;
   Close_Button = PTJ_PTJ7;
   
   if(Close_Button == 0){
    
      Door_Status = 0;
      PORTA = CLOSE;
      
     // for(i;i<10000;i++){
        
     // }
      
     // i = 0;
    
   }
   
   errorflag = CANTx(SendID, 0x00, 1, 0x00);
    
  }
 
 
  
  
  if(Abort == 0){
   *txbuff = 0x00;
   PORTA = ABORTED;
   errorflag = CANTx(SendID, 0x00, 1, txbuff);
   
   for(i;i<3;i++){
    
    Abort = PORTB_BIT4;
    
    if(Abort == 0){
     j++;
    }
    //if(j > 2){
    // *txbuff = 0x05;
    // errorflag = CANTx(SendID, 0x00, 1, txbuff); 
    //}
    
    msDelay(1000);
    
   }
   
    i = 0;    //reset counters
    j = 0; 
   
  }
  else if(Floor_1 == 0){
   *txbuff = 0x05;
   errorflag = CANTx(SendID, 0x00, 1, txbuff); 
  } 
  else if(Floor_2 == 0){
   *txbuff = 0x06;
   errorflag = CANTx(SendID, 0x00, 1, txbuff); 
  } 
  else if(Floor_3 == 0){
   *txbuff = 0x07;
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



