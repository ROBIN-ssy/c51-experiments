#include <STC89C5xRC.H>

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms)
	{
			i = 2;
			j = 239;
			do
			{
				while (--j);
			} while (--i);
			xms--;
	}
	
}

void main()
{
	unsigned char LEDNum=0;
	while(1)
	{
		if(P30==0)
		{
			Delay(20);
			while(P30==0);
			Delay(20);
			
			LEDNum++;
			P2=~LEDNum;
			
		}
	}
}
