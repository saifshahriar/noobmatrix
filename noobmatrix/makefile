CC=clang
CFLAGS=-g -Wall
OBJS=main.o matrix.o ui.o

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses
	cp main nmatrix

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o main nmatrix

install:
	make
	cp -f main /bin/nmatrix
	echo "\033[0;32mSuccessfully installed!"
