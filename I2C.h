/*
 * I2C Driver for AVR Atmega32
 *
 *  Created on: Apr, 17, 2017
 *      Author: Vagobeka
 */

#ifndef I2C_H_
#define I2C_H_

#include "Types.h"
#include "Dio.h"

/*Control Register Bits*/
#define I2C_ENABLE         2         	//TWEN
#define STOP               4            //TWSTO
#define START              5	  		//TWSTA
#define ENABLE_ACK         6   		    //TWEA
#define INT_FLAG           7			//TWINT

/*General Call*/
#define GeneralCall_BIT    0
#define GeneralCallON      1
#define GeneralCallOFF     0

/*Status*/
#define TW_START           0x08
#define TW_REP_START       0x10

#define TW_MT_ARB_LOST     0x38
#define TW_MR_ARB_LOST     0x38

#define TW_MT_SLA_ACK      0x18
#define TW_MT_DATA_ACK     0x28
#define TW_MT_SLA_NOT_ACK  0x20
#define TW_MT_DATA_NOT_ACK 0x30

#define TW_MR_SLA_ACK      0x40
#define TW_MR_DATA_ACK     0x50
#define TW_MR_SLA_NOT_ACK  0x48
#define TW_MR_DATA_NOT_ACK 0x58



/********** I2C APIs ************/

/*Master*/
void I2C_vidMasterInit(void);
void I2C_vidStart(void);
void I2C_vidStop(void);
/*slave*/
void I2C_vidSlaveInit(u8 slaveAddress,u8 generalCall);
void I2C_vidListenToBus(void);
/*Sending & Receiving (Master or Slave)*/
void I2C_vidSend(u8 data);
u8 I2C_u8ReceiveAck(void);
u8 I2C_u8ReceiveNotAck(void);
u8 I2C_u8GetStatus(void);



#endif /* I2C_H_ */
