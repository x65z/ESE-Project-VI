#include "../include/pcanFunctions.h"
#include "../include/databaseFunctions.h"
#include "../include/mainFunctions.h"

#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <libpcan.h>

using namespace std;




// ******************************************************************

int main() {

	int choice;
	int ID;
	int data;
	int numRx;
	int floorNumber = 1, prev_floorNumber = 1;
	TPCANMsg Message;

	while(1) {
		system("@cls||clear");
		choice = menu();
		switch (choice) {
			case 1:
				ID = chooseID();		// user to select ID depending on intended recipient
				data = chooseMsg();		// user to select message data
				pcanTx(ID, data);		// transmit ID and data
				db_setFloorNum(FloorFromHex(data)); 		// change floor number in database ** NEW **
				break;

			case 2:
				printf("\nHow many messages to receive? ");
				scanf("%d", &numRx);
				pcanRx(numRx);
				break;

			case 3:
				printf("\nNow listening to commands from the website and Bus - press ctrl-z to cancel\n");
				// Synchronize elevator db and CAN (start at 1st floor)


				while(1)
				{
					//sleep(1); //might not need

					BusToDatabase(1);
					DatabaseToBus(1);
																				// poll Bus to check for requests
				}
				break;


			case 4:
				printf("\nNow listening to commands from the floors - press ctrl-z to cancel\n");

				while(1)
				{
					sleep(1);

					RelayMessage(100);															// poll Bus to check for requests
				}
				break;



			case 5:
				return(0);

			default:
				printf("Error on input values");
				sleep(3);
				break;
		}
		sleep(1);					// delay between send/receive
	}

	return(0);
}
