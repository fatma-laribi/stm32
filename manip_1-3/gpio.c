#include <gpio.h>

uint8_t GPIO_TestPin(GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
uint32_t etat=GPIOx->IDR & GPIO_PIN ;
if (etat==0x0) return 1;
	else return 0;
}

void GPIO_SetPin(GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BSRR = GPIO_PIN;
	
}

void GPIO_ResetPin (GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BRR = GPIO_PIN;
	
}
void GPIO_Init(GPIO_Typedef* GPIOx, GPIO_Struct* GPIO_InitStruct){
	int i;
for (i=0; i<16; i++)
	{
		int16_t IsPin = (GPIO_InitStruct->GPIO_PIN) & (1<<i);
		if ( IsPin!=0){
			if(i<8){
				GPIOx->CRL &= ~(uint32_t)0xF<<4*i;
				GPIOx->CRL |= GPIO_InitStruct->GPIO_Mode<<4*i;
			}
			else{
				GPIOx->CRH &= ~ (uint32_t)0xF<<(4*(i-8));
				GPIOx->CRH |= GPIO_InitStruct->GPIO_Mode<<(4*(i-8));
			}
		}
	}
	}

