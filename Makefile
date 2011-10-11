helpers.o : helpers.c helpers.h
	gcc -c helpers.c

42 : helpers.o
	gcc -o problem 42.c helpers.o

clean :
	rm -f problem *.o
