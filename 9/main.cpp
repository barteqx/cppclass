#include "fifteen.h"

int main(int argc, char* argv []) {
   fifteen input, solved;

   unsigned int tab[4][4];

   for (int i = 0; i < 16; i++) std::cin >> tab[i/4][i%4];

   input = fifteen(tab);
   solved = solve(input);

   std::cout << solved << std::endl << solved.distance();

   return 0; 
}
