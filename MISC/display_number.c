#include <stdio.h>

void display_number (const int a_number);

int main () {
	int bob = 5;
	display_number(bob);
	return 0;
}

void display_number (const int a_number) {

	printf("%d \n" , a_number);
	return;
}
