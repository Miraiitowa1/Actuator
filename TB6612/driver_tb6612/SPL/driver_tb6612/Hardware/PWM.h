#ifndef __PWM_H
#define __PWM_H

//引脚定义
#define PWMA_GPIO_PORT           GPIOB
#define PWMA_GPIO_PIN            GPIO_Pin_0
#define PWMA_GPIO_CLK            RCC_APB2Periph_GPIOB

#define PWMA_TIM                 TIM3
#define PWMA_TIM_CLK             RCC_APB1Periph_TIM3

#define PWMB_GPIO_PORT           GPIOB
#define PWMB_GPIO_PIN            GPIO_Pin_1
#define PWMB_GPIO_CLK            RCC_APB2Periph_GPIOB

#define PWMB_TIM                 TIM3
#define PWMB_TIM_CLK             RCC_APB1Periph_TIM3


//函数声明
void PWM_Init(void);
void PWM_SetCompare3(uint16_t Compare);

#endif
