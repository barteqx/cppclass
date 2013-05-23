#include <iostream>

class stack {

	unsigned int current_size;
	unsigned int current_capacity;
	double* tab;

	void ensure_capacity(unsigned int c);

public:
	stack();
	stack(const stack& s);
	~stack();
	void operator = (const stack& s);
	void push(double d);
	void reset(unsigned int s);
	double operator [] (unsigned int i) const;
	double& operator [] (unsigned int i);
	double top() const;
	double& top();
	void pop();
	unsigned int size() const { return current_size; }
	bool nonempty() const { return current_size; }
};

std::ostream& operator << (std::ostream& stream, const stack& s);