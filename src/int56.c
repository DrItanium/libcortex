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
#define SetField(x,n) ((((uint56)a[x]) << n))

void decompose_uint56_le(uint56 a, byte56_ptr b) {
	b[0] = (byte)a;
	b[1] = (byte)(a >> 8);
	b[2] = (byte)(a >> 16);
	b[3] = (byte)(a >> 24);
	b[4] = (byte)(a >> 32);
	b[5] = (byte)(a >> 40);
	b[6] = (byte)(a >> 48);
}
uint56 compose_uint56_le(byte56_ptr a) {
	return (SetField(6, 48) | SetField(5, 40) | SetField(4, 32) | SetField(3, 24) | SetField(2, 16) | SetField(1, 8) | SetField(0, 0)) & UINT56_MAX;
}

void decompose_uint56_be(uint56 a, byte56_ptr b) {
	b[0] = (byte)(a >> 48);
	b[1] = (byte)(a >> 40);
	b[2] = (byte)(a >> 32);
	b[3] = (byte)(a >> 24);
	b[4] = (byte)(a >> 16);
	b[5] = (byte)(a >> 8);
	b[6] = (byte)a;
}
uint56 compose_uint56_be(byte56_ptr a) {
	return (SetField(0, 48) | SetField(1, 40) | SetField(2, 32) | SetField(3, 24) | SetField(4, 16) | SetField(5, 8) | SetField(6, 0))  & UINT56_MAX;
}
static int fread_uint56_base(FILE*, byte56_ptr); 
int fread_uint56_base(FILE* a, byte56_ptr b) {
	int r0, r1, r2, r3, r4, r5, r6;
	// endianness is not important at this point as we are just reading bytes
	r0 = fgetc(a);
	r1 = fgetc(a);
	r2 = fgetc(a);
	r3 = fgetc(a);
	r4 = fgetc(a);
	r5 = fgetc(a);
	r6 = fgetc(a);
	if (r0 == EOF || r1 == EOF || r2 == EOF || r3 == EOF || r4 == EOF || r5 == EOF || r6 == EOF) {
		return 0;
	} else {
		b[0] = r0;
		b[1] = r1;
		b[2] = r2;
		b[3] = r3;
		b[4] = r4;
		b[5] = r5;
		b[6] = r6;
		return 1;
	}
}
int fread_uint56_le(FILE* a, uint56_ptr b) {
	int result;
	byte56 container;
	result = fread_uint56_base(a, container);
	if(result) {
		*b = compose_uint56_le(container);
	}
	return result;
}

int fread_uint56_be(FILE* a, uint56_ptr b) {
	int result;
	byte56 container;
	result = fread_uint56_base(a, container);
	if(result) {
		*b = compose_uint56_be(container);
	}
	return result;
}
#undef SetField
