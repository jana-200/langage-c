CFLAGS = -Wall -std=c17 -pedantic -Wvla -Werror -D_DEFAULT_SOURCE

all: encryptPolybe decryptPolybe
 
# Compilation de chaque fichier .c en .o

cryptPolybe.o : cryptPolybe.c cryptPolybe.h
	cc $(CFLAGS) -c cryptPolybe.c

utils_v1.o : ../utils_v1.c ../utils_v1.h
	cc $(CFLAGS) -c ../utils_v1.c


encryptPolybe.o: encryptPolybe.c cryptPolybe.h ../utils_v1.h
	cc $(CFLAGS) -c encryptPolybe.c

decryptPolybe.o: decryptPolybe.c cryptPolybe.h ../utils_v1.h
	cc $(CFLAGS) -c decryptPolybe.c

# Règle principale : compilation de l'exécutable
encryptPolybe: encryptPolybe.o cryptPolybe.o utils_v1.o
	cc $(CFLAGS) -o encryptPolybe encryptPolybe.o cryptPolybe.o utils_v1.o

decryptPolybe: decryptPolybe.o cryptPolybe.o utils_v1.o
	cc $(CFLAGS) -o decryptPolybe decryptPolybe.o cryptPolybe.o utils_v1.o

# Nettoyage
clean:
	rm *.o
	rm encryptPolybe
	rm decryptPolybe
