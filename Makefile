CC = gcc
CFLAGS = -Wall -std=c99

all: test

points_segments_naive.o: points_segments_naive.c points_segments.h
	$(CC) $(CFLAGS) -c points_segments_naive.c

points_segments_fast.o: points_segments_fast.c points_segments.h
	$(CC) $(CFLAGS) -c points_segments_fast.c

test.o: test.c points_segments.h
	$(CC) $(CFLAGS) -c test.c

test: points_segments_naive.o points_segments_fast.o test.o
	$(CC) $(CFLAGS) -o test points_segments_naive.o points_segments_fast.o test.o

clean:
	rm *.o test