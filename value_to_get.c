#include <stdio.h>

int get_number();

int main() {

	int bob;
	bob = get_number();
	return 0;
}


int get_number() {

	int value_to_get;
	printf("Enter an Integer : ");
	scanf("%d", &value_to_get);
	return value_to_get;
}
