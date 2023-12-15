CC = gcc
CFLAGS = -m32

all: tail

tail: tail.o lineholder.o
	$(CC) $(CFLAGS) $^ -o $@

tail.o: tail.c lineholder.h
	$(CC) $(CFLAGS) -c $<

lineholder.o: lineholder.c lineholder.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o tail

