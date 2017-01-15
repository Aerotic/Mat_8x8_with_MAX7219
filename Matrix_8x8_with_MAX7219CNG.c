/*
 * Matrix_8x8_with_MAX7219CNG.c
 *
 *  Created on: 2017Äê1ÔÂ15ÈÕ
 *      Author: Aeroman
 */
#include <msp430.h>
#include"Matrix_8x8_with_MAX7219CNG.h"

void sendbyte (uchar dat)
{
        uchar i,temp;

                    for (i=0;i<8;i++)
               {
                   temp=dat&0x80;
                   dat=dat<<1;
                   if(temp)
                           pinDIN_1;
                   else
                           pinDIN_0;
                   pinCLK_0;
                   //_delay_cycles(50000);
                   pinCLK_1;
               }

}

void sendword7219 (uchar addr,uchar dat)
{
        pinLOAD_0;
        sendbyte (addr);
        sendbyte (dat);
        pinLOAD_1;

}
void init7219()
   {
			P2SEL&=~(BIT4+BIT5+BIT3);
    		P2DIR |=BIT4+BIT5+BIT3;
            sendword7219 (0x0c,0x01);     /*  set power mode        */
            sendword7219 (0x0a,0x09);     /*   set lightness  19/32      */
            sendword7219 (0x0b,0x07);     /*  set scan limit           */
            sendword7219 (0x09,0x00);     /*   set decode mode         */
            sendword7219 (0x0f,0x00);     /*displaytest*/
   }
/**************************************************
*                MAX7219cleanscreen                                *
***************************************************/
void clear7219(void)
{
        uchar i;
        for(i=8;i>0;i--)
        	sendword7219(i,0x00);
}
void display7219(uchar a[])
{
	uchar i;
	for(i=0;i<8;i++)
		sendword7219(i+1,*(a+i));
}
