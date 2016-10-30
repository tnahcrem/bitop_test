/*
 * bit_utils.c
 *
 *  Created on: Oct 29, 2016
 *      Author: hmerchan
 */


#include "bit_utils.h"
/*****************************************************************************
*    Function: void uint16tostr(char *str, uint32_t val)
*
*    Abstract:
*
*    Input/Output:
*
*    Return:
*
*****************************************************************************/
void uint16tostr(char *str, uint32_t val)
{
    char  tmp;
    int   i = 3;

    // NULL terminate the string.
    str[4] = '\0';

    while( i >=0 )
    {
        tmp = val & 0xf;

        if( tmp > 9 )
        {
            tmp += ('A' - 0xa);
        }
        else
        {
            tmp += '0';
        }
        str[i] = tmp;

        // next nibble.
        i--;
        val >>=4;
    }

}

/*****************************************************************************
*    Function: uint32_t getNumBitsSet(uint32_t data)
*
*    Abstract: get the count of bits set as 1 in uint32_t variable
*
*    Input/Output:
*                data -- input data
*
*    Return: the number of bits set as 1
*
*****************************************************************************/
uint32_t getNumBitsSet(uint32_t data)
{
    uint32_t count = 0;
    while(data)
    {
          data = data & (data - 1);
          count++;
    }
    return count;
}

/*****************************************************************************
*    Function: uint32_t bitop_countBits8(uint32_t tmpVal)
*
*    Abstract: This function counts the bits in the uint8_t and returns the
*              number of bits that are set. This method uses a lookup method.
*
*
*    Input/Output:
*       uint32_t word to count.
*
*    Return:
*       number of bits that are set.
*
*****************************************************************************/
const uint8_t bitcounts[] = {
    0, // b0000
    1, // b0001
    1, // b0010
    2, // b0011
    1, // b0100
    2, // b0101
    2, // b0110
    3, // b0111
    1, // b1000
    2, // b1001
    2, // b1010
    3, // b1011
    2, // b1100
    3, // b1101
    3, // b1110
    4, // b1111
};
uint32_t bitop_countBits8(uint32_t tmpVal)
{
    uint32_t count;

    count = bitcounts[tmpVal & 0x000F];
    count += bitcounts[(tmpVal & 0x00F0) >> 4];

    return count;
}


/*****************************************************************************
*    Function: uint8_t reverseBit(uint8_t data)
*
*    Abstract: Reverse the bit order in a byte
*
*    Input/Output:
*
*    Return:
*
*****************************************************************************/
uint8_t reverseBit(uint8_t data)
{
    uint32_t i;
    uint32_t val = 0;

    for(i=0; i < 8 ; i++)
    {
        val <<= 1;
        val |= data & 0x01;
        data >>= 1;
    }
    return (uint8_t)val;
}



/*****************************************************************************
*    Function: uint32_t bitop_getAt(uint8_t* buffer, uint32_t bitpos)
*
*    Abstract: get the bit value at a specific location of array
*
*    Input/Output:
*
*    Return:
*
*****************************************************************************/
uint32_t bitop_getAt(uint8_t* buffer, uint32_t bitpos)
{
    uint32_t val;
    uint32_t bytes;
    uint32_t bits;

    bytes = bitpos >> 3;
    bits = bitpos & 0x07;

    val = (buffer[bytes] >> bits) & 0x01;

    return (uint8_t)val;
}

/*****************************************************************************
*    Function: void bitop_setAt(uint8_t* buffer, uint32_t bitpos, uint32_t val)
*
*    Abstract: Set the bit value at a specific location of array
*
*    Input/Output:
*
*    Return:
*
*****************************************************************************/
void bitop_setAt(uint8_t* buffer, uint32_t bitpos, uint32_t val)
{
    uint32_t bytes;
    uint32_t bits;

    bytes = bitpos >> 3;
    bits = bitpos & 0x07;

    // clear that bit
    buffer[bytes] &= ~( 1 << bits);

    // set new value to that bit
    buffer[bytes] |= val << bits;
}

/*****************************************************************************
*    Function: void bitop_copy()
*
*    Abstract: Copy array of bit from src to dst
*
*    Input/Output:
*
*    Return:
*
*****************************************************************************/
void bitop_copy(uint8_t* dstBuffer, uint32_t dstBitpos,
                      uint8_t* srcBuffer, uint32_t srcBitpos, uint32_t bits)
{
    uint32_t   i;
    uint32_t   val;

    for(i = 0; i < bits; i ++)
    {
        val = bitop_getAt(srcBuffer, srcBitpos + i);
        bitop_setAt(dstBuffer, dstBitpos + i, val);
    }
}



