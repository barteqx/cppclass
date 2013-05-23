
#include "tree.h"


int main( int argc, char* argv [ ] )
{
   for( unsigned int i = 0; i < 1000000; ++ i ) {
	   tree t1( std::string( "a" ));
	   tree t2( std::string( "b" )); 
	   tree t3 = tree( std::string( "f" ), { t1, t2 } );
	   tree t4 = tree( std::string( "f" ), { t2, t3 } );
	   std::cout << t4 << std::endl; 
	   tree t5 = subst(t4, std::string( "a" ), t3);
	   std::cout << "substitution" << std::endl;
	   std::cout << t4 << std::endl;
	   std::cout << t5 << std::endl;
   }
}



