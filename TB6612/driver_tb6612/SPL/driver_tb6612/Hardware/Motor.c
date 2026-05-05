#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "PWM.h"

/**
  * 函    数：Motor_Init()
  * 参    数：无
  * 返 回 值：无
  * 说    明：PA4和PA5为方向控制引脚，PB0为PWM引脚
  */
void Motor_Init(void)
{
	//开启时钟
	RCC_APB2PeriphClockCmd(AIN12_GPIO_CLK, ENABLE);		// 开启GPIOA的时钟
	RCC_APB2PeriphClockCmd(PWMA_GPIO_CLK, ENABLE);		// 开启GPIOB的时钟（PWM引脚）
	
	//方向控制引脚初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = AIN1_GPIO_PIN | AIN2_GPIO_PIN;		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(AIN12_GPIO_PORT, &GPIO_InitStructure);						
	
	//初始化直流电机的底层PWM
	PWM_Init();													
	
	//初始状态停止电机
	Motor_SetSpeed(0);
}

/**
  * 函    数：Motor_SetSpeed()
  * 参    数：Speed 要设置的速度，范围：-100~100
  * 返 回 值：无
  */
void Motor_SetSpeed(int8_t Speed)
{
	if (Speed >= 0)							
	{
		GPIO_SetBits(AIN12_GPIO_PORT, AIN1_GPIO_PIN);	
		GPIO_ResetBits(AIN12_GPIO_PORT, AIN2_GPIO_PIN);	
		PWM_SetCompare3(Speed);				
	}
	else									
	{
		GPIO_ResetBits(AIN12_GPIO_PORT, AIN1_GPIO_PIN);	
		GPIO_SetBits(AIN12_GPIO_PORT, AIN2_GPIO_PIN);	
		PWM_SetCompare3(-Speed);			
	}
}