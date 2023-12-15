/* 
Sawyer Bowerman
10/19/2023
showxbits.c
driver function for the rest of the xbits program.
*/


#include <stdio.h>
#include "xbits.h"

int main(void) {


	char hexstring[9];
	int num = 0;

	while(scanf("%d", &num) == 1) {
	itox(hexstring, num);

	int reconverted = xtoi(hexstring);

	printf("%12d %s %12d\n", num, hexstring, reconverted);
	}




	return 0;
}
