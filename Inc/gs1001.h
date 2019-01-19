#ifndef GS1001_h
#define GS1001_h

#include "hall_effect_sensors.h"

//#define RIGHT_WHEEL_TIM TIM3
//#define LEFT_WHEEL_TIM 	TIM2
//#define TOOTH_ANGLE 	(180.0f / 11.0f)
//#define TOOTH_COUNT		22
//
//#define LEFT_WHEEL_LED 	LD6_Pin
//#define RIGHT_WHEEL_LED	LD3_Pin
//#define LED_Port		GPIOD
//

typedef struct
{
	TIM_HandleTypeDef * htim;
	uint32_t 			count;
	uint32_t 			time_n;
	uint32_t 			time_n_minus_1;
	uint32_t			timer_count;
	uint32_t			speed;
	uint8_t 			broken;
} gs1001_t;

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
//void calculate_wheel_speed(TIM_HandleTypeDef *htim);
//void init_gs1001(gs1001_t * sensor, TIM_HandleTypeDef *htim);


#endif
