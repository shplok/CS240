/*
Sawyer Bowerman
11/26/2023
lineholder.c
contains a static array of pointers for lines.
 Implements init_lineholder, insert_line, and print_lines.
 Init_lineholder initializes the "first" slot and related variables.
 Insert_line adds a line to the array.
It must allocate memory for the new line.
It must free the memory for a line no longer needed, if any.
 Print_lines prints the lines in the array and frees the memory used for them
*/


// lineholder.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lineholder.h"

#define MAX_LINES 2000
#define MAX_LENGTH 1001

static char *lines[MAX_LINES];
static int current_line = 0;
static int total_lines = 0;

void init_lineholder(int nlines) {
    for (int i = 0; i < MAX_LINES; ++i) {
        lines[i] = NULL;
    }
    current_line = 0;
    total_lines = 0;
}

void insert_line(char *line) {
    if (lines[current_line] != NULL) {
        free(lines[current_line]);
    }

    lines[current_line] = strdup(line);

    current_line = (current_line + 1) % MAX_LINES;
    total_lines++;
}

void print_lines(int n) {
    int start = (current_line - total_lines + MAX_LINES) % MAX_LINES;

    // Ensure n is not greater than the total number of lines
    if (n > total_lines) {
        n = total_lines;
    }

    // Create an array to store the last n lines
    char **lastNLines = malloc(n * sizeof(char *));
    if (lastNLines == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Copy the last n lines into the array
    for (int i = total_lines - n; i < total_lines; ++i) {
        int index = (start + i) % MAX_LINES;
        lastNLines[i - (total_lines - n)] = strdup(lines[index]);
    }

    // Print the last n lines in their original order
    for (int i = 0; i < n; ++i) {
        printf("%s", lastNLines[i]);
        free(lastNLines[i]);
    }

    free(lastNLines);
}

