CC=clang
CFLAGS= #-DDEBUG

main: tamagoshi_cow

options_cow.o: options_cow.c options_cow.h debug.h

tamagoshi_cow: tamagoshi_cow.c options_cow.o

clean:
	rm -f *.o tamagoshi_cow

