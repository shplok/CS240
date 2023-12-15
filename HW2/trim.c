/* Name: Sawyer Bowerman
   Date: 09/28/2023
   File: trim.c
   Description: This program trims the trailing whitespace from a given file input. */



/*
	while there is space in the line
		traverse through all blank characters until a non-blank one is found.
		add a null line terminator at i+1.
		print the line with a newline character
	return. */



#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);

int main(void) {
    char line[MAXLINE];
    int length;

    while ((length = mygetline(line, MAXLINE)) > 0) {
        int i = length - 1;

        // Find the first non-blank character or the beginning of the line
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
            --i;
        }

        // If a non-blank character is found, add a null terminator
        if (i >= 0) {
            line[i + 1] = '\0'; // Null-terminate the line
            printf("%s\n", line); // Print the line
        }
    }

    return 0;
}

int mygetline(char line[],int maxline){
    int c, i;
    for (i=0; i < maxline-1 &&(c=getchar())!=EOF &c!='\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}



