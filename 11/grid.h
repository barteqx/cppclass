#include <initializer_list>
#include <iostream>
#include <vector>

#include <SFML/OpenGL.hpp>

struct OutOfTable {};

class grid;

std::ostream& operator << (std::ostream&, const grid&);

class grid {
   
   struct cell
   {
      bool s0; // Current state.
      bool s1; // Next state.
      cell( ) : s0( false ), s1( false ) { }
   };

   unsigned int xsize;
   unsigned int ysize;

   cell* c;

public:
   grid (unsigned int xsize, unsigned int ysize)
      : xsize(xsize),
        ysize(ysize),
        c(new cell[xsize*ysize])
   { }

   grid (const grid& g);

   void operator = (const grid& g);
   ~grid();

   cell* operator [] (unsigned int x) {
      return c + x * ysize;
   }

   const cell* operator[] (unsigned int x) const {
      return c + x * ysize;
   }

   void clear();

   void add(unsigned int x, unsigned int y, const std::vector< std::vector<bool>> &);

   void nextgeneration();

   void plot() const;

   friend std::ostream& operator << (std::ostream&, const grid&);

   bool on_table(int x, int y);
};