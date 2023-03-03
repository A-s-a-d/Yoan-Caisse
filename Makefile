CC=gcc
CFLAGS=-g -O2 -Wall -std=c11 -Wextra 
LDFLAGS=
OBJECTS=main.o panier.o chiffrement.o fichiers.o produits.o personnes.o utils.o
BINARY=caisse

all: $(BINARY)

$(BINARY): main.o $(OBJECTS) 
	$(CC) -o $@ $^

%.o: %.c %.h  definitions.h
	$(CC) $(CFLAGS) -o $@  -c $<

clean:
	rm -f *.o

mrproper: 
	make clean
	rm -f $(BINARY)
