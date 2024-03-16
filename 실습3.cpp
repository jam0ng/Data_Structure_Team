#include <stdio.h>

int main(void) {

	int num = 10;		/* cccccccc => 0000000a*/
	int* pnum = &num;	/* cccccccc cccccccc => 80dbf894 00000026 */

	printf("%d", sizeof(char*));
	printf(" %d , %d \m", num, *pnum);

	return 0;
}