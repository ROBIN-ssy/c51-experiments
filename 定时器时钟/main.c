#include <STC89C5xRC.H> 
#include "Delay.h" 
#include "LCD1602.h" 
#include "Timer0.h" 

unsigned char Sec=30,Min=18,Hour=22; 

void main() 
{ 
    LCD_Init(); 
    Time0_Init();  // 修正函数名
    
    LCD_ShowString(1, 1, "Clock:"); 
		LCD_ShowString(2, 1, "  :  :"); 
	 
    LCD_ShowNum(2, 1, 0, 2);  // 初始显示0
    while(1) 
    { 
        LCD_ShowNum(2, 1, Hour, 2); 
				LCD_ShowNum(2, 4, Min, 2); 
				LCD_ShowNum(2, 7, Sec, 2); 
    }
} 

void Timer0_Routine() interrupt 1 
{ 
    static unsigned int T0Count = 0;
    TH0 = 0xFC; 
    TL0 = 0x18; 
    T0Count++; 
    if(T0Count >= 1000)  // 1000ms = 1秒 
    { 
        T0Count = 0; 
        Sec++; 
				if(Sec>=60)
				{
						Sec=0;
						Min++;
						if(Min>=60)
						{
								Min=0;
								Hour++;
								if(Hour>=24)
								{
										Hour=0;
								}
						}
				}
    } 
} 