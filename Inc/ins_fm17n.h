#ifndef INS_FM17N_H
#define INS_FM17N_H

#include "hall_effect_sensors.h"

//#define KOOLANCE_TIM   TIM5

typedef struct
{
	TIM_HandleTypeDef * htim;
	uint32_t 			count;
	uint32_t 			time_n;
	uint32_t 			time_n_minus_1;
	uint32_t			timer_count;
	uint32_t			speed;
	uint8_t 			broken;
} ins_fm17n_t;


//void calculate_flow_speed(TIM_HandleTypeDef *htim);
void init_ins_fm17n(TIM_HandleTypeDef *htim, ins_fm17n_t * sensor);


#endif
