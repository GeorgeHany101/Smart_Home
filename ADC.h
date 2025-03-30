#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

//
///* Enumeration for Reference Voltage Options */
//typedef enum {
//    ADC_REF_AREF = 0,      // External AREF
//    ADC_REF_AVCC = 1,      // AVCC (5V)
//    ADC_REF_INT_2_56 = 3   // Internal 2.56V
//} ADC_ReferenceVoltage;
//
///* Enumeration for ADC Prescaler Options */
//typedef enum {
//    ADC_PRESCALER_2   = 1,
//    ADC_PRESCALER_4   = 2,
//    ADC_PRESCALER_8   = 3,
//    ADC_PRESCALER_16  = 4,
//    ADC_PRESCALER_32  = 5,
//    ADC_PRESCALER_64  = 6,
//    ADC_PRESCALER_128 = 7
//} ADC_Prescaler;
//
//typedef enum {
//	ADC_CHANNEL_0,
//	ADC_CHANNEL_1,
//	ADC_CHANNEL_2,
//	ADC_CHANNEL_3,
//	ADC_CHANNEL_4,
//	ADC_CHANNEL_5,
//	ADC_CHANNEL_6,
//	ADC_CHANNEL_7
//} ADC_Channel;
//
///* Enumeration for Auto Trigger Options */
//typedef enum {
//    ADC_AUTO_TRIGGER_OFF,
//    ADC_AUTO_TRIGGER_ON
//} ADC_AutoTrigger;
//
///* ADC Configuration Structure */
//typedef struct {
//    uint8 ref_volt;    // Reference Voltage
//    uint8 prescaler;   // Clock Prescaler
//    uint8 channel;     // ADC channel
//    uint8 auto_trigger; // Enable/Disable Auto Trigger
//} ADC_Config;
//
///* Function Prototypes */
//void ADC_init(const ADC_Config *config);
//
//uint16 ADC_readChannel(uint8 channel_num);

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
