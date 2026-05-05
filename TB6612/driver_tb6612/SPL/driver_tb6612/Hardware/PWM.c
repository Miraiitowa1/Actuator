#include "stm32f10x.h"                  // Device header
#include "PWM.h"

/**
  * 函    数：PWM_Init()
  * 参    数：无
  * 返 回 值：无
  * 说    明：PB0对应TIM3_CH3 PB1对应TIM3_CH4
  */
void PWM_Init(void)
{
	//开启时钟
	RCC_APB1PeriphClockCmd(PWMA_TIM_CLK, ENABLE);			
	RCC_APB2PeriphClockCmd(PWMA_GPIO_CLK, ENABLE);			
	
	//GPIO初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = PWMA_GPIO_PIN;						
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(PWMA_GPIO_PORT, &GPIO_InitStructure);							
																	
	
	//配置时钟源
	TIM_InternalClockConfig(PWMA_TIM);		
	
	//时基单元初始化
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;						// 定义结构体变量
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;     		// 时钟分频，选择不分频
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; 		// 计数器模式，选择向上计数
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;                 		// 计数周期，即ARR的值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;               		// 预分频器，即PSC的值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;   

	TIM_TimeBaseInit(PWMA_TIM, &TIM_TimeBaseInitStructure);            
	
	//输出比较初始化 
	TIM_OCInitTypeDef TIM_OCInitStructure;									// 定义结构体变量
	TIM_OCStructInit(&TIM_OCInitStructure);                         		// 结构体初始化
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;               		// 输出比较模式，选择PWM模式1
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       		// 输出极性，选择为高
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   		// 输出使能
	TIM_OCInitStructure.TIM_Pulse = 0;										// 初始的CCR值

	TIM_OC3Init(PWMA_TIM, &TIM_OCInitStructure);                        
	
	//TIM使能
	TIM_Cmd(PWMA_TIM, ENABLE);			
}

/**
  * 函    数：PWM_SetCompare3()
  * 参    数：Compare 要写入的CCR的值
  * 返 回 值：无
  * 注意事项：CCR和ARR共同决定占空比，此函数仅设置CCR的值，并不直接是占空比
  *           占空比Duty = CCR / (ARR + 1)
  */
void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(PWMA_TIM, Compare);
}
