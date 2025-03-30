#include "ADC.h"
#include "common_macros.h"
#include <avr/io.h>


//void ADC_init(const ADC_Config *config) {
//
//    /* Set Reference Voltage */
//    ADMUX = (config->ref_volt << REFS0);
//
//
//    ADCSRA = (1 << ADEN) | config->prescaler;
//
//    /* Enable Auto Trigger if required */
//    if (config->auto_trigger) {
//        ADCSRA |= (1 << ADATE);
//    }
//}
//
//uint16 ADC_readChannel(uint8 channel_num) {
//    /* Select ADC channel (0-7) */
//    ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);
//
//    /* Start Conversion */
//    SET_BIT(ADCSRA, ADSC);
//
//    /* Wait for conversion to complete */
//    while (BIT_IS_CLEAR(ADCSRA, ADIF));
//
//    /* Clear ADIF */
//    SET_BIT(ADCSRA, ADIF);
//
//    /* Return ADC result */
//    return ADC;
//}


void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 01 to choose AVCC = 5v as reference voltage
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (1<<REFS0);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

