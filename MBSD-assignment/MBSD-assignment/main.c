#include <avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>

int GetKeyPressed(void);
int checkPassword(char a[],char b[],int size);
int main(void)
{
	char digit[20]={'7','8','9','A','4','5','6','B','1','2','3','C','*','0','#','D','\0'};
	DDRD=0xF0;
	DDRA=0xFF;
	DDRC=0x00;
	DDRB=(1<<PINB1);
	int key;
	char password[4]={'1','2','3','4'};
	char check[4];
	int index=0;
	char open=0b11000000;
	char close=0b11000110;
	PORTA=0b11000110;
	while(1)
	{
		//TODO:: Please write your application code
		key= GetKeyPressed();
		// any key is pressed
		if(key !=16)
		{ //password key is correct and it matches
			if (digit[key]==password[index] && index!=4){
				check[index]=password[index];
				index++;
			}
			//reset button
			else if(digit[key]=='0'){
				index=0;
			}
			else if(digit[key]=='#'){
				index--;
				PORTA=0b00000000;
			}
			//incorrect input is entered
			else if (digit[key]!=password[index-1] && index!=4){
				index=0;
				memset(check,0,4);
			}
		}
		if (index==4 && checkPassword(password,check,4)){
			PORTA=open;
		}
		else{
			PORTA=close;
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

//function to compare array elements
int checkPassword(int a[],int b[],int size)	{
	int i;
	for(i=0;i<size;i++){
		if(a[i]!=b[i])
		return 1;
	}
	return 0;
}