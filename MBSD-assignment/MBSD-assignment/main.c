#include <avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>

int GetKeyPressed(void);
int main(void)
{
	char digit[20]={'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D','\0'};
	DDRD=0xF0;
	DDRA=0xFF;
	DDRC=0x00;
	DDRB=(1<<PINB1);
	int key;
	char password='7';
	PORTA=digit[16];
	while(1)
	{
		//TODO:: Please write your application code
		key= GetKeyPressed();
		if(key!=16)
		{
			//PORTA=digit[key];
			PORTA=0b11000000;
			
		}
		if(key==16){
			PORTA=0b11000110;
		}
	}
}
int GetKeyPressed(void)
{
	char x;
	PORTB=0x00;
	int data;
	x=PINC;
	if(x==0x01)
	{
		data=(PIND&0x0F);
		return data;
	}
	return 16;
}

