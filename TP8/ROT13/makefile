CFLAGS = -Wall -std=c17 -pedantic -Wvla -Werror -D_DEFAULT_SOURCE

all: encryptROT13 decryptROT13
 
# Compilation de chaque fichier .c en .o
cryptROT13.o : cryptROT13.c cryptROT13.h
	cc $(CFLAGS) -c cryptROT13.c

utils_v1.o : ../utils_v1.c ../utils_v1.h
	cc $(CFLAGS) -c ../utils_v1.c

encryptROT13.o: encryptROT13.c cryptROT13.h ../utils_v1.h
	cc $(CFLAGS) -c encryptROT13.c

decryptROT13.o: decryptROT13.c cryptROT13.h ../utils_v1.h
	cc $(CFLAGS) -c decryptROT13.c

# Règle principale : compilation de l'exécutable
encryptROT13: encryptROT13.o cryptROT13.o utils_v1.o
	cc $(CFLAGS) -o encryptROT13 encryptROT13.o cryptROT13.o utils_v1.o

decryptROT13: decryptROT13.o cryptROT13.o utils_v1.o
	cc $(CFLAGS) -o decryptROT13 decryptROT13.o cryptROT13.o utils_v1.o


# Nettoyage
clean:
	rm *.o
	rm encryptROT13
	rm decryptROT13
