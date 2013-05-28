#include "surface.h"

double rectangle::area() const {
   return std::abs(x1 - x2) * std::abs(y1-y2);
}

double circle::area() const {
   return radius * radius * 3.14;
}

double triangle::area() const {
   double p = circumference()/2;
   double a = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
   double b = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));
   double c = std::sqrt(std::pow(x2 - x3, 2) + std::pow(y2 - y3, 2));
   return std::sqrt(p*(p - a)*(p - b)*(p - c));
}

double rectangle::circumference() const {
   return std::abs(x1 - x2)*2 + std::abs(y1-y2)*2;
}

double circle::circumference() const {
   return 2 * radius * 3.14;
}

double triangle::circumference() const {
   double a = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
   double b = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));
   double c = std::sqrt(std::pow(x2 - x3, 2) + std::pow(y2 - y3, 2));
   return a + b + c;
}

rectangle* rectangle::clone() const {
   return new rectangle(x1, y1, x2, y2);
}

triangle* triangle::clone() const {
   return new triangle(x1, y1, x2, y2, x3, y3);
}

circle* circle::clone() const {
   return new circle(x, y, radius);
}

void rectangle::print(std::ostream& stream) const {
   stream << "rectangle: x1: " << x1;
   stream << ", y1: " << y1;
   stream << ", x2: " << x2;
   stream << ", y2: " << y2 << std::endl;
   stream << "area: " << area();
   stream << ", circumference: " << circumference() << std::endl;
}

void triangle::print(std::ostream& stream) const {
   stream << "rectangle: x1: " << x1;
   stream << ", y1: " << y1;
   stream << ", x2: " << x2;
   stream << ", y2: " << y2;
   stream << ", x3: " << x3;
   stream << ", y3: " << y3 << std::endl;
   stream << "area: " << area();
   stream << ", circumference: " << circumference() << std::endl;
}

void circle::print(std::ostream& stream) const {
   stream << "rectangle: x: " << x;
   stream << ", y: " << y;
   stream << ", radius: " << radius << std::endl;
   stream << "area: " << area();
   stream << ", circumference: " << circumference() << std::endl;
}

surf::~surf () {};

std::ostream& operator << (std::ostream& stream, const surface& s) {
   s.ref -> print(stream);
   return stream;
}

std::ostream& operator << (std::ostream& stream, const std::vector< surface > & table) {
   for (unsigned int i = 0; i < table.size(); i++) {
      stream << i << "-th element = " << table[i] << "\n";
   }
   return stream;
}

void print_statistics(const std::vector<surface> & table) {
   double total_area = 0.0;
   double total_circumference = 0.0;
   for(auto p = table.begin(); p != table. end(); p++) {
      total_area += p -> getsurf(). area();
      total_circumference += p -> getsurf(). circumference();
      std::cout << "adding info about a " << *p << "\n";
   }
   std::cout << "total area is " << total_area << "\n";
   std::cout << "total circumference is " << total_circumference << "\n\n";
}