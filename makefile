# Variables
CC=gcc
CFLAGS= -c -Wall


# Executables
all: touch cat ls pwd head

touch: touch.o helper.o
	$(CC) touch.o helper.o -o touch

cat: cat.o helper.o
	$(CC) cat.o helper.o -o cat

ls: ls.o
	$(CC) ls.o -o ls

pwd: pwd.o
	$(CC) pwd.o -o pwd

head: head.o helper.o
	$(CC) head.o helper.o -o head

# .o files
touch.o: touch.c
	$(CC) $(CFLAGS) touch.c

cat.o : cat.c
	$(CC) $(CFLAGS) cat.c

ls.o: ls.c
	$(CC) $(CFLAGS) ls.c

pwd.o: pwd.c 
	$(CC) $(CFLAGS) pwd.c

head.o: head.c
	$(CC) $(CFLAGS) head.c 

helper.o: helper.c
	$(CC) $(CFLAGS) helper.c

clean:
	rm -rf *.o touch cat ls