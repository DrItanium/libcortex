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

int fread_uint48_seq(FILE* a, byte48_ptr b) {
	int r0, r1, r2, r3, r4, r5;
	// endianness is not important at this point as we are just reading bytes
	r0 = fgetc(a);
	r1 = fgetc(a);
	r2 = fgetc(a);
	r3 = fgetc(a);
	r4 = fgetc(a);
	r5 = fgetc(a);
	if (r0 == EOF || r1 == EOF || r2 == EOF || r3 == EOF || r4 == EOF || r5 == EOF) {
		return 0;
	} else {
		b[0] = r0;
		b[1] = r1;
		b[2] = r2;
		b[3] = r3;
		b[4] = r4;
		b[5] = r5;
		return 1;
	}
}
