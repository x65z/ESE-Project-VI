#include "../include/pcanFunctions.h"
#include "../include/databaseFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>  
#include <errno.h>
#include <unistd.h> 
#include <signal.h>
#include <string.h>
#include <fcntl.h>    					// O_RDWR
#include <unistd.h>
#include <ctype.h>
#include <libpcan.h>   					// PCAN library


// Globals
// ***********************************************************************************************************
HANDLE h;
HANDLE h2;
TPCANMsg Txmsg;
TPCANMsg Rxmsg;
TPCANMsg RxmsgOLD;
DWORD status;

// Code
// ***********************************************************************************************************

// Functions
// *****************************************************************
int pcanTx(int id, int data){
	h = LINUX_CAN_Open("/dev/pcanusb32", O_RDWR);		// Open PCAN channel

	// Initialize an opened CAN 2.0 channel with a 125kbps bitrate, accepting standard frames
	status = CAN_Init(h, CAN_BAUD_125K, CAN_INIT_TYPE_ST);

	// Clear the channel - new - Must clear the channel before Tx/Rx
	status = CAN_Status(h);

	// Set up message
	Txmsg.ID = id; 	
	Txmsg.MSGTYPE = MSGTYPE_STANDARD; 
	Txmsg.LEN = 1; 
	Txmsg.DATA[0] = data; 

	sleep(1);  
	status = CAN_Write(h, &Txmsg);

	// Close CAN 2.0 channel and exit	
	CAN_Close(h);
}

int pcanRx(int num_msgs){
	int i = 0;

	// Open a CAN channel 
	h2 = LINUX_CAN_Open("/dev/pcanusb32", O_RDWR);

	// Initialize an opened CAN 2.0 channel with a 125kbps bitrate, accepting standard frames
	status = CAN_Init(h2, CAN_BAUD_125K, CAN_INIT_TYPE_ST);

	// Clear the channel - new - Must clear the channel before Tx/Rx
	status = CAN_Status(h2);

	// Clear screen to show received messages
	system("@cls||clear");

	// receive CAN message  - CODE adapted from PCAN BASIC C++ examples pcanread.cpp
	printf("\nReady to receive message(s) over CAN bus\n");
	
	// Read 'num' messages on the CAN bus
	while(i < num_msgs) {
		while((status = CAN_Read(h2, &Rxmsg)) == PCAN_RECEIVE_QUEUE_EMPTY){
			sleep(1);
		}
		if(status != PCAN_NO_ERROR) {						// If there is an error, display the code
			printf("Error 0x%x\n", (int)status);
			//break;
		}
										
		if(Rxmsg.ID != 0x01 && Rxmsg.LEN != 0x04) {		// Ignore status message on bus	
			printf("  - R ID:%4x LEN:%1x DATA:%02x \n",	// Display the CAN message
				(int)Rxmsg.ID, 
				(int)Rxmsg.LEN,
				(int)Rxmsg.DATA[0]);
		i++;
		}
	}
	

	// Close CAN 2.0 channel and exit	
	CAN_Close(h2);
	//printf("\nEnd Rx\n");
	return ((int)Rxmsg.DATA[0]);						// Return the last value received
}

int RelayMessage(int num_msgs){
		int i = 0;

	// Open a CAN channel 
	h2 = LINUX_CAN_Open("/dev/pcanusb32", O_RDWR);

	// Initialize an opened CAN 2.0 channel with a 125kbps bitrate, accepting standard frames
	status = CAN_Init(h2, CAN_BAUD_125K, CAN_INIT_TYPE_ST);

	// Clear the channel - new - Must clear the channel before Tx/Rx
	status = CAN_Status(h2);

	// Clear screen to show received messages
	system("@cls||clear");

	// receive CAN message  - CODE adapted from PCAN BASIC C++ examples pcanread.cpp
	printf("\nReady to receive message(s) over CAN bus\n");
	
	// Read 'num' messages on the CAN bus
	while(i < num_msgs) {
		while((status = CAN_Read(h2, &Rxmsg)) == PCAN_RECEIVE_QUEUE_EMPTY){
			sleep(1);
		}
		if(status != PCAN_NO_ERROR) {						// If there is an error, display the code
			printf("Error 0x%x\n", (int)status);
			//break;
		}
										
		if(Rxmsg.ID != 0x01 && Rxmsg.LEN != 0x04) {		// Ignore status message on bus	
		
		
		if(Rxmsg.ID == RxmsgOLD.ID && Rxmsg.DATA[0] == RxmsgOLD.DATA[0]) {				
		}
		else{
			printf("  - R ID:%4x LEN:%1x DATA:%02x \n",	// Display the CAN message
				(int)Rxmsg.ID, 
				(int)Rxmsg.LEN,
				(int)Rxmsg.DATA[0]);	
				
				switch (Rxmsg.ID) 
		{
			case ID_EC_TO_ALL:    //ID 101 (Elevator Controller)
				switch (Rxmsg.DATA[0]) 
				{
					case 0x00:
						printf("Elevator Moving\n");
						break;
						
					case 0x01:
						printf("Elevator at floor 1\n");
						db_setFloorNum(1);
						break;
					
					case 0x02:
						printf("Elevator at floor 2\n");
						db_setFloorNum(2);
						break;
						
					case 0x03:
						printf("Elevator at floor 3\n");
						db_setFloorNum(3);
						break;
						
					case 0x04:
						printf("Elevator Moving\n");
						break;
						
					case 0x05:
						printf("Elevator at floor 1\n");
						db_setFloorNum(1);
						break;
					
					case 0x06:
						printf("Elevator at floor 2\n");
						db_setFloorNum(2);
						break;
									
					case 0x07:
						printf("Elevator at floor 3\n");
						db_setFloorNum(3);
						break;
									
					default:
						printf("Elevator car request error\n");
						sleep(3);
						break;
				}
				break;
							
			case ID_CC_TO_SC:    //ID 200 (Elevator Car)
				switch (Rxmsg.DATA[0]) 
				{
					case 0x00:
						pcanTx(ID_SC_TO_EC, 0x01); //should disable the elevator (Emergency Stop)
						break;
						
					case GO_TO_FLOOR1:
						pcanTx(ID_SC_TO_EC, GO_TO_FLOOR1);
						break;
					
					case GO_TO_FLOOR2:
						pcanTx(ID_SC_TO_EC, GO_TO_FLOOR2);
						break;
						
					case GO_TO_FLOOR3:
						pcanTx(ID_SC_TO_EC, GO_TO_FLOOR3);
						break;
						
					default:
						printf("Elevator car request error\n");
						sleep(3);
						break;
				}
				break;
				
			case ID_F1_TO_SC:    //ID 201 (Floor 1)
				pcanTx(ID_SC_TO_EC, GO_TO_FLOOR1);
				break;
			
			case ID_F2_TO_SC:    //ID 202 (Floor 2)
				pcanTx(ID_SC_TO_EC, GO_TO_FLOOR2);
				break;
			
			case ID_F3_TO_SC:    //ID 203 (Floor 3)
				pcanTx(ID_SC_TO_EC, GO_TO_FLOOR3);
				break;
				
			default:
				printf("Error on input values");
				sleep(3);
				break;
			}	
				
				
		}
		i++;
		}
		
		
		
		
		RxmsgOLD = Rxmsg;
		
	}

	// Close CAN 2.0 channel and exit	
	CAN_Close(h2);
	//printf("\nEnd Rx\n");
	return ((int)Rxmsg.DATA[0]);						// Return the last value received
}
