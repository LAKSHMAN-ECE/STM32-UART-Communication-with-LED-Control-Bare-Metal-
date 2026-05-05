

#include <stdint.h>
#include<stdio.h>


uint32_t *pAHB1ENR=(uint32_t*)0x40023830;
uint32_t *pAPB1ENR=(uint32_t*)0x40023840;
uint32_t *pGPIOMODER=(uint32_t*)0x40020000;
uint32_t *pGPIOAAFRL=(uint32_t*)0x40020020;
uint32_t *pUSART2BRR=(uint32_t*)0x40004408;
uint32_t *pUSART2_CR1=(uint32_t*)0x4000440c;
uint32_t *pUSART2_SR=(uint32_t*)0x40004400;
uint32_t *pUSART2_DR=(uint32_t*)0x40004404;
uint32_t *pGPIOCMODER=(uint32_t*)0x40020800;
uint32_t *pGPIOCODR=(uint32_t*)0x40020814;
void uart_INIT(){

	*pAHB1ENR |=(1<<0); // GPIOA ENABLE
	*pAHB1ENR |=(1<<2);//GPIOC ENABLE
	*pAPB1ENR |=(1<<17);// USART2 ENABLE
	//pa2(TX) alternative  mode
	*pGPIOMODER &=~(1<<4);
		*pGPIOMODER |=(1<<5);
	//pa3(RX) alternative  mode
		*pGPIOMODER &=~(1<<6);
		*pGPIOMODER |=(1<<7);
	 //gpio A Alternate function mapping (af07) to   pa2,pa3
		*pGPIOAAFRL |=(1<<8);
		*pGPIOAAFRL |=(1<<9);
		*pGPIOAAFRL |=(1<<10);
		*pGPIOAAFRL &=~(1<<11);
		*pGPIOAAFRL |=(1<<12);
		*pGPIOAAFRL |=(1<<13);
		*pGPIOAAFRL |=(1<<14);
		*pGPIOAAFRL &=~(1<<15);
		// BAUD RATE  for 16mhz clock and 9600 baud
		*pUSART2BRR=0X0683;
		//control register
		*pUSART2_CR1 |=(1<<13);//usart peripheral enable  enable
		*pUSART2_CR1 |=(1<<3);//tx
		*pUSART2_CR1 |=(1<<2);//rx

}
void LED_INIT(){
	*pGPIOCMODER |=(1<<26);
	*pGPIOCMODER  &=~(1<<27);
	*pGPIOCODR |=(1<<13);
}
//to check buffer
void Uart_Write(ch){
	//check for buffer empty if buffer is empty then it stops checking and comes out he loop
	while(!(*pUSART2_SR &80)){

	}
	// to send 8 bits only
	*pUSART2_DR=(ch&0Xff);

}
char Uart_Read(){
	while(!(*pUSART2_SR &20)){

		}
	return *pUSART2_DR;
}
int __io_putchar(int ch){
	Uart_Write(ch);
	return ch;
}

int main(){
    char ch;
	uart_INIT();
	LED_INIT();
	printf("WELCOME TO THE MY REPO  \n");

while(1){
	ch=Uart_Read();
	//led on 
	if(ch=='a'){
		*pGPIOCODR &=~(1<<13);
	}
	else{
		*pGPIOCODR |=(1<<13);
	}
}

}
