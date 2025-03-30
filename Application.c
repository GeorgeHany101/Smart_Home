#include "ADC.h"
#include "Buzzer.h"
#include "flame.h"
#include "LCD.h"
#include "LDR.h"
#include "LED.h"
#include "LM35.h"
#include "Motor.h"


void main(void){
	ADC_init();
	LCD_init();
	LEDS_init();
	DcMotor_Init();
	FlameSensor_init();
	Buzzer_init();

	uint8 critDisplayDone = 0;
	uint8 normDisplayDone =0;

	while(1){
		while (FlameSensor_getValue()){
			if (!critDisplayDone){
				LCD_clearScreen();
				LCD_moveCursor(0,0);
				Buzzer_on();
				LCD_displayString("Critical Alert!");
				critDisplayDone = 1;
				normDisplayDone = 0;
			}
		}
		critDisplayDone = 0;
		Buzzer_off();
		if (!normDisplayDone){
			LCD_clearScreen();
			LCD_moveCursor(0,3);
			LCD_displayString("FAN IS OFF");
			LCD_moveCursor(1,0);
			LCD_displayString("Temp= ");
			LCD_moveCursor(1,8);
			LCD_displayString("LDR=   %");
			normDisplayDone = 1;
		}

		LCD_moveCursor(1,5);
		if (LM35_getTemperature() >= 100){
			LCD_integerToString(LM35_getTemperature());
		}
		else{
			LCD_integerToString(LM35_getTemperature());
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(1,12);
		if (LDR_getLightIntensity() >= 100){
			LCD_integerToString(LDR_getLightIntensity());
		}
		else {
			LCD_integerToString(LDR_getLightIntensity());
			LCD_displayCharacter(' ');
		}

		if (LDR_getLightIntensity()<15){
			LED_on(red);
			LED_on(green);
			LED_on(blue);
		}
		else if (LDR_getLightIntensity()<=50 && LDR_getLightIntensity()>=16){
			LED_on(red);
			LED_on(green);
			LED_off(blue);
		}
		else if (LDR_getLightIntensity()<=70 && LDR_getLightIntensity()>=51){
			LED_on(red);
			LED_off(green);
			LED_off(blue);
		}
		else {
			LED_off(red);
			LED_off(green);
			LED_off(blue);
		}

		if (LM35_getTemperature() >= 40){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,100);
		}
		else if (LM35_getTemperature() >= 35 && LM35_getTemperature() < 40){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,75);
		}
		else if (LM35_getTemperature()>= 30 && LM35_getTemperature() < 35){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,50);
		}
		else if (LM35_getTemperature() >= 25 && LM35_getTemperature() < 30){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,25);
		}
		else {
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP,0);
		}
	}
}
