#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;

void main()
{
		LCD_Init();
		LCD_ShowString(1,1,"PassWord:");
		while(1)
		{
				KeyNum=MatrixKey();
				if(KeyNum)
				{
						if(KeyNum<=10)
						{
								if(Count<4)
								{
										Password*=10;
										Password+=KeyNum%10;
										Count++;
								}
								LCD_ShowNum(2,1,Password,4);
						}
						if(KeyNum==11)		//11为确认键
						{
								if(Password==1234)//密码设定
								{
										LCD_ShowString(1,14,"OK");
										Password=0;
										Count=0;
										LCD_ShowNum(2,1,Password,4);
								}
								else
								{
										LCD_ShowString(1,14,"NO");
										Delay(1000);
										LCD_ShowString(2,1,"ONCE");
										Delay(2000);
										Password=0;
										Count=0;
										LCD_ShowNum(2,1,Password,4);
								}
						}
						if(KeyNum==12)		//12为取消键
						{
							Password=0;
							Count=0;
							LCD_ShowNum(2,1,Password,4);
						}
				}
		}
}