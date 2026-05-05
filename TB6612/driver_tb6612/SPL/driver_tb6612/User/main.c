#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "motor.h"

/**
  * 坐标轴定义：
  * 左上角为(0, 0)点
  * 横向向右为X轴，取值范围：0~127
  * 纵向向下为Y轴，取值范围：0~63
  * 
  *       0             X轴           127 
  *      .------------------------------->
  *    0 |
  *      |
  *      |
  *      |
  *  Y轴 |
  *      |
  *      |
  *      |
  *   63 |
  *      v
  * 
  */

int main(void)
{
	OLED_Init();
	Motor_Init();

	while(1)
	{
		OLED_ShowString(0, 0, "driver_tb6612", OLED_8X16);
		Motor_SetSpeed(90); 
		OLED_Update();
	}
}
