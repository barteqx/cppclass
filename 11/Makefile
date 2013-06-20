Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++0x
Link = -lGL -lGLU -lsfml-graphics -lsfml-window -lsfml-system
CPP = g++

main: main.o grid.o
	$(CPP) $(Flags) grid.o main.o $(Link) -o main
main.o: main.cpp grid.h
	$(CPP) -c $(Flags) main.cpp -o main.o
grid.o: grid.cpp grid.h
	$(CPP) -c $(Flags) grid.cpp -o grid.o