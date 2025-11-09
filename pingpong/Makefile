CC=gcc
CFLAGS=-c -g -Wall

all: ping pong

ping: ping.c pingpong.c
	$(CC) -o ping ping.c pingpong.c

pong: pong.c pingpong.c
	$(CC) -o pong pong.c pingpong.c

clean:
	rm -f *.o ping pong pingpong

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $c