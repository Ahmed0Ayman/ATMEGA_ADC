/*
 * ATMEGA_ADC.c
 *
 * Created: 5/13/2021 11:18:44 PM
 * Author : Ahmed_Ayman
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include "ADC.h"
#include <util/delay.h>


ADC_Handler_t ADC_Handler ;



int main(void)
{
	ADC_Handler.ADC_Adjust_Select = ADC_Adjust_Right ;
	ADC_Handler.ADC_Intrrupet_Select = ADC_INIT_DISABLE ;
	ADC_Handler.ADC_PreScaler = ADC_Presaler_2 ;
	ADC_Handler.ADC_TRIG_SOURCE = ADC_TRIG_FREE_RUNNING ;
	ADC_Handler.ADC_Vref_Select = ADC_Vref_AVCC ;
	ADC_INIT(&ADC_Handler);

	
	DDRD =0xff ;
	
    /* Replace with your application code */
    while (1) 
    {
		//PORTD = 0xff;//(uint8_t)ADC_Handler.ADC_Value ;

		ADC_GET_VALUE(&ADC_Handler,ADC_CH_0);
		PORTD = (uint8_t)ADC_Handler.ADC_Value ; 
		_delay_ms(500);
    }
}

