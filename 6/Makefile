main: vsc vsm lsc lsm rmlist

vsc: vect_sort_copy.cpp readfile.o
	g++ -std=c++11 vect_sort_copy.cpp readfile.o -o vsc

vsm: vect_sort_move.cpp readfile.o
	g++ -std=c++11 vect_sort_move.cpp readfile.o -o vsm

lsc: list_sort_copy.cpp readfile.o
	g++ -std=c++11 list_sort_copy.cpp readfile.o -o lsc

lsm: list_sort_move.cpp readfile.o
	g++ -std=c++11 list_sort_move.cpp readfile.o -o lsm

rmlist: rmlist.cpp readfile.o
	g++ -std=c++11 rmlist.cpp readfile.o -o rmlist

readfile.o: readfile.cpp readfile.h
	g++ -std=c++11 readfile.cpp -o readfile.o -c
