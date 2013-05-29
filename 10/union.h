#include <iostream>

template<typename A, typename B> class unionof;

template<typename A, typename B>
std::ostream& operator << (std::ostream& stream, const unionof<A, B> & u);

template<typename A, typename B>
class unionof
{
	A* a;
	B* b;
	// Invariant: Exactly one of them is non-zero.
public:
	unionof(const A& a);
	unionof(const B& b);
	unionof(const unionof& u);
	unionof(const A& a, const B& b);
	void operator = (const A& a);
	void operator = (const B& b);
	void operator = (const unionof& u);
	const A& first() const;
	A& first();
	const B& second() const;
	B& second();
	bool hasfirst() const;
	bool hassecond() const;
	~unionof();
	friend std::ostream& operator << < > (std::ostream& stream, const unionof<A, B> &);
};

template<typename A, typename B> 
unionof<A, B>::unionof(const A& a)
   : a(new A(a)) {}

template<typename A, typename B> 
unionof<A, B>::unionof(const B& b)
   : b(new B(b)) {}

template<typename A, typename B> 
unionof<A, B>::unionof(const unionof& u)
   : a(u.a ? new A(a) : nullptr),
     b(u.b ? new B(b) : nullptr) {}

template<typename A, typename B> 
unionof<A, B>::unionof(const A& a, const B& b)
   : a(a), b(b) {}

template<typename A, typename B> 
void unionof<A, B>::operator = (const A& a) {
   if (*this -> a) delete *this -> a;
   // if (*this.b) delete *this b;
   *this -> a = new A(a);
}

template<typename A, typename B> 
void unionof<A, B>::operator = (const B& b) {
   // if (*this.a) delete *this.a;
   if (*this -> b) delete *this -> b;
   *this -> b = new A(b);
}

template<typename A, typename B> 
void unionof<A, B>::operator = (const unionof& u) {
   if (a) delete a;
   if (b) delete b;
   a = u.a ? new A(a) : nullptr;
   b = u.b ? new B(b) : nullptr;
}

template<typename A, typename B> 
const A& unionof<A, B>::first() const {
   if (hasfirst()) return new A(a);
}

template<typename A, typename B> 
A& unionof<A, B>::first() { if (hasfirst()) return a; } 

template<typename A, typename B> 
const B& unionof<A, B>::second() const {
   if (hassecond()) return new B(b);
}

template<typename A, typename B> 
B& unionof<A, B>::second() { if (hassecond()) return b; }

template<typename A, typename B> 
bool unionof<A, B>::hasfirst() const { return a;}

template<typename A, typename B> 
bool unionof<A, B>::hassecond() const { return b;}

template<typename A, typename B>
unionof<A, B>::~unionof() {
   delete a;
   delete b;
}

template<typename A, typename B> 
std::ostream& operator << (std::ostream& stream, const unionof<A, B> & u) {
   if (u.hasfirst()) stream << u.first() << std::endl;
   if (u.hassecond()) stream << u.second() << std::endl;
}