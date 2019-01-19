///***************************************************************************
//**     Name of File: hall_effect_sensors.c
//*
//*     Authors (Include Email):
//*       1. Name  Chris Fallon     Email fallon2@purdue.edu
//*
//*     File dependents: (header files, flow charts, referenced documentation)
//*       1. ins_fm17n.h
//*
//*     File Description: initializes the koolance timer interrupt and calculates the flow speed
//*
//*
//***************************************************************************/
//
//#include "ins_fm17n.h"
//
//extern ins_fm17n_t g_koolance;
//
//void init_ins_fm17n(TIM_HandleTypeDef *htim, ins_fm17n_t * sensor)
//{
//		sensor->htim = htim;
//		sensor->count = 0;
//		sensor->time_n = 0;
//		sensor->time_n_minus_1 = 0;
//		sensor->speed = 0;
//		sensor->timer_count = 0;
//		sensor->broken = false;
//
//		if (HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_2) != HAL_OK)
//		{
//			sensor->broken = true;
//		}
//}
//
//void calculate_flow_speed(TIM_HandleTypeDef *htim)
//{
//
//	ins_fm17n_t * sensor;
//	uint32_t time_delta = 0;
//	float speed = 0;
//
//	sensor = &g_koolance;
//
//	//hit counter for the rotor
//	sensor->count++;
//	//get the current timer value for the sensor
//	sensor->timer_count = __HAL_TIM_GET_COUNTER(htim);
//
//	sensor->time_n_minus_1 = sensor->time_n;
//	sensor->time_n = __HAL_TIM_GET_COMPARE(htim, TIM_CHANNEL_2);		//current time gets stored in the sensor's current time stamp
//	time_delta = sensor->time_n - sensor->time_n_minus_1;
//
//	//if the time delta > 0, then we calculate speed, otherwise we divide by 0
//	if (time_delta > 0)
//	{
//
//	}
//}
//
