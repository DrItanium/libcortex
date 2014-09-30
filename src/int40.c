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
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <libcortex.h>
#define SetField(x,n) ((((uint40)a[x]) << n))

void decompose_uint40_le(uint40 a, byte40_ptr b) {
	b[0] = (byte)a;
	b[1] = (byte)(a >> 8);
	b[2] = (byte)(a >> 16);
	b[3] = (byte)(a >> 24);
	b[4] = (byte)(a >> 32);
}
uint40 compose_uint40_le(byte40_ptr a) {
	return (SetField(4, 32) | SetField(3, 24) | SetField(2, 16) | SetField(1, 8) | SetField(0, 0)) & UINT40_MAX;
}

void decompose_uint40_be(uint40 a, byte40_ptr b) {
	b[0] = (byte)(a >> 32);
	b[1] = (byte)(a >> 24);
	b[2] = (byte)(a >> 16);
	b[3] = (byte)(a >> 8);
	b[4] = (byte)a;
}
uint40 compose_uint40_be(byte40_ptr a) {
	return (SetField(0, 32) | SetField(1, 24) | SetField(2, 16) | SetField(3, 8) | SetField(4, 0))  & UINT40_MAX;
}
static int fread_uint40_base(FILE*, byte40_ptr); 
int fread_uint40_base(FILE* a, byte40_ptr b) {
	int r0, r1, r2, r3, r4;
	// endianness is not important at this point as we are just reading bytes
	r0 = fgetc(a);
	r1 = fgetc(a);
	r2 = fgetc(a);
	r3 = fgetc(a);
	r4 = fgetc(a);
	if (r0 == EOF || r1 == EOF || r2 == EOF || r3 == EOF || r4 == EOF) {
		return 0;
	} else {
		b[0] = r0;
		b[1] = r1;
		b[2] = r2;
		b[3] = r3;
		b[4] = r4;
		return 1;
	}
}
int fread_uint40_le(FILE* a, uint40_ptr b) {
	int result;
	byte40 container;
	result = fread_uint40_base(a, container);
	if(result) {
		*b = compose_uint40_le(container);
	}
	return result;
}

int fread_uint40_be(FILE* a, uint40_ptr b) {
	int result;
	byte40 container;
	result = fread_uint40_base(a, container);
	if(result) {
		*b = compose_uint40_be(container);
	}
	return result;
}

#undef SetField
