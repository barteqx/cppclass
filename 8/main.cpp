#include "surface.h"


int main() {
   for (int i = 0; i < 1000000; i++) {
      std::vector<surface> shapes;
      shapes.push_back(surface(rectangle(10, 20, 30, 100)));
      shapes.push_back(surface(triangle(10, 20, 30, 100, 200, 300)));
      shapes.push_back(surface(circle(10, 20, 30)));
      print_statistics(shapes);
   }
}