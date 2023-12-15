/* main comments
*/

#include <stdio.h>

// function prototype here

int get_number();

int main(void) {
	int my_number = get_number();
	printf("%d \n", my_number);
	return 0;
}

// function definition

int get_number() {

	int number = 0;
	printf("Enter a number : ");
	scanf("%d", &number);
	return number;
}
