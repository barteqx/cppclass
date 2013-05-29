main: main.o union.o
	g++ main.o union.o -o main

main.o: main.cpp union.h
	g++ -c -std=c++0x main.cpp -o main.o -c

union.o: union.cpp union.h
	g++ -c -std=c++0x union.cpp -o union.o -c
