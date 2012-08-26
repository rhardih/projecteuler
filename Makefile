helpers.o : helpers.c helpers.h
	gcc -c helpers.c

12:
	gcc -o problem 12.c

23:
	gcc -o problem 23.c

26:
	gcc -o problem 26.c

33: helpers.o
	gcc -o problem 33.c helpers.o

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

49: helpers.o
	gcc -o problem 49.c helpers.o

50: helpers.o
	gcc -o problem 50.c helpers.o

51: helpers.o
	gcc -o problem 51.c helpers.o

52:
	gcc -o problem 52.c

53: helpers.o
	gcc -lgmp -o problem 53.c helpers.o

clean :
	rm -f problem *.o
