
#include "rational.h"

std::ostream& operator << ( std::ostream& stream, const rational& r ) 
{
   stream << r. num << " / " << r. denum;
   return stream;
}

bool operator == ( const rational& r1, const rational& r2 ) {
	if (r1.num*r2.denum == r2.num*r1.denum) return true;
	else return false;
}

bool operator != ( const rational& r1, const rational& r2 ) {
	return !(r1 == r2);
}

bool operator < ( const rational& r1, const rational& r2 ) {
	if (r1.num*r2.denum < r2.num*r1.denum) return true;
	else return false;
}

bool operator > ( const rational& r1, const rational& r2 ) {
	if (r1.num*r2.denum > r2.num*r1.denum) return true;
	else return false;
}
ss
bool operator <= ( const rational& r1, const rational& r2 ) {
	return !(r1 > r2);
}

bool operator >= ( const rational& r1, const rational& r2 ) {
	return !(r1 < r2);
}

int rational::gcd( int num, int denum ) {
	while (denum != 0) {
		int c = num % denum;
		num = denum;
		denum = c;
	}
	return num;
}

rational operator - ( const rational& r ) {
	rational r1(-r.num, r.denum);
	return r1;
}

rational operator + ( const rational& r1, const rational& r2 ) {
	int newnum = r1.num*r2.denum + r2.num*r1.denum;
	int newdenum = r2.denum * r1.denum;
	int gcd = rational::gcd(newnum, newdenum);
	return rational(newnum/gcd, newdenum/gcd);
}

rational operator - ( const rational& r1, const rational& r2 ) {
	int newnum = r1.num*r2.denum - r2.num*r1.denum;
	int newdenum = r2.denum * r1.denum;
	int gcd = rational::gcd(newnum, newdenum);
	return rational(newnum/gcd, newdenum/gcd);
}

rational operator * ( const rational& r1, const rational& r2 ) {
	int newnum = r1.num * r2.num;
	int newdenum = r2.denum * r1.denum;
	int gcd = rational::gcd(newnum, newdenum);
	return rational(newnum/gcd, newdenum/gcd);
}

rational operator / ( const rational& r1, const rational& r2 ) {
	int newnum = r1.num * r2.denum;
	int newdenum = r2.denum * r1.num;
	int gcd = rational::gcd(newnum, newdenum);
	return rational(newnum/gcd, newdenum/gcd);
}