#include <STC89C5xRC.H>
#include "LCD1602.h"
#include "Delay.h"
#include "IR.h"

unsigned char Num;
unsigned char Address;
unsigned char Command;

void main()
{
	P2=0xFE;
	LCD_Init();
	LCD_ShowString(1,1,"LIGHT  IR  CONTROL");
	LCD_ShowString(2,1,"GEAR:");
	
	IR_Init();
	
	while(1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			
//			LCD_ShowHexNum(2,1,Address,2);
//			LCD_ShowHexNum(2,5,Command,2);
			
			if(Command==IR_1)
			{
				P20=1;
			}
			if(Command==IR_2)
			{
				P20=0;
			}
			if(Command==IR_3)
			{
				unsigned char i;
				for(i=0;i<100;i++)
				{
					P20=1;
					Delay(50);
					P20=0;
					Delay(50);
				}
			}
			
			LCD_ShowNum(2,10,1,3);
		}
	}

}

