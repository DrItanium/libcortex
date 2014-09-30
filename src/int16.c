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
#define SetField(x,n) ((((uint16)a[x]) << n))

void decompose_uint16_le(uint16 a, byte16_ptr b) {
	b[0] = (byte)a;
	b[1] = (byte)(a >> 8);
}
uint16 compose_uint16_le(byte16_ptr a) {
	return SetField(1, 8) | SetField(0, 0);
}
void decompose_uint16_be(uint16 a, byte16_ptr b) {
	b[0] = (byte)(a >> 8);
	b[1] = (byte)(a);
}
uint16 compose_uint16_be(byte16_ptr a) {
	return SetField(0, 8) | SetField(1, 0);
}

static int fread_uint16_base(FILE*, byte16_ptr); 
int fread_uint16_base(FILE* a, byte16_ptr b) {
	int r0, r1; 
	// endianness is not important at this point as we are just reading bytes
	r0 = fgetc(a);
	r1 = fgetc(a);
	if (r0 == EOF || r1 == EOF) {
		return 0;
	} else {
		b[0] = r0;
		b[1] = r1;
		return 1;
	}
}
int fread_uint16_le(FILE* a, uint16_ptr b) {
	int result;
	byte16 container;
	result = fread_uint16_base(a, container);
	if(result) {
		*b = compose_uint16_le(container);
	}
	return result;
}

int fread_uint16_be(FILE* a, uint16_ptr b) {
	int result;
	byte16 container;
	result = fread_uint16_base(a, container);
	if(result) {
		*b = compose_uint16_be(container);
	}
	return result;
}
#undef SetField
