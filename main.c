#include <REGX52.H>
#include <INTRINS.H>

void Delay_ms(unsigned int miliseconds)		//@11.0592MHz
{
	unsigned char i, j;
	unsigned int idx;
	
	for(idx = 0; idx < miliseconds; idx++){
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main(){
	unsigned char cnt = 0xFE;
	unsigned int delay = 500;
	while(1){
		P2 = cnt;
		Delay_ms(delay);
		if(delay > 10){
			delay -= 10;
		}
		cnt = cnt == 0x7F ? 0xFE : ~(~cnt<<1);		
	}
}