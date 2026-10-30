#include <STC89C5xRC.H>
#include "LCD1602.h"
#include "Delay.h"

int uu=0;

void main()
{
		LCD_Init();
		while(1)
		{
			uu++;
			Delay(1000);
			LCD_ShowNum(1,1,uu,3);
		}

}