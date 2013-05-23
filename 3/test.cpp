#include <iostream>
#include "stack.h"
#include <cstdio>

int main() {

	stack s1;

	s1.push(111);
	const stack s2(s1);
	double& i = s1[0];
	double j = s2[0];
	i = 3;
	j = 3;
	std::cout << s1;
	std::cout << s2;
	return 0;
}