#include<lpc21xx.h>
#include<stdio.h>
void delay(unsigned int );
void data(unsigned int);
void command(unsigned int);
void extint0_ISR(void)__irq;
int main()
{
unsigned char message[]= {"faraz"};
unsigned int c[]={0x30,0x30,0x01,0x06,0x0e,0x80};
unsigned int i,j;
unsigned  long int y;
PINSEL0=0X00000000;
IO0DIR=0x00001ffc;
y=0X00001000;
IO0CLR=y;
for(i=0;i<6;i++)
{
command(c[i]);
delay(65000);}
if(y=IO0SET)
{
command(0x80);
delay(65000);
for(j=0;j<5;j++)
{
data(message[j]);
delay(65000);

delay(10000);
}command(0x01);}
else{
command(0x01);
delay(10000);}

/* {	PINSEL1=0x00000001;
	EXTMODE=0x00000001;
	VICVectAddr0=(unsigned long)extint0_ISR;
	VICVectCntl0=0x20|14;
	VICIntEnable|=0x00004000;
	while(1);}*/
return 0;
  }


void command(unsigned int x)
{
x=x<<4;
IO0CLR=0x00000ffc;
IO0CLR=0x00000004;
IO0SET=x;
delay(10000);
IO0SET=0x00000008;
delay(100);
IO0CLR=0x00000008;
}


void data(unsigned int a)
{
a=a<<4;
IO0CLR=0x00000ffc;
IO0SET=0x00000004;
IO0SET=a;
delay(10000);
IO0SET=0x00000008;
delay(100);
IO0CLR=0x00000008;
}

/*void extint0_ISR(void)__irq
{
	PINSEL0=0X00000000;
	IODIR0=0x00001000;
	IOSET0=0X00001000; 	// ON LEDS
	delay(10000000);	  
  IOCLR0=0X00001000; 	// OFF LEDS
	delay(1000);
	EXTINT|=0X00000001;	//Clear interrupt flag
	VICVectAddr=0;		// End of interrupt execution
}*/	 
void delay(unsigned int x)
{
unsigned int i;
for(i=0;i<x;i++);
}