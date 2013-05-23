
#include "tree.h"


int main( int argc, char* argv [ ] )
{
	 try {
	   tree t1( std::string( "x" ));
	   tree t2( std::string( "50" )); 
	   std::vector< tree > args = { t1, t2 };
	   tree t3 = tree( std::string( "+" ), std::move(args) );
	   std::cout << args. size( ) << "\n";
	   tree t4 = tree( std::string( "/" ), { t2, t3 } ); 
	   tree t5 = diff(t4, std::string( "x" ));
	   tree t6 = diff(tree(std::string("sin"), {tree(std::string("x"))}), "x");
	   tree t7 = diff(tree("e", {tree("x")}), "x");
	   tree t8 = diff(tree("abc"), "x");
	   std::cout << "differetiation" << std::endl;
	   std::cout << t4 << std::endl;
	   std::cout << t5 << std::endl;
	   std::cout << t6 << std::endl;
	   std::cout << t7 << std::endl;
	   std::cout << t8 << std::endl;
   }
   catch( std::string s )
   {
   	   std::cout << "caught " << s << "\n";
   }
}


