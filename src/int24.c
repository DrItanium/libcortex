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

void decompose_uint24_le(uint24 a, byte24_ptr b) {
	b[0] = (byte)a;
	b[1] = (byte)(a >> 8);
	b[2] = (byte)(a >> 16);
}
uint24 compose_uint24_le(byte24_ptr a) {
	return	(uint24)((((uint24)(a[2] << 16)) |
				((uint24)(a[1] << 8)) |
				((uint24)(a[0]))) & UINT24_MAX);
}

void decompose_uint24_be(uint24 a, byte24_ptr b) {
	b[0] = (byte)(a >> 16);
	b[1] = (byte)(a >> 8);
	b[2] = (byte)a;
}
uint24 compose_uint24_be(byte24_ptr a) {
	return	(uint24)((((uint24)(a[0] << 16)) |
				((uint24)(a[1] << 8)) |
				((uint24)(a[2]))) & UINT24_MAX);
}

