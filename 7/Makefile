main: map.o main.o
	g++  main.o map.o -o main

main.o: main.cpp map.h
	g++ -c -std=c++0x main.cpp -o main.o -c

map.o: map.cpp map.h
	g++ -c -std=c++0x map.cpp -o map.o -c