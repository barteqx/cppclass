#include "union.h"



int main () {
	for (int i = 1; i < 1000000; i++) {
		unionof<std::string, std::vector<int>> u(std::string("abcd"));
		std::cout << u << std::endl << std::endl;
		u = std::vector<int>({2,2,2});
		auto u1 = u;
		u1 = std::string( "XXX" );
		u = u1;
		u1 = u;
		std::cout << u << std::endl << "######################" << std::endl;
	}
}
