#include <gpio.h>


#define   RCC_APB2ENR    (uint32_t*) 0x40021018
uint8_t EtatBouton;
GPIO_Struct GPIO_InitStruct ;

int main ()
{	GPIO_InitStruct.GPIO_PIN = GPIO_PIN_13 ; 
GPIO_InitStruct.GPIO_Mode = GPIO_Mode_InputFloating ; 
GPIO_Init (GPIOC, &GPIO_InitStruct) ; 
GPIO_InitStruct.GPIO_PIN = GPIO_PIN_5;
GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OutputPP2Mhz; 
GPIO_Init (GPIOA, &GPIO_InitStruct) ; 
	
 while (1)
  {		
		//Test Push Button
 		//Read Oush Button State (0=Pressed, 1=Released)
		EtatBouton=GPIO_TestPin(GPIOC,GPIO_PIN_13);
		
	if (EtatBouton==0)  //If Pressed, Led ON	
	GPIO_SetPin(GPIOA, GPIO_PIN_5);
	else //Released, Led OFF
	GPIO_ResetPin(GPIOA, GPIO_PIN_5);				
	}
	}
