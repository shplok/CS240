CC = gcc
CFLAGS = -m32

all: calcit

calcit: main.o getch.o getop.o stack.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c calc.h
	$(CC) $(CFLAGS) -c $<

getch.o: getch.c calc.h
	$(CC) $(CFLAGS) -c $<

getop.o: getop.c calc.h
	$(CC) $(CFLAGS) -c $<

stack.o: stack.c calc.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o calcit
