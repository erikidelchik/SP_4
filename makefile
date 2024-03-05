
all:digitcompress

digitcompress: encodemain.o compress.a
	gcc -o digitcompress encodemain.o compress.a

compress.a: compress.o
	ar -rcs compress.a compress.o

encodemain.o: encodemain.c compress.h
	gcc -c -Wall encodemain.c -o encodemain.o

compress.o: compress.c
	gcc -c -Wall compress.c -o compress.o
	
	
clean:
	rm -f *.o *.a digitcompress
