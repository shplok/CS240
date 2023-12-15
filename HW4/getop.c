/*
 * getop.c
 *
 * gets the next token: operator or numeric operand
 */


// SAWYER BOWERMAN :)

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;  /* not a number */

    /* collect integer part in string s */
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    /* collect fractional part in string s */
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    // bitwise operators
    if (c == '~')
        return c;
    else if (c == '^' || c == '|' || c == '&') {
        return c;
    }

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

