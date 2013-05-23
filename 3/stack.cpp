#include <iostream>
#include "stack.h"

stack::stack() 
	: current_size(0),
		current_capacity(0),
		tab(new double[0]) {}

stack::stack(const stack& s)
  : current_size( s.current_size ),
    current_capacity( s.current_capacity ),
    tab( new double[ s.current_capacity] )
 {
	for (unsigned int i = 0; i < current_size ; i++)
		tab[i] = s.tab[i];
}

stack::~stack() {
	delete[] tab;
}

void stack::ensure_capacity(unsigned int c) {
	if (current_capacity < c) {
		if (c < 2 * current_capacity) 
			c = 2 * current_capacity;
		double* newtab = new double[c];
		for (unsigned int i = 0; i < current_size; i++) 
			newtab[i] = tab[i];
		current_capacity = c;
		delete[] tab;
		tab = newtab;
	}
}

void stack::operator = (const stack& s) {
	ensure_capacity( s.current_size );
	for (unsigned int i = 0; i < s.size(); i++)
	   tab[i] = s.tab[i];
	 current_size = s.current_size;
}

void stack::push(double d) {
	ensure_capacity(current_size + 1);
	tab[current_size++] = d;
}

void stack::reset(unsigned int s) {
	if (s < current_size) current_size = s;
}

double stack::operator [] (unsigned int i) const {
	if (i < current_size)
		return tab[current_size - i - 1];
}

double& stack::operator [] (unsigned int i) {
	if (i < current_size)
		return tab[current_size - i - 1];
}

double stack::top() const {
	return tab[current_size-1];
}
double& stack::top() {
	return tab[current_size-1];
}

void stack::pop() { 
	if (nonempty()) current_size--; 
}

std::ostream& operator << (std::ostream& stream, const stack& s) {
	for (unsigned int i = 0; i < s.size(); i++)
		stream << s[i] << " ";
		stream << std::endl;
	return stream;
}