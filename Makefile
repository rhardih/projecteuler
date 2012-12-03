helpers.o : helpers.c helpers.h
	gcc -c helpers.c

test: helpers.o
	gcc -o test test.c helpers.o

12:
	gcc -o problem 12.c

23:
	gcc -o problem 23.c

24:
	g++ -o problem 24.cc

26:
	gcc -o problem 26.c

33: helpers.o
	gcc -o problem 33.c helpers.o

35: helpers.o
	gcc -o problem 35.c helpers.o

41: helpers.o
	gcc -o problem 41.c helpers.o

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
	gcc -o problem 53.c helpers.o

54:
	gcc -o problem 54.c

clean :
	rm -f problem test *.o
