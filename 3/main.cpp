#include <iostream>
#include "stack.h"
#include <cstdio>

int main() {
	for(unsigned int i = 0; i < 1000000; i++) {
		stack s1;
		s1.push(45); s1.push(45); s1.push(46);

		stack s2 = s1;
		s2.push(2000); s2.push(2000);
		s1 = s2;
		std::cout << s1;
	}
	return 0;
}