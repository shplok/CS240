/*
 * stack.c
 *
 * stack routines
 */

#include <stdio.h>
#include "calc.h"
#define MAXVAL 100  /* maximum depth of val stack */

/* even better, we could make the following two defines "static"
   and thus hide these data structures from the rest of the sources */
static int sp = 0;         /* next free stack position */
static int val[MAXVAL]; /* value stack */


/* push: push f onto value stack */
void push(int f)
{
    if (sp < MAXVAL)
	val[sp++] = f;
    else
	printf("error: stack full, can't push %d\n", f);
}

/* pop: pop and return top value from stack */

int pop(void)
{
    if (sp > 0)
	return val[--sp];
    else
      {
	printf("error: stack empty\n");
	return 0;
      }
}


// bitwise operators

void bitwiseXOR(void) {

    if(sp >= 2){
        push(pop() ^ pop());
    } else {
	printf("error: not enough arguments for XOR\n");
	}
}

void bitwiseOR(void) {

    if(sp >= 2) {
        push(pop() | pop());
    } else {
	printf("error: not enough arguments for OR\n");
    }
    
}

void bitwiseAND(void) {

    if(sp >= 2) {
        push(pop() & pop());
	} else {
		printf("error: not enough arguments for AND\n");
	}
}

void bitwiseNOT(void) {

    if(sp >= 1) {
        push(~pop());
    } else {
	printf("error: not enough arguments for NOT\n");
	}
}
