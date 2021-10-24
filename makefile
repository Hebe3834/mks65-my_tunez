all: main.o library.o list.o
	gcc -o output main.o library.o list.o

main.o: main.c library.h list.h
	gcc -c main.c

library.o: library.c library.h list.h
	gcc -c library.c

list.o: list.c list.h
	gcc -c list.c

run:
	./output

clean:
	rm *.o