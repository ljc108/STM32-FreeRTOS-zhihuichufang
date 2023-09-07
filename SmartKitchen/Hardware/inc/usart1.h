#ifndef __USART1_H
#define __USART1_H
#include "stm32f10x.h" 

void USART1_Init();
void USART1_Putc(uint8_t ch);
void USART1_Write(char *wbuf,int len);

#endif
