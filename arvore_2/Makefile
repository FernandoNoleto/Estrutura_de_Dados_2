all: main.o
	gcc -o main main.o abb.o
main.o: main.c abb.o
	gcc -c main.c -o main.o
abb.o: abb.h abb.c
	gcc -c abb.c -o abb.o
clean: 
	rm -f *.o main
	