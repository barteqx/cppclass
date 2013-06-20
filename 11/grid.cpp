#include "grid.h"

grid::grid (const grid& g) 
   : xsize(g.xsize),
     ysize(g.ysize),
     c(new cell[g.xsize*g.ysize]) {

   for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) {
         (*this)[i][j] = g[i][j];
      }
   }
}


void grid::operator = (const grid& g) {

   if (this != &g) {
      delete[] c;

      xsize = g.xsize;
      ysize = g.ysize;
      c = new cell[xsize*ysize];

      for (int i = 0; i < ysize; i++) {
         for (int j = 0; j < xsize; j++)
         {
            (*this)[i][j].s0 = g[i][j].s0;
            (*this)[i][j].s1 = g[i][j].s1;
         }
      }
   }
}

grid::~grid () { delete[] c; }

void grid::clear () { 
   for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) {
         (*this)[i][j].s0 = false;
         (*this)[i][j].s1 = false;
      }
   }
}

void grid::add(unsigned int x, unsigned int y, const std::vector< std::vector<bool>> & vec) {
   for (int i = 0; i < vec.size(); i++) {
      for (int j = 0; j < vec[i].size(); j++) {
         (*this)[x+i][y+j].s0 = vec[i][j];
      }
   }
}

void grid::nextgeneration() {

   int neighbours[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {1, -1}, {-1, 0}, {-1, -1}, {0, -1}};

   for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) {
         
         int count = 0;
         for (int n = 0; n < 8; n++) {
            if ((*this)[(i+neighbours[n][0]) % xsize][(j+neighbours[n][1]) % ysize].s0) count++;
         }

         if (count < 2 && (*this)[i][j].s0) (*this)[i][j].s1 = false;
         else if ((count == 2 || count == 3) && (*this)[i][j].s0) (*this)[i][j].s1 = true;
         else if (count > 3 && (*this)[i][j].s0) (*this)[i][j].s1 = false;
         else if (count == 3 && !(*this)[i][j].s0) (*this)[i][j].s1 = true;
      }
   }

   for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) (*this)[i][j].s0 = (*this)[i][j].s1;
   }
}


std::ostream& operator << (std::ostream& stream, const grid& g) {
   for (int j = g.ysize - 1; j > 0; j--) {
      for (int i = 0; i < g.xsize; i++) {
         stream << (g[i][j].s0 ? '#' : '.');
      }
      stream << std::endl;
   }

   return stream;
}

void grid::plot() const {
   glColor3f(0, 0, 1);
   for (int j = ysize - 1; j >= 0; j--) {
      for (int i = 0; i < xsize; i++){
         if ((*this)[i][j].s0 == true) {
            i -= xsize/2;
            j -= ysize/2;
            glBegin( GL_POLYGON );
               glVertex3f( i, j, 0 );
               glVertex3f( i + 1, j, 0 );
               glVertex3f( i + 1, j + 1, 0 );
               glVertex3f( i, j + 1, 0 );
            glEnd( );
            i += xsize/2;
            j += ysize/2;
         }
      }
   }
   glFlush();
}