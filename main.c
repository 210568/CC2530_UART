/*
*��ĿĿ�꣺ͨ�����ڷ�������"Hello ZigBee!"
*��Ŀ��дʱ�䣺2022��3��16��
*��Ŀ��д�ˣ����
*/


#include "ioCC2530.h"
char data[]="Hello ZigBee!";

/*
*�������ƣ�delay()
*�������ܣ��ӳٺ���
*�������void delay(unsigned int time)
*�����βΣ�unsigned int time
*��������ֵ����
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
*�������ƣ�Initial_USART_Tx()
*�������ܣ�UART��ʼ������
*������ڣ�void Initial_USART_Tx()
*�����βΣ���
*��������ֵ����
*/
void Initial_USART_Tx()
{
  CLKCONCMD &= ~0x7F;           //��������Ϊ32Mhz
  while(CLKCONCMD & 0x40);
  CLKCONCMD &= ~0x47;           //����ϵͳ��ʱ��Ƶ��Ϊ32Mhz
  PERCFG = 0x00;                 //usart0 ʹ�ñ���δ֪1 TX-P0.3 RX-P0.2
  P0SEL |= 0x3C;                 //P0.2P0.3P0.4P0.5��Ϊ���蹦��
  P2DIR &= ~0xC0;                //P0������ΪUART��ʽ
  U0CSR = 0x80;                 //Uartģʽ
  U0GCR = 9;
  U0BAUD = 59;                   //����������Ϊ19200
  UTX0IF = 0;                   //uart0 Tx�жϱ�־λ����
}

/*
*�������ƣ�main()
*�������ܣ����������������
*������ڣ�void main(void)
*�����βΣ���
*��������ֵ����
*/
void main(void)
{

}