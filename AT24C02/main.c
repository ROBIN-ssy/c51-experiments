#include <STC89C5xRC.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Key.h"

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"A");
	while(1)
	{

	}

}
