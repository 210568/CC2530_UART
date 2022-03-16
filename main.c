/*
*项目目标：通过串口发送数据"Hello ZigBee!"
*项目编写时间：2022年3月16日
*项目编写人：李俊辉
*/


#include "ioCC2530.h"
char data[]="Hello ZigBee!";

/*
*函数名称：delay()
*函数功能：延迟函数
*函数入口void delay(unsigned int time)
*函数形参：unsigned int time
*函数返回值：无
*/
void delay(unsigned int time)
{
  for(unsigned int i = 0;i < time; i++)
    for(unsigned char j = 0; j < 240; j++)
    {
      asm("NOP");
      asm("NOP");
      asm("NOP");
    }
}

/*
*函数名称：Initial_USART_Tx()
*函数功能：UART初始化函数
*函数入口：void Initial_USART_Tx()
*函数形参：无
*函数返回值：无
*/
void Initial_USART_Tx()
{
  CLKCONCMD &= ~0x7F;           //晶振设置为32Mhz
  while(CLKCONCMD & 0x40);
  CLKCONCMD &= ~0x47;           //设置系统主时钟频率为32Mhz
  PERCFG = 0x00;                 //usart0 使用备用未知1 TX-P0.3 RX-P0.2
  P0SEL |= 0x3C;                 //P0.2P0.3P0.4P0.5作为外设功能
  P2DIR &= ~0xC0;                //P0优先作为UART方式
  U0CSR = 0x80;                 //Uart模式
  U0GCR = 9;
  U0BAUD = 59;                   //波特率设置为19200
  UTX0IF = 0;                   //uart0 Tx中断标志位清零
}

/*
*函数名称：main()
*函数功能：主函数，程序入口
*函数入口：void main(void)
*函数形参：无
*函数返回值：无
*/
void main(void)
{

}