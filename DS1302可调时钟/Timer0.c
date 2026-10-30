#include <STC89C5xRC.H>

void Time0_Init()
{
    TMOD = 0x01;  // 设置定时器0为模式1
    TF0 = 0;      // 清除定时器0溢出标志
    TR0 = 1;      // 启动定时器0
    // 使用更保守的初值，确保定时更准确
    TH0 = 0xFC;   // 65536 - 1000 = 64536 = 0xFC18
    TL0 = 0x18;   //定时一毫秒
    ET0 = 1;      // 允许定时器0中断
    EA = 1;       // 开启总中断
    PT0 = 0;      // 定时器0中断优先级为低
}

/*
void Timer0_Routine() interrupt 1
{
    // 重新加载定时器初值
    static unsigned int T0Count = 0;
		TH0 = 0xFC;
    TL0 = 0x18;
    T0Count++;
    if(T0Count >= 1000)  // 1000ms = 1秒
    {
        T0Count = 0;
        P20 = ~P20;  // 翻转P20引脚状态
    }
}
*/
