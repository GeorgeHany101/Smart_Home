#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"

#define MOTOR_PORT_ID PORTB_ID

#define MOTOR_IN1_PIN_ID PIN0_ID
#define MOTOR_IN2_PIN_ID PIN1_ID
#define MOTOR_EN1_PIN_ID PIN3_ID

typedef enum{
	CW, A_CW, STOP
}DcMotor_State;

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
