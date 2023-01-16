# Variables
CC=gcc
CFLAGS= -c -Wall


# Executables
all: touch cat ls

touch: touch.o helper.o
	$(CC) touch.o helper.o -o touch

cat: cat.o helper.o
	$(CC) cat.o helper.o -o cat

ls: ls.o
	$(CC) ls.o -o ls

# .o files
touch.o: touch.c
	$(CC) $(CFLAGS) touch.c

cat.o : cat.c
	$(CC) $(CFLAGS) cat.c

ls.o: ls.c
	$(CC) $(CFLAGS) ls.c

helper.o: helper.c
	$(CC) $(CFLAGS) helper.c

clean:
	rm -rf *.o touch cat ls