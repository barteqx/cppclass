#include "union.h"

int main () {
	for (int i = 1; i < 1000000; i++) { 
		unionof<double, int> u(100.12345678, -9000);
		std::cout << u << std::endl << std::endl;
		u = 10;
		std::cout << u << std::endl << std::endl;
		u = static_cast<double>(264.98765);
		std::cout << u << std::endl << "######################" << std::endl;
	}
}