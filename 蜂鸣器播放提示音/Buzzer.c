#include <STC89C5xRC.H>
#include "INTRINS.H"

//蜂鸣器端口
sbit Buzzer=P2^5;

//蜂鸣器私有延时函数
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

//蜂鸣器发声
//ms时间查明长度
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}
	