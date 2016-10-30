/*
 * bit_utils.h
 *
 *  Created on: Oct 29, 2016
 *      Author: hmerchan
 */

#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_

#include <stdint.h>
#define MAKEWORD(lsbByte, msbByte) (((uint32_t)(lsbByte)) | (((uint32_t)(msbByte)) << 8))
#define LSBBYTE(word)    (((uint32_t)(word)) & 0xFF)
#define MSBBYTE(word)    ((((uint32_t)(word)) >> 8) & 0xFF)

#define MAKEDWORD(lsbWord, msbWord) (((uint32_t)(lsbWord)) | (((uint32_t)(msbWord)) << 16))
#define LSBWORD(dword)   (((uint32_t)(dword)) & 0xFFFF)
#define MSBWORD(dword)   ((((uint32_t)(dword)) >> 16) & 0xFFFF)

#define MAKE2BYTESWORD(bytes)   MAKEWORD((bytes)[0], (bytes)[1])
#define MAKE4BYTESDWORD(bytes)  MAKEDWORD(MAKEWORD((bytes)[0], (bytes)[1]), MAKEWORD((bytes)[2], (bytes)[3]))


void uint16tostr(char *str, uint32_t val);


void ConvertByteToAscii (uint8_t byte, char * pString);

uint32_t getNumBitsSet(uint32_t num);

uint8_t reverseBit(uint8_t data);

uint32_t bitop_getAt(uint8_t* buffer, uint32_t bitpos);
void bitop_setAt(uint8_t* buffer, uint32_t bitpos, uint32_t val);
void bitop_copy(uint8_t* dstBuffer, uint32_t dstBitpos,
                    uint8_t* srcBuffer, uint32_t srcBitpos, uint32_t bits);
uint32_t bitop_countBits8(uint32_t tmpVal);
#endif /* BIT_UTILS_H_ */
