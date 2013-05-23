#include "readfile.h"

int main() {
	std::vector<std::string> strings = VectReadFile("book.txt");
	VectorSortMove(strings);
}