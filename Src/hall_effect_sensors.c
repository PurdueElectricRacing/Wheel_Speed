#include "hall_effect_sensors.c"
#include "gs1001.h"
#include "ins_fm17n.h"



/** void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
 * 	-- Input Compare capture callback handler
 *
 *		@param: TIM_HandleTypeDef *htim
 *		@brief: determines which timer is being interrupted on
 *		@retvalue: none
 *	  **/

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == LEFT_WHEEL_TIM || htim->Instance == RIGHT_WHEEL_TIM)
	{
		calculate_wheel_speed(htim);
	}
	else if (htim->Instance == KOOLANCE_TIM)
	{
		calculate_flow_speed(htim);
	}

}
