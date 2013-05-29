#include <cmath>
#include <iostream>
#include <vector>

class surf {
public:
   virtual double area() const = 0;
   virtual double circumference() const = 0;
   virtual surf* clone() const = 0;
   virtual void print(std::ostream&) const = 0;
   virtual ~surf() = 0;
};

class rectangle : public surf {

public:
   double x1, y1;
   double x2, y2;

   rectangle(double a, double b, double c, double d)
   : x1(a), y1(b), x2(c), y2(d) {}

   double area() const;
   double circumference() const;
   rectangle* clone() const;
   void print(std::ostream&) const;
};

class triangle : public surf {

public:
   double x1, y1; // Positions of corners.
   double x2, y2;
   double x3, y3;

   triangle(double a, double b, double c, double d, double e, double f)
   : x1(a), y1(b), x2(c), y2(d), x3(e), y3(f) {}

   double area() const;
   double circumference() const;
   triangle* clone() const;
   void print(std::ostream&) const;
};

class circle : public surf {

public:
   double x; // Position of center.
   double y;
   double radius;

   circle(double a, double b, double r)
   : x(a), y(b), radius(r) {}

   double area() const;
   double circumference() const;
   circle* clone() const;
   void print(std::ostream&) const;
};

struct surface {
   
   surf* ref;

   surface(const surface& s)
   : ref(s.ref -> clone()) {}

   surface(const surf& s)
   : ref(s.clone()) {}

   void operator = (const surface& s) {
      if(ref != s.ref) {
         delete ref;
         ref = s.ref -> clone();
      }
      // I am not in favour of making assignment
      // return something.
   }

   ~surface() {
      delete ref;
   }

   const surf& getsurf() const { return *ref; }
      // There is no non-const method, because
      // changing would be dangerous.
};

std::ostream& operator << (std::ostream& stream, const surface& s);

std::ostream& operator << (std::ostream& stream, const std::vector<surface> & table);

void print_statistics(const std::vector<surface> & table);
