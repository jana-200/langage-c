CFLAGS = -Wall -std=c17 -pedantic -Wvla -Werror -D_DEFAULT_SOURCE

all: secretAgent 
 
# Compilation de chaque fichier .c en .o
cryptROT13.o : ROT13/cryptROT13.c ROT13/cryptROT13.h
	cc $(CFLAGS) -c ROT13/cryptROT13.c

cryptPolybe.o : Polybe/cryptPolybe.c Polybe/cryptPolybe.h
	cc $(CFLAGS) -c Polybe/cryptPolybe.c

cryptMorse.o : Morse/cryptMorse.c Morse/cryptMorse.h
	cc $(CFLAGS) -c Morse/cryptMorse.c

utils_v1.o : utils_v1.c utils_v1.h
	cc $(CFLAGS) -c utils_v1.c

secretAgent.o: secretAgent.c ROT13/cryptROT13.h Polybe/cryptPolybe.h Morse/cryptMorse.h utils_v1.h
	cc $(CFLAGS) -c secretAgent.c

# Règle principale : compilation de l'exécutable
secretAgent: secretAgent.o cryptROT13.o cryptPolybe.o cryptMorse.o utils_v1.o
	cc $(CFLAGS) -o secretAgent secretAgent.o cryptROT13.o cryptPolybe.o cryptMorse.o utils_v1.o


# Nettoyage
clean:
	rm *.o
	rm secretAgent
