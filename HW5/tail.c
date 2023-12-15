/*
 * Sawyer Bowerman
 * 11/26/2023
 * tail.c
 * Calls init_lineholder(int nlines) with the number from the command line.
 * Does a loop calling getline and insert_line(char *line).
 * When getline returns 0 (indicating EOF on stdin), it calls print_lines().
 */



// tail.c

#include <stdio.h>
#include <stdlib.h>
#include "lineholder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_lines>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int nlines = atoi(argv[1]);
    if (nlines <= 0 || nlines >= 2000) {
        fprintf(stderr, "Number of lines should be between 1 and 1999\n");
        exit(EXIT_FAILURE);
    }

    init_lineholder(nlines);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        insert_line(line);
    }

    if (line) {
        free(line);
    }

    print_lines(nlines);

    return 0;
}
