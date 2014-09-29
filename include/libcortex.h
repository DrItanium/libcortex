/*
Copyright (c) 2014 Joshua Scoggins

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef _LIBCORTEX_H
#define _LIBCORTEX_H

typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long vlong;
typedef unsigned long long uvlong;
typedef long double vdouble;

/* Fixed size types and odd in between types */
typedef int16_t int16;
typedef uint16_t uint16;
typedef uint32_t uint24;
typedef uint32_t uint32;
typedef uint64_t uint40;
typedef uint64_t uint48;
typedef uint64_t uint56;
typedef uint64_t uint64;

/* byte manipulation functions */
typedef byte byte16[2];
typedef byte byte24[3];
typedef byte byte32[4];
typedef byte byte40[5];
typedef byte byte48[6];
typedef byte byte56[7];
typedef byte byte64[8];

typedef byte* byte16_ptr;
typedef byte* byte24_ptr;
typedef byte* byte32_ptr;
typedef byte* byte40_ptr;
typedef byte* byte48_ptr;
typedef byte* byte56_ptr;
typedef byte* byte64_ptr;

/* newtypesizes typesize limits */
enum {
	UINT24_MAX = 0x00FFFFFF,
	UINT24_MIN = 0x00000000,
	//40-bit operations
	UINT40_MAX = 0x000000FFFFFFFFFF,
	UINT40_MIN = 0x0000000000000000,
	//48-bit
	UINT48_MAX = 0x0000FFFFFFFFFFFF,
	UINT48_MIN = 0x0000000000000000,
	//56-bit
	UINT56_MAX = 0x00FFFFFFFFFFFFFF,
	UINT56_MIN = 0x0000000000000000,
};


/* You have to explicit if you want little endian or big endian decomposition
 * and composition. Choosing a default style leads to complexity and potential
 * bugs so it is up to the user of the lib to be explicit! */

//TODO: add functions for manipulating off boundary values


void decompose_uint16_le(uint16, byte16_ptr);
uint16 compose_uint16_le(byte16_ptr);

void decompose_uint16_be(uint16, byte16_ptr);
uint16 compose_uint16_be(byte16_ptr);

/* 24-bit operations */

void decompose_uint24_le(uint24, byte24_ptr);
uint24 compose_uint24_le(byte24_ptr);

void decompose_uint24_be(uint24, byte24_ptr);
uint24 compose_uint24_be(byte24_ptr);

/* 32-bit operations */
uint32 compose_uint32_le(byte32_ptr);
void decompose_uint32_le(uint32, byte32_ptr);

uint32 compose_uint32_be(byte32_ptr);
void decompose_uint32_be(uint32, byte32_ptr);

uint40 compose_uint40_le(byte40_ptr);
void decompose_uint40_le(uint40, byte40_ptr);

uint40 compose_uint40_be(byte40_ptr);
void decompose_uint40_be(uint40, byte40_ptr);

uint48 compose_uint48_le(byte48_ptr);
void decompose_uint48_le(uint48, byte48_ptr);

uint48 compose_uint48_be(byte48_ptr);
void decompose_uint48_be(uint48, byte48_ptr);

uint56 compose_uint56_le(byte56_ptr);
void decompose_uint56_le(uint56, byte56_ptr);

uint56 compose_uint56_be(byte56_ptr);
void decompose_uint56_be(uint56, byte56_ptr);

uint64 compose_uint64_le(byte64_ptr);
void decompose_uint64_le(uint64, byte64_ptr);

uint64 compose_uint64_be(byte64_ptr);
void decompose_uint64_be(uint64, byte64_ptr);


/* File operations */
char* freadline(FILE*);

#endif /* _LIBCORTEX_H */
