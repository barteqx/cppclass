main: main.o stack.o
	g++ -std=c++0x main.o stack.o -o main

test: test.o stack.o 
	g++ -std=c++0x test.o stack.o -o test

stack.o: stack.cpp stack.h 
	g++ -std=c++0x stack.cpp -o stack.o -c -Wall

main.o: main.cpp stack.h
	g++ -std=c++0x main.cpp -o main.o -c

test.o: test.cpp stack.h
	g++ -std=c++0x test.cpp -o test.o -c 


