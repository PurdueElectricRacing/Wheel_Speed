#include "ins_fm17n.h"

extern ins_fm17_t g_koolance;

void init_ins_fm17n(TIM_HandleTypeDef *htim, ins_fm17n_t * sensor)
{
		sensor->htim = htim;
		sensor->count = 0;
		sensor->time_n = 0;
		sensor->time_n_minus_1 = 0;
		sensor->speed = 0;
		sensor->timer_count = 0;
		sensor->broken = 0;

		if (HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_2) != HAL_OK)
		{
			sensor->broken = 1;
		}
}

void calculate_flow_speed(TIM_HandleTypeDef *htim)
{

	ins_fm17n_t * sensor;
	uint32_t time_delta = 0;
	float speed = 0;

	//hit counter for the teeth
	sensor->count++;
	//get the current timer value for the sensor
	sensor->timer_count = __HAL_TIM_GET_COUNTER(htim);

	sensor->time_n_minus_1 = sensor->time_n;
	sensor->time_n = __HAL_TIM_GET_COMPARE(htim, TIM_CHANNEL_2);		//current time gets stored in the sensor's current time stamp
	time_delta = sensor->time_n - sensor->time_n_minus_1;

	//if the time delta > 0, then we calculate speed, otherwise we divide by 0
	if (time_delta > 0)
	{
		speed = (TOOTH_COUNT * 1000 * 60 * ( TOOTH_ANGLE / time_delta) ) / 360;
		sensor->speed = SCALAR * speed;
	}
}

