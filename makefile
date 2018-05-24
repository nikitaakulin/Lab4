CC=gcc
CFLAGS=-I.

all : process_memory parallel_min_max

parallel_sum : utils.o utils.h
	$(CC) -o parallel_sum utils.o parallel_sum.c $(CFLAGS)

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max find_min_max.o utils.o parallel_min_max.c $(CFLAGS)

process_memory :
	$(CC) -o process_memory -c process_memory.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max : utils.h find_min_max.h
	$(CC) -o find_min_max -c find_min_max.c $(CFLAGS)

clean :
	rm utils.o find_min_max parallel_sum parallel_min_max
