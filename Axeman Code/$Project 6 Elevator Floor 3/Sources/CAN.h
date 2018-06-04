// CAN.h Header file containing macros and constants

// Definitions
#define INIT_MODE                   0x01      // Ref: MC9S12C128V1 pg. 291: CANCTL0
#define NORMAL_MODE                 0x00      // Ref: MC9S12C128V1 pg. 291: CANCTL0
#define CAN_ENABLED_MODE_BUS_CLOCK  0xC0      // Ref: MC9S12C128V1 pg. 291: CANCTL1
#define LOOPBACK_MODE_BUS_CLOCK     0xE0      // Ref: MC9S12C128V1 pg. 291: CANCTL1
#define BIT_0_125K                  0x07      // k = 8, SJW = 0
#define BIT_1_125K                  0x23      // TSEG1 = 4, TSEG2 = 3
#define FOUR_16BIT_FILTERS          0x10      // Defines four 16 bit filters
#define CAN_SYNC                    0x10       


// Error codes
#define CAN_NO_ERROR                0x00
#define CAN_ERR_BUFFER_FULL         0x01


// Definitions for filters
  // Acceptance code definitions 
    #define ACC_CODE_ID100          0x2000        // ID100
    #define ACC_CODE_ID101          0x2020        // ID101 (see AN3034 pg 10-11 for explanation)
    #define ACC_CODE_ID200          0x4000       // ID200
    #define ACC_CODE_ID100_HIGH     ((ACC_CODE_ID100 & 0xFF00) >> 8)  // Select high order bits then bit shift by 8 bits
    #define ACC_CODE_ID100_LOW      (ACC_CODE_ID100 & 0x00FF)
    #define ACC_CODE_ID101_HIGH     ((ACC_CODE_ID101 & 0xFF00) >> 8)  // Select high order bits then bit shift by 8 bits 
    #define ACC_CODE_ID101_LOW      (ACC_CODE_ID101 & 0x00FF)
    #define ACC_CODE_ID200_HIGH     ((ACC_CODE_ID200 & 0xFF00) >> 8)  // Select high order bits then bit shift by 8 bits 
    #define ACC_CODE_ID200_LOW      (ACC_CODE_ID200 & 0x00FF)
 
     
  
  // Mask code definitions
    #define MASK_CODE_ST_ID 0x0007   // Last 3 bits are garbage bits (not used, dont care)
    #define MASK_CODE_ST_ID_ELEVATOR 0x0067   //Last 3 are garbage, good for 0xXX0-0xXX3  
    #define MASK_CODE_ST_ID_HIGH    ((MASK_CODE_ST_ID & 0xFF00) >> 8)
    #define MASK_CODE_ST_ID_LOW     (MASK_CODE_ST_ID & 0x00FF)   
    #define MASK_CODE_ST_ID_ELEVATOR_HIGH    ((MASK_CODE_ST_ID_ELEVATOR & 0xFF00) >> 8)  
    #define MASK_CODE_ST_ID_ELEVATOR_LOW     (MASK_CODE_ST_ID_ELEVATOR & 0x00FF) 

// Definition of IDs
    #define ST_ID_100 0x20000000    // Standard ID 0x100 formatted to be loaded in IDRx registers in Tx buffer
    #define ST_ID_101 0x20200000    // Standard ID 0x101 formatted to be loaded in IDRx registers in Tx buffer
    #define ST_ID_200 0x40000000    // Standard ID 0x200 formatted to be loaded in IDRx registers in Tx buffer
    #define ST_ID_201 0x40200000    // Standard ID 0x201 formatted to be loaded in IDRx registers in Tx buffer
    #define ST_ID_202 0x40400000    // Standard ID 0x202 formatted to be loaded in IDRx registers in Tx buffer
    #define ST_ID_203 0x40600000    // Standard ID 0x203 formatted to be loaded in IDRx registers in Tx buffer
    #define ST_ID_300 0x60000000    // Standard ID 0x300 formatted to be loaded in IDRx registers in Tx buffer


// Function for initializing the CAN module
void CANInit(void);

// Function for transmitting CAN messages
unsigned char CANTx(unsigned long id, unsigned char priority, unsigned char length, unsigned char *txdata);

// Function for receiveing CAN messages via interrupt
void interrupt CANRxISR(void);


