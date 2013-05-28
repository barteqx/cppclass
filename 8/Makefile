main: main.o surface.o
	g++ main.o surface.o -o main

main.o: main.cpp surface.h
	g++ -c -std=c++0x main.cpp -o main.o -c

surface.o: surface.cpp surface.h
	g++ -c -std=c++0x surface.cpp -o surface.o -c
