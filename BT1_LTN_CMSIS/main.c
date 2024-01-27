#include "stm32f10x.h"


uint32_t Ticks = 0;

void SysTick_Handler(void) {
    Ticks++;
		if (Ticks == 500){
				Ticks = 0;
				GPIOC->ODR ^= GPIO_ODR_ODR13;
		}
}

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; 
    GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13); 
    GPIOC->CRH |= GPIO_CRH_MODE13_0; 

    SysTick->LOAD = SystemCoreClock / 1000 - 1; 
    SysTick->CTRL |= 	 SysTick_CTRL_ENABLE_Msk
											|SysTick_CTRL_TICKINT_Msk
											|SysTick_CTRL_CLKSOURCE_Msk;

    while (1) {

    }
}
