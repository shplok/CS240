#include <stdio.h>
int main (void) {
	int c, m;
	m = 0;
	while ((c=getchar()) != EOF) {
		if (c == '\n') {
			++m;
		}
	} 
	return 0;
}
