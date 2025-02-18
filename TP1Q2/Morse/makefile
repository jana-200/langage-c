CFLAGS = -Wall -std=c17 -pedantic -Wvla -Werror -D_DEFAULT_SOURCE

all: encryptMorse decryptMorse
  
# Compilation de chaque fichier .c en .o
cryptMorse.o : cryptMorse.c cryptMorse.h
	cc $(CFLAGS) -c cryptMorse.c

utils_v1.o : ../utils_v1.c ../utils_v1.h
	cc $(CFLAGS) -c ../utils_v1.c

encryptMorse.o: encryptMorse.c cryptMorse.h ../utils_v1.h
	cc $(CFLAGS) -c encryptMorse.c

decryptMorse.o: decryptMorse.c cryptMorse.h ../utils_v1.h
	cc $(CFLAGS) -c decryptMorse.c


# Règle principale : compilation de l'exécutable
encryptMorse: encryptMorse.o cryptMorse.o utils_v1.o
	cc $(CFLAGS) -o encryptMorse encryptMorse.o cryptMorse.o utils_v1.o

decryptMorse: decryptMorse.o cryptMorse.o utils_v1.o
	cc $(CFLAGS) -o decryptMorse decryptMorse.o cryptMorse.o utils_v1.o


# Nettoyage
clean:
	rm *.o
	rm encryptMorse
	rm decryptMorse
