CC=gcc
CFLAGS=-c -g -Wall

all: recv_signal send_signal signal_alarm signal_handler signal_segfault signal_sigaction

recv_signal: recv_signal.c
	$(CC) -o recv_signal recv_signal.c

send_signal: send_signal.c
	$(CC) -o send_signal send_signal.c

signal_alarm: signal_alarm.c
	$(CC) -o signal_alarm signal_alarm.c

signal_handler: signal_handler.c
	$(CC) -o signal_handler signal_handler.c

signal_segfault: signal_segfault.c
	$(CC) -o signal_segfault signal_segfault.c

signal_sigaction: signal_sigaction.c
	$(CC) -o signal_sigaction signal_sigaction.c

clean:
	rm -f *.o recv_signal send_signal signal_alarm signal_handler signal_segfault signal_sigaction

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $c