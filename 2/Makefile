main: main.o rational.o vector.o
	g++ -std=c++0x main.o rational.o vector.o -o main

vector.o: vector.cpp rational.h vector.h
	g++ -std=c++0x -c vector.cpp -o vector.o

rational.o: rational.cpp rational.h
	g++ -std=c++0x -c rational.cpp -o rational.o

main.o: main.cpp rational.h vector.h
	g++ -std=c++0x -c main.cpp -o main.o	


