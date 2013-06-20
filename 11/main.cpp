#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>

#include "grid.h"

int main (int argc, char const* argv[])
{
   int gridSizeX = 500;
   int gridSizeY = 500;
   std::default_random_engine generator;
   std::uniform_int_distribution<int> distribution(0,1);
   int dice_roll = distribution(generator);

   grid life(gridSizeX, gridSizeY);

   life.clear();

   for (int i = 0; i < gridSizeX; i++) {
    for (int j = 0; j < gridSizeY; j++) {
      bool dice_roll = distribution(generator);
      life.add(i, j, {{dice_roll}});
    }
   }
   sf::Window window( sf::VideoMode(800, 600), "Game of Life" );
   window.setVerticalSyncEnabled(true);

   glClearColor( 0, 0, 0, 1.0 );
   glClearDepth( 1.0 );
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity( );
   glScalef( 1.0 / (gridSizeX/2), 1.0 / (gridSizeY/2), 1.0 );

   bool running = true;
    int frames = 0;
    while (running) {

      sf::Event event;
      while (window.pollEvent(event)) {
         if (event.type == sf::Event::Closed) running = false;
         else if (event.type == sf::Event::Resized) {
            glViewport(0, 0, event.size.width, event.size.height);
         }
      }

      if (frames >= 5) {
         frames = 0;
         life.nextgeneration();
      }
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      life.plot();
      frames++;
      window.display();
      // system("clear");
      // std::cout << life;
    }
   return 0;
}