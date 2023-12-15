/*
Sawyer Bowerman
10/19/2023
xbits.c
Depending on the function, this program either takes an integer or hexstring as input and returns the calculated inverse.
*/



#include <stdio.h>
#include "xbits.h"



/* Itox Pseudocode

	if n is less than 0, leave and claim the input is invalid.

	set the index to the size of an int + 1 to make space for the null terminator
	if n is equal to zero, we can make a special case to just print zero
	otherwise,
		while the index is greater than 0
			calculate and then return the hexstring value of the given int.
*/




/* Function represents the int n as a hexstring which it places in the hexstring array */
void itox(char hexstring[], int n) {
    

	if (n < 0){
                printf("invalid input\n");
                return;
        }

        int index = 2 * sizeof(int) + 1; // add null terminator at the end
	hexstring[index] = '\0';
        

	if(n == 0) {
		 hexstring[index - 1] = '0';
	} else {

		while (index > 0) {     // start at the end and traverse back, perform the operation.
        	        index--;
               		int remainder = n % 16;
                	if (remainder < 10) {
                        	hexstring[index] = '0' + remainder;
                	} else {
                        	hexstring[index] = 'A' + (remainder - 10);
                	}
                	n /= 16;
		}
        }
        printf("in itox, processing %s\n",hexstring);
}




/* Xtoi Pseudocode

	while the index of hexstring is not equal to the null terminator
		increase the length variable until we get to the null terminator

			
	while the hexxtring at index i meets all of our conditions,
		increment i 
		check each value and remove what is necessary
	
		loop through the length
			do the reverse of the arithmetic from before in order to get the int value.		

		return the xtoi value.
*/





	

/* function converts hexstring array to equivalent integer value  */
int xtoi( char hexstring[]) {
	
	int intConvert = 0;
	int length = 0;
	int i = 0;

	while(hexstring[length] != '\0'){
		length++;
	}
	
	while (hexstring[i] == '0' && i < length -1) {
		i++;
	}

	if (hexstring[i] >= '0' &&  hexstring[i] <= '9') {
		intConvert = hexstring[i] - '0';
	} else if (hexstring[i] >= 'A' && hexstring[i] <= 'F') {
		intConvert = hexstring[i] - 'A' + 10;
	} else {
		return -1;
	}

	for (i++; i < length; i++){

		char c = hexstring[i];
		
		if (c >= '0' && c <= '9') {
			intConvert = intConvert * 16 + (c - '0');
		} else if (c >= 'A' && c <= 'F') {
			intConvert = intConvert * 16 +  (c - 'A' + 10);
		} else {
			return -1;
		}

	}
	printf("in xtoi, processing %d\n", intConvert);
	return intConvert;
 }
