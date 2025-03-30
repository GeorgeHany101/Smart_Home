#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"


#define TEMP_SENSOR_CHANNEL_ID         1
#define TEMP_SENSOR_MAX_VOLT_VALUE     1.5
#define TEMP_SENSOR_MAX_TEMPERATURE    150


uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
