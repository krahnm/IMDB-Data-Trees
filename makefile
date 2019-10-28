
CC = gcc
CFLAGS = -ansi -g -Wall -pedantic

all: a3.o binary.o common.o name.o principals.o title.o
	$(CC) -o a3 a3.o binary.o common.o name.o principals.o title.o
 
a3.o: a3.c common.h binary.h name.h principals.h title.h
	$(CC) $(CFLAGS) -c a3.c
	
binary.o: binary.c common.h
	$(CC) $(CFLAGS) -c binary.c
	
common.o: common.c
	$(CC) $(CFLAGS) -c common.c

name.o: name.c binary.h common.h
	$(CC) $(CFLAGS) -c name.c
	
principals.o: principals.c binary.h common.h
	$(CC) $(CFLAGS) -c principals.c
	
title.o: title.c binary.h common.h
	$(CC) $(CFLAGS) -c title.c


clean:
	rm *.o ./a3
