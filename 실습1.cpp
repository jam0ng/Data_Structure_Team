#include <stdio.h>

int main(void) {

	int val = 21;			/* 00000000 => 00000015*/
	int val_minus = -21;	/* 00000000 => ffffffeb*/
	int result = 0;			/* 00000179 => 00000000*/
	
	result = val + val_minus;	/*00000000*/
	printf("result is %d\n", result);
	
	return 0;

}