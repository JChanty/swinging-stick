#include <STC8G.H>
#include "intrins.H"
#define u8 unsigned char 
#define u16 unsigned int 
u16 disp_cjm[16] = {0x8FFF,0xA7FF,0x347F,0x739F,0x7BA3,0x7BB9,0x7BBD,0x7BBD,0x7BA5,0x7B95,0x7BB3,0x7BBF,0x347F,0xA7FF,0xAFFF,0xCFFF};
sbit mercury_key0 = P3^0;
sbit mercury_key1 = P3^1;

void P3P5(unsigned char hex)
{
	P37 = hex&0x01;
	P36 = hex&0x02;			   
	P35 = hex&0x04;
	P34 = hex&0x08;
	P33 = hex&0x10;
	P32 = hex&0x20;
	P54 = hex&0x40;
	P55 = hex&0x80;
}

void P1P3P5(unsigned int temp)
{
	u8 temp1 = 0;
	P1=temp;
	temp1 = temp>>8;
	P3P5(temp1);
}

void Delayms(int time)		//@12.000MHz
{
	unsigned char data i, j;
	while(time--)
	{
		i = 16;
		j = 147;
		do
		{
			while (--j);
		} while (--i);
	}
}

u8 i=0;
u16 dat=0;

void main()
{
	P1M0=0xff;P1M1=0X00;
	P3M0=0XFF;P3M1=0X00;
	P5M0=0XFF;P5M1=0X00;
	mercury_key0 = 1;	
	while(1)
	{	
		for(i=0;i<16;i++)
		{
			P1P3P5(disp_cjm[i]);
			Delayms(1);
		}
	}
}