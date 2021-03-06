/***************************************************************************
**     Name of File: gs1001.c
*
*     Authors (Include Email):
*       1. Name  Chris Fallon     Email fallon2@purdue.edu
*
*     File dependents: (header files, flow charts, referenced documentation)
*       1. gs1001.h, GS1001_Datasheet.pdf
*
*     File Description: Initializes and controls the GS1001 hall effect
*     					sensors used for the wheel speed measurement
*
*
***************************************************************************/


#include "gs1001.h"

extern gs1001_t g_left_wheel;
extern gs1001_t g_right_wheel;


/** void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
 * 	-- Input Compare capture callback handler
 *
 *		@param: TIM_HandleTypeDef *htim
 *		@brief: Calculates the wheel speed in RPM and stores it as an integer,
 *				scaled up by 10000 to avoid sending floats over CAN
 *		@retvalue: none
 *	  **/

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	gs1001_t * sensor;
	uint32_t time_delta = 0;
	float speed = 0;

	//each sensor has a pointer to its corresponding TIM_HandleTypeDef
	if (htim->Instance == LEFT_WHEEL_TIM)
	{
		sensor = &g_left_wheel;
	}
	else
	{
		sensor = &g_right_wheel;
	}

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


/** void init_gs1001(gs1001_t *sensor, TIM_HandleTypeDef *htim)
 *
 *		@param: gs1001_t * sensor, TIM_HandleTypeDef *htim
 *		@brief: Initializes the provided gs1001_t struct with the provided TIM_HandleTypeDef pointer
 *				and initializes all values to 0. Starts the Input Capture for the provided TIM_HandleTypeDef *
 *				in interrupt mode on channel 2 of the timer.
 *		@retvalue: none
 *	  **/
void init_gs1001(gs1001_t *sensor, TIM_HandleTypeDef *htim)
{
	sensor->htim = htim;
	sensor->count = 0;
	sensor->time_n = 0;
	sensor->time_n_minus_1 = 0;
	sensor->speed = 0;
	sensor->timer_count = 0;

	HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_2);

}
