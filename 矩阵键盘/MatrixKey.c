#include <REG52.H>
#include "Delay.h"

/* 可显示所按的矩阵键盘位置 */

sbit P17 = P1^7;
sbit P16 = P1^6;
sbit P15 = P1^5;
sbit P14 = P1^4;
sbit P13 = P1^3;
sbit P12 = P1^2;
sbit P11 = P1^1;
sbit P10 = P1^0;

unsigned char MatrixKey()
{
		unsigned char KeyNumber=0;
					
		P1=0xFF;
		P13=0;
		if(P17==0){Delay(20);while(P17==0);Delay(20);KeyNumber=1;}
		if(P16==0){Delay(20);while(P16==0);Delay(20);KeyNumber=5;}
		if(P15==0){Delay(20);while(P15==0);Delay(20);KeyNumber=9;}
		if(P14==0){Delay(20);while(P14==0);Delay(20);KeyNumber=13;}
		
		P1=0xFF;
		P12=0;
		if(P17==0){Delay(20);while(P17==0);Delay(20);KeyNumber=2;}
		if(P16==0){Delay(20);while(P16==0);Delay(20);KeyNumber=6;}
		if(P15==0){Delay(20);while(P15==0);Delay(20);KeyNumber=10;}
		if(P14==0){Delay(20);while(P14==0);Delay(20);KeyNumber=14;}
		
		P1=0xFF;
		P11=0;
		if(P17==0){Delay(20);while(P17==0);Delay(20);KeyNumber=3;}
		if(P16==0){Delay(20);while(P16==0);Delay(20);KeyNumber=7;}
		if(P15==0){Delay(20);while(P15==0);Delay(20);KeyNumber=11;}
		if(P14==0){Delay(20);while(P14==0);Delay(20);KeyNumber=15;}
		
		P1=0xFF;
		P10=0;
		if(P17==0){Delay(20);while(P17==0);Delay(20);KeyNumber=4;}
		if(P16==0){Delay(20);while(P16==0);Delay(20);KeyNumber=8;}
		if(P15==0){Delay(20);while(P15==0);Delay(20);KeyNumber=12;}
		if(P14==0){Delay(20);while(P14==0);Delay(20);KeyNumber=16;}
		
		return KeyNumber; 

}
