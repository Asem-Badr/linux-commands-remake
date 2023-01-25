# Variables
CC=gcc
CFLAGS= -c -Wall


# Executables
all: touch cat ls pwd head echo tail

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

echo: echo.o helper.o
	$(CC) echo.o helper.o -o echo

tail: tail.o helper.o
	$(CC) tail.o helper.o -o tail

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

echo.o :echo.c
	$(CC) $(CFLAGS) echo.c

tail.o: tail.c
	$(CC) $(CFLAGS) tail.c

helper.o: helper.c
	$(CC) $(CFLAGS) helper.c



clean:
	rm -rf *.o touch cat ls pwd head echo tail