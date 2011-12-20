helpers.o : helpers.c helpers.h
	gcc -c helpers.c

42: helpers.o
	gcc -o problem 42.c helpers.o

43:
	gcc -o problem 43.c

44:
	gcc -o problem 44.c

45:
	gcc -o problem 45.c

46: helpers.o
	gcc -o problem 46.c helpers.o

47:
	gcc -o problem 47.c

clean :
	rm -f problem *.o
