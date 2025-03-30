#ifndef LED_H_
#define LED_H_

#include "std_types.h"

#define LED_PORT_ID PORTB_ID

typedef enum{
	red=5, green, blue
}LED_ID;

#define connection positive_logic

#if ((connection != positive_logic) && (connection != negative_logic))

#error "connection should either be positive_logic or negative_logic"

#endif

void LEDS_init(void);

void LED_on(LED_ID id);

void LED_off(LED_ID id);

#endif /*LED_H_*/
