#include "readfile.h"

int main() {
	std::list<std::string> strings = ListReadFile("book.txt");
	removeshortstrings(strings, 20);
	std::cout << strings;
}