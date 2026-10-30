#include <STC89C5xRC.H>

void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	while(1)
	{
		P2=0xEF;
		Delay1ms(100);
		P2=0xFD;
		Delay1ms(100);
	}
}