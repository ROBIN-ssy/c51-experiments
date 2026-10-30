void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--)
	{
			i = 24;
			j = 85;
			do
			{
				while (--j);
			} while (--i);
	}
}
