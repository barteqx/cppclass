#include "readfile.h"

int main() {
	std::list<std::string> strings = ListReadFile("book.txt");
	ListSortMove(strings);
}