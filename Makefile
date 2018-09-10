CC := gcc
CFLAGS := -W -Wall -pedantic -ansi -lm -Wcomment -std=c99

all:

	$(CC) main.c sort.c vector.c helper.c -o prog $(CFLAGS)

clean:

	rm prog

run:

	./prog