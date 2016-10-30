/*
 ============================================================================
 Name        : bitop_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bit_utils.h"

int main(void) {
	uint8_t temp;
	uint8_t bitCnt;
	uint8_t temp1;
	temp = 6;
	bitCnt = getNumBitsSet(temp);
	printf("\n Number of bits set in %d  = %d",temp,bitCnt);

	temp = 0x17;
	temp1 = reverseBit(temp);
	printf("\n the reverse of %x is %x",temp,temp1);
	return 0;
}
