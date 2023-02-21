CC=gcc
CFLAGS= -c -Wall

all: ls

test: test_util.out

ls: ls.o util.o
	$(CC) ls.o util.o -o ls

test_util: test_util.o util.o
	$(CC) test_util.o util.o -o test_util

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o
