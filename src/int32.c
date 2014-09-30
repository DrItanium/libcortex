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
#define SetField(x,n) ((((uint32)a[x]) << n))
void decompose_uint32_le(uint32 a, byte32_ptr b) {
	b[0] = (byte)a;
	b[1] = (byte)(a >> 8);
	b[2] = (byte)(a >> 16);
	b[3] = (byte)(a >> 24);
}
uint32 compose_uint32_le(byte32_ptr a) {
	return	SetField(3, 24) | SetField(2, 16) | SetField(1, 8) | SetField(0, 0);
}

void decompose_uint32_be(uint32 a, byte32_ptr b) {
	b[3] = (byte)a;
	b[2] = (byte)(a >> 8);
	b[1] = (byte)(a >> 16);
	b[0] = (byte)(a >> 24);
}
uint32 compose_uint32_be(byte32_ptr a) {
	return	SetField(0, 24) | SetField(1, 16) | SetField(2, 8) | SetField(3, 0);
}
static int fread_uint32_base(FILE*, byte32_ptr); 
int fread_uint32_base(FILE* a, byte32_ptr b) {
	int r0, r1, r2, r3;
	// endianness is not important at this point as we are just reading bytes
	r0 = fgetc(a);
	r1 = fgetc(a);
	r2 = fgetc(a);
	r3 = fgetc(a);
	if (r0 == EOF || r1 == EOF || r2 == EOF || r3 == EOF) {
		return 0;
	} else {
		b[0] = r0;
		b[1] = r1;
		b[2] = r2;
		b[3] = r3;
		return 1;
	}
}
int fread_uint32_le(FILE* a, uint32_ptr b) {
	int result;
	byte32 container;
	result = fread_uint32_base(a, container);
	if(result) {
		*b = compose_uint32_le(container);
	}
	return result;
}

int fread_uint32_be(FILE* a, uint32_ptr b) {
	int result;
	byte32 container;
	result = fread_uint32_base(a, container);
	if(result) {
		*b = compose_uint32_be(container);
	}
	return result;
}
#undef SetField

