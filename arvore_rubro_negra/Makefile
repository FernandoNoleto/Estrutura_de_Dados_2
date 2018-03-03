all: main.o
	gcc -o main main.o arn.o
main.o: main.c arn.o
	gcc -c main.c -o main.o
arn.o: arn.h arn.c
	gcc -c arn.c -o arn.o
clean: 
	rm -f *.o main
	