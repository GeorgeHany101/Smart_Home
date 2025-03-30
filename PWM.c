#include "PWM.h"
#include "GPIO.h"
#include <avr/io.h>
#include "common_macros.h"

void PWM_Timer0_Start(uint8_t duty_cycle) {
    // Set OC0 (PB3) as an output pin
    GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

    // Set Timer0 in Fast PWM mode (WGM00 = 1, WGM01 = 1)
    SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

    // Set non-inverting mode (COM01 = 1, COM00 = 0)
    SET_BIT(TCCR0, COM01);
    CLEAR_BIT(TCCR0, COM00);

    // Set prescaler to F_CPU/1024 (CS02 = 1, CS01 = 0, CS00 = 1)
    SET_BIT(TCCR0, CS02);
    CLEAR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS00);

    // Limit duty cycle to 100%
    if (duty_cycle > 100) duty_cycle = 100;

    // Set duty cycle: OCR0 = (duty_cycle * 255) / 100
    OCR0 = (uint8)(((uint16)duty_cycle * 255) / 100);
}
