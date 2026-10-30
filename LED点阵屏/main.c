#include <STC89C5xRC.H>
#include "Delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

#define MATRIX_LED_PORT			P0

//74HC595写入一个字节


void _74HC595_WriteByte(unsigned char Byte)
{
		unsigned char i;
		for(i=0;i<8;i++)
		{
				SER=Byte&(0x80>>i);
				SCK=1;
				SCK=0;
		}
		RCK=1;
		RCK=0;
		
}
//LED点阵屏显示一列数据
//Column列选0-7,最左为0
//Data列数据
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
		_74HC595_WriteByte(Data);
		MATRIX_LED_PORT=~(0x80>>Column);
		Delay(1);
		MATRIX_LED_PORT=0xFF;
}

void main()
{
		SCK=0;
		RCK=0;
		
		while(1)
		{
				MatrixLED_ShowColumn(0,0x80);
				MatrixLED_ShowColumn(1,0x40);
				MatrixLED_ShowColumn(2,0x20);
				MatrixLED_ShowColumn(3,0x10);
				MatrixLED_ShowColumn(4,0x08);
				MatrixLED_ShowColumn(5,0x04);
				MatrixLED_ShowColumn(6,0x02);
				MatrixLED_ShowColumn(7,0x01);
			
		}

}