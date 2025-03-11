CFLAGS = -Wall -std=c17 -pedantic -Wvla -Werror -D_DEFAULT_SOURCE

all: main 
 
biblio.o : biblio.c biblio.h utils_v1.h
	cc $(CFLAGS) -c biblio.c

utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

main.o : main.c biblio.h
	cc $(CFLAGS) -c main.c

main : main.o biblio.o utils_v1.o
	cc $(CFLAGS) -o main main.o biblio.o utils_v1.o

clean:
	rm *.o
	rm main
