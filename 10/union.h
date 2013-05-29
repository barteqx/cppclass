#include <iostream>
#include <vector>
#include <string>

template<typename A, typename B> class unionof;

template<typename A, typename B>
std::ostream& operator << (std::ostream& stream, const unionof<A, B> & u);

template<typename T>
std::ostream& operator << (std::ostream& stream, const std::vector<T> & v);

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
	void operator = (const A& x);
	void operator = (const B& x);
	void operator = (const unionof& u);
	const A& first() const;
	A& first();
	const B& second() const;
	B& second();
	bool hasfirst() const;
	bool hassecond() const;
	~unionof();
	friend std::ostream& operator << < > (std::ostream& stream, const unionof<A, B> &);
   friend std::ostream& operator << < > (std::ostream& stream, const std::vector<A> &);
   friend std::ostream& operator << < > (std::ostream& stream, const std::vector<B> &);
};

template<typename A, typename B> 
unionof<A, B>::unionof(const A& a)
   : a(new A(a)), b(nullptr) {}

template<typename A, typename B> 
unionof<A, B>::unionof(const B& b)
   : a(nullptr), b(new B(b)) {}

template<typename A, typename B> 
unionof<A, B>::unionof(const unionof& u)
   : a(u.a ? new A(a) : nullptr),
     b(u.b ? new B(b) : nullptr) {}

template<typename A, typename B> 
void unionof<A, B>::operator = (const A& x) {
   if (a) delete a;
   if (b) delete b;
   a = new A(x);
   b = nullptr;
}

template<typename A, typename B> 
void unionof<A, B>::operator = (const B& x) {
   if (a) delete a;
   if (b) delete b;
   a = nullptr;
   b = new B(x);
}

template<typename A, typename B> 
void unionof<A, B>::operator = (const unionof& u) {
   if (a) delete a;
   else if (b) delete b;
   if (u.a) {
      a = new A(u.a);
      b = nullptr;
   } 
   else if(u.b) {
      a = nullptr;
      b = new B(u.b);
   }
}

template<typename A, typename B> 
const A& unionof<A, B>::first() const {
   if (hasfirst()) return *a;
}

template<typename A, typename B> 
A& unionof<A, B>::first() { if (hasfirst()) return a; } 

template<typename A, typename B> 
const B& unionof<A, B>::second() const {
   if (hassecond()) return *b;
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

template<typename T>
std::ostream& operator << (std::ostream& stream, const std::vector<T> & v) {
   for (unsigned int i = 0; i < v.size(); i++) {
      stream << v[i] << " ";
   }
   return stream;
}

template<typename A, typename B> 
std::ostream& operator << (std::ostream& stream, const unionof<A, B> & u) {
   if (u.hasfirst()) stream << u.first() << std::endl;
   else if (u.hassecond()) stream << u.second() << std::endl;
   return stream;
}

