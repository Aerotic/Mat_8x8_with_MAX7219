/*
 * Matrix_8x8_with_MAX7219CNG.h
 *
 *  Created on: 2017Äê1ÔÂ15ÈÕ
 *      Author: Aeroman
 */

#ifndef MATRIX_8X8_WITH_MAX7219CNG_H_
#define MATRIX_8X8_WITH_MAX7219CNG_H_

//change the corresponding port and pin
//remember to change the port and pin in init7219()
#define pinCLK_1 P2OUT |= BIT5 // CLKpin
#define pinCLK_0 P2OUT &=~ BIT5
#define pinLOAD_1 P2OUT |= BIT4 //LOADpin CSpin chip select
#define pinLOAD_0 P2OUT &=~ BIT4
#define pinDIN_1 P2OUT |= BIT3 //DINpin
#define pinDIN_0 P2OUT &=~ BIT3
#define uchar unsigned char
extern void init7219();
extern void sendword7219(uchar addr,uchar dat);
extern void display7219(uchar *a);
#endif /* MATRIX_8X8_WITH_MAX7219CNG_H_ */
