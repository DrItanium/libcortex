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
typedef uint16_t uint16;
typedef uint16* uint16_ptr;
typedef uint32_t uint24;
typedef uint24* uint24_ptr;
typedef uint32_t uint32;
typedef uint32* uint32_ptr;
typedef uint64_t uint40;
typedef uint40* uint40_ptr;
typedef uint64_t uint48;
typedef uint48* uint48_ptr;
typedef uint64_t uint56;
typedef uint56* uint56_ptr;
typedef uint64_t uint64;
typedef uint64* uint64_ptr;

/* byte manipulation functions */
typedef byte byte16[2];
typedef byte byte24[3];
typedef byte byte32[4];
typedef byte byte40[5];
typedef byte byte48[6];
typedef byte byte56[7];
typedef byte byte64[8];

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


void decompose_uint16_le(uint16, byte*);
uint16 compose_uint16_le(byte*);

void decompose_uint16_be(uint16, byte*);
uint16 compose_uint16_be(byte*);

int fread_uint16_le(FILE*, uint16_ptr);
int fread_uint16_be(FILE*, uint16_ptr);

int fwrite_uint16_le(FILE*, uint16_ptr);
int fwrite_uint16_be(FILE*, uint16_ptr);

/* 24-bit operations */

void decompose_uint24_le(uint24, byte*);
uint24 compose_uint24_le(byte*);

void decompose_uint24_be(uint24, byte*);
uint24 compose_uint24_be(byte*);

int fread_uint24_le(FILE*, uint24_ptr);
int fread_uint24_be(FILE*, uint24_ptr);

int fwrite_uint24_le(FILE*, uint24_ptr);
int fwrite_uint24_be(FILE*, uint24_ptr);

/* 32-bit operations */
uint32 compose_uint32_le(byte*);
void decompose_uint32_le(uint32, byte*);

uint32 compose_uint32_be(byte*);
void decompose_uint32_be(uint32, byte*);

int fread_uint32_le(FILE*, uint32_ptr);
int fread_uint32_be(FILE*, uint32_ptr);

int fwrite_uint32_le(FILE*, uint32_ptr);
int fwrite_uint32_be(FILE*, uint32_ptr);
/* 40-bit operations */
uint40 compose_uint40_le(byte*);
void decompose_uint40_le(uint40, byte*);

uint40 compose_uint40_be(byte*);
void decompose_uint40_be(uint40, byte*);

int fread_uint40_le(FILE*, uint40_ptr);
int fread_uint40_be(FILE*, uint40_ptr);

int fwrite_uint40_le(FILE*, uint40_ptr);
int fwrite_uint40_be(FILE*, uint40_ptr);

/* 48-bit operations */
uint48 compose_uint48_le(byte*);
void decompose_uint48_le(uint48, byte*);

uint48 compose_uint48_be(byte*);
void decompose_uint48_be(uint48, byte*);

int fread_uint48_le(FILE*, uint48_ptr);
int fread_uint48_be(FILE*, uint48_ptr);

int fwrite_uint48_le(FILE*, uint48_ptr);
int fwrite_uint48_be(FILE*, uint48_ptr);
/* 56-bit operations */
uint56 compose_uint56_le(byte*);
void decompose_uint56_le(uint56, byte*);

uint56 compose_uint56_be(byte*);
void decompose_uint56_be(uint56, byte*);

int fread_uint56_le(FILE*, uint56_ptr);
int fread_uint56_be(FILE*, uint56_ptr);

int fwrite_uint56_le(FILE*, uint56_ptr);
int fwrite_uint56_be(FILE*, uint56_ptr);
/* 64-bit operations */
uint64 compose_uint64_le(byte*);
void decompose_uint64_le(uint64, byte*);

uint64 compose_uint64_be(byte*);
void decompose_uint64_be(uint64, byte*);

int fread_uint64_le(FILE*, uint64_ptr);
int fread_uint64_be(FILE*, uint64_ptr);

int fwrite_uint64_le(FILE*, uint64_ptr);
int fwrite_uint64_be(FILE*, uint64_ptr);

/* endian ignorant functions - read in/write out sequentially */
int fread_uint16_seq(FILE*, byte*);
int fread_uint24_seq(FILE*, byte*);
int fread_uint32_seq(FILE*, byte*);
int fread_uint40_seq(FILE*, byte*);
int fread_uint48_seq(FILE*, byte*);
int fread_uint56_seq(FILE*, byte*);
int fread_uint64_seq(FILE*, byte*);

int fwrite_uint16_seq(FILE*, byte*);
int fwrite_uint24_seq(FILE*, byte*);
int fwrite_uint32_seq(FILE*, byte*);
int fwrite_uint40_seq(FILE*, byte*);
int fwrite_uint48_seq(FILE*, byte*);
int fwrite_uint56_seq(FILE*, byte*);
int fwrite_uint64_seq(FILE*, byte*);


/* File operations */
char* freadline(FILE*);

/* misc */
void libcortex_exit(int, char*);
#endif /* _LIBCORTEX_H */
