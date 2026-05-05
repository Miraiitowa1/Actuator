#ifndef __MOTOR_H
#define __MOTOR_H

//引脚定义
#define AIN12_GPIO_PORT         GPIOA
#define AIN1_GPIO_PIN          GPIO_Pin_4
#define AIN2_GPIO_PIN          GPIO_Pin_5
#define AIN12_GPIO_CLK          RCC_APB2Periph_GPIOA

#define BIN12_GPIO_PORT         GPIOB
#define BIN1_GPIO_PIN          GPIO_Pin_4
#define BIN2_GPIO_PIN          GPIO_Pin_3
#define BIN12_GPIO_CLK          RCC_APB2Periph_GPIOB

//函数声明
void Motor_Init(void);
void Motor_SetSpeed(int8_t Speed);

#endif
