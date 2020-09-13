helpers.o : helpers.c helpers.h
	gcc -c helpers.c

test: helpers.o
	gcc -o test test.c helpers.o

%:
	gcc -o problem $@.c && ./problem

24:
	g++ -o problem 24.cc

33: helpers.o
	gcc -o problem 33.c helpers.o

35: helpers.o
	gcc -o problem 35.c helpers.o

36: helpers.o
	gcc -o problem 36.c helpers.o

37: helpers.o
	gcc -o problem 37.c helpers.o

38: helpers.o
	gcc -o problem 38.c helpers.o

41: helpers.o
	gcc -o problem 41.c helpers.o

42: helpers.o
	gcc -o problem 42.c helpers.o

46: helpers.o
	gcc -o problem 46.c helpers.o

49: helpers.o
	gcc -o problem 49.c helpers.o

50: helpers.o
	gcc -o problem 50.c helpers.o

51: helpers.o
	gcc -o problem 51.c helpers.o

53: helpers.o
	gcc -o problem 53.c helpers.o

55: helpers.o
	gcc -o problem 55.c helpers.o

56:
	gcc -o problem -I /usr/local/include -L /usr/local/lib -lgmp 56.c

57:
	gcc -o problem -I /usr/local/include -L /usr/local/lib -lgmp 57.c

clean :
	rm -f problem test *.o
