helpers.o : helpers.c helpers.h
	gcc -c helpers.c

42 : helpers.o
	gcc -o problem 42.c helpers.o

43 :
	gcc -o problem 43.c

clean :
	rm -f problem *.o
