/* Name: Sawyer Bowerman
   Date: 10/01/2023
   File: reverse.c
   Description: This file reads a file of strings from command line input until EOF is reached.
*/



/*

Reverse function pseudocode
	
	While the EOF is not reached
		While the line we are on does not have an indicator to stop
			get the length of the line and assign it to a variable
			terminate the string using '\0'
		assign a temp value array and do the switch.
		print that value and move to the next line!
	*/


#include <stdio.h>

#define MAXLINE 1000


void reverse(void);

int main(void) {
    reverse();
    return 0;
}


void reverse(void) {
    char line[MAXLINE];
    int len;
    int c;

    while (1) {
        len = 0; // Reset the length for each line

        while ((c = getchar()) != '\n' && c != EOF && len < MAXLINE - 1) {
            line[len++] = c;
        }

        if (c == EOF) {
            break; // End the loop when EOF is encountered
        }

        line[len] = '\0'; // Null-terminate the string

        for (int i = 0; i < len / 2; i++) {
            char charTemp = line[i];
            line[i] = line[len - 1 - i];
            line[len - 1 - i] = charTemp;
        }

        printf("%s\n", line);
    }
}


