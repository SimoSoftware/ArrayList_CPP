lib.o: lib.cpp ArrayList.h
	g++-7.3 -c lib.cpp

main.o: main.cpp ArrayList.h
	g++-7.3 -c main.cpp

main.x: main.o lib.o
	g++-7.3 main.cpp lib.cpp -o main.x
