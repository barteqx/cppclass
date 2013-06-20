#include "fifteen.h"
#include "move.h"
#include <map>
#include <queue>
#include <cmath>

inline std::ostream& operator << (std::ostream& stream, illegalmove i) {
   stream << "Illegal move: " << i.m << std::endl;
   return stream;
}

fifteen solve(const fifteen& f) {
   std::map<fifteen, bool, fifteen_cmp> reached;
   reached[f] = true;

   std::priority_queue<fifteen, std::vector<fifteen>, fifteen_better> unchecked; 
   unchecked.push(f);

   std::vector<move> moves = { move_up, move_down, move_left, move_right };

   while(unchecked.size()) {
      fifteen best = unchecked.top();
      unchecked.pop();

      if (best.issolved()) return best;

      for (auto m = moves.begin(); m != moves.end(); m++) {
         fifteen newMove = best;
         try { newMove.makemove(*m); }
         catch (illegalmove im) { continue; }

         if (!reached[newMove]) {
            reached[newMove] = true;
            unchecked.push(newMove);
         }
      }
   }
}

fifteen::fifteen () 
  : x(3), y(3)
  {
   for (int i = 0; i < 16; i++) {
      table[i/4][i%4] = (i+1) % 16;
   }
}

fifteen::fifteen (unsigned int _table[4][4]) {
   for (int i = 0; i < 16; i++) {
      table[i/4][i%4] = _table[i/4][i%4];
      if (table[i/4][i%4] == 0) { x = i/4; y = i%4; }
   }
}

unsigned int fifteen::distance () const {

   unsigned int dist = 0;

   std::pair<int, int> current;

   for (int i = 1; i < 16; i++) {
      for (int j = 0; j < 16; j++) {
         if(table[j/4][j%4] == i) current = std::pair<int,int>(j/4, j%4);
      }

      int x = i - 1;
      std::pair<int, int> target = std::pair<int, int>(x/4, x%4);

      int cur_dist = 0;
      cur_dist += fabs(current.first - target.first);
      cur_dist += fabs(current.second - target.second);

      dist += cur_dist*cur_dist;
   }
   return dist;
}

void fifteen::makemove(move p) throw(illegalmove) {
  switch (p) {
    case move_left:
      if (y == 0) throw illegalmove(p);
      else {
        std::swap(table[x][y], table[x][y-1]); 
        y -= 1;
        history.push_back(p);
      }
      break;
    case move_up:
      if (x == 0) throw illegalmove(p);
      else {
        std::swap(table[x][y], table[x-1][y]);
        x -= 1;
        history.push_back(p);
      }
      break;
    case move_down:
      if (x == 3) throw illegalmove(p);
      else {
        std::swap(table[x][y], table[x+1][y]);
        x += 1;
        history.push_back(p);
      }
      break;
    case move_right:
      if (y == 3) throw illegalmove(p);
      else {
        std::swap(table[x][y], table[x][y+1]);
        y += 1;
        history.push_back(p);
      }
      break;
  }
}

bool fifteen::issolved() const { return distance() == 0; }

bool fifteen_cmp::operator() (const fifteen &f1, const fifteen &f2)
{
  for (uint i = 0; i < 16; i++) {
      if (f1.table[i/4][i%4] < f2.table[i/4][i%4]) return false;
      if (f1.table[i/4][i%4] > f2.table[i/4][i%4]) return true;
  }
  return false; 
}

std::ostream& operator << ( std::ostream& stream, const fifteen& f ) {
  stream << "State: " << std::endl;
  for( uint i = 0; i < 4; ++i ) {
    for( uint j = 0; j < 4; ++j ) {
      stream << f.table[i][j] << " ";
    }
    stream << std::endl;
  }
  stream << "Steps: " << f.history.size() << std::endl;
  for( std::vector<move>::const_iterator x = f.history.begin(); x != f.history.end(); ++x ) {
    stream << *x << std::endl;
  }
  stream << std::endl;
  return stream;
}