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
#include<stdio.h>
#include<libcortex.h>
enum {
#ifndef CapacityIncreaseSize
	CapacityIncreaseSize = 80,
#endif
	EndConstants
};
char* freadline(FILE* f) {
	char* output;
	int curr, count, capacity;
	curr = 0;
	output = NULL;
	if (f && !feof(f)) {
		count = 0;
		capacity = CapacityIncreaseSize;
		output = calloc(CapacityIncreaseSize, sizeof(char));
		for (curr = fgetc(f); curr != '\n' && curr != EOF; curr = fgetc(f)) {
			if (count == capacity) {
				capacity += CapacityIncreaseSize;
				output = realloc(output, capacity);
				if (output == NULL) {
					break;
				} 
			}
			output[count] = curr;
			count++;
		}
		if (count == capacity) {
			output = realloc(output, capacity+1);
			if (output != NULL) {
				output[count+1] = 0;
			}
		}
	}
	return output;
}


