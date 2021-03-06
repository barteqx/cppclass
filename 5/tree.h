
#ifndef TREE_INCLUDED
#define TREE_INCLUDED  1


#include <iostream>
#include <vector>
#include <string>
#include <sstream>


class tree;

// struct trnode should be invisible to the user of tree. This can be 
// obtained by making it a private number of tree. 
// In this exercise, we leave it like this, because it is simpler.
// In real code, trnode should be defined inside tree.


struct trnode 
{
   std::string f;
   std::vector< tree > subtrees;
   
   unsigned int refcnt;
      // The reference counter: Counts how often this trnode is referred to.

   trnode( const std::string& f, const std::vector< tree > & subtrees, 
           unsigned int refcnt )
      : f(f),
        subtrees( subtrees ),
        refcnt( refcnt )
   { }

   trnode( const std::string& f, std::vector< tree > && subtrees,
           unsigned int refcnt )
      : f(f),
        subtrees( std::move( subtrees )), 
        refcnt( refcnt )
   { }
      // The double && is an R-value reference. This is a reference
      // to an object, that nobody cares about anymore, and that
      // is about to be destroyed. In this way, it can be avoided that 
      // elements in the vector are copied, when it is possible to simply
      // pass the link. See: 
      // http://thbecker.net/articles/rvalue_references/section_01.html
};


class tree;
std::ostream& operator << ( std::ostream&, const tree& );

class tree
{
   trnode* pntr;

public: 
   tree( const std::string& f ) 
      : pntr( new trnode( f, { }, 1 ))
   { }

   tree( const std::string& f, const std::vector< tree > & subtrees )   
      : pntr( new trnode( f, subtrees, 1 ))
   { std::cout << "Not R-value" << *this; } 
 
   tree( const std::string& f, std::vector< tree > && subtrees )
      : pntr( new trnode( f, std::move( subtrees ), 1 ))
   { std::cout << "R-value" << *this; } 

   tree( unsigned int i );
  
   tree( const tree& t );
   void operator = ( const tree& t );
 
   const std::string& functor() const;
   std::string& functor();

   const tree& operator [ ] ( unsigned int i ) const;
   tree& operator [ ] ( unsigned int i );
   
   unsigned int nrsubtrees() const;

   ~tree( );

   void print( std::ostream& stream, unsigned int indent = 0 ) const;

   unsigned int getunsigned( ) const;

   bool isunsigned( ) const;

private:  
   // Delete public, when the thing is tested:

   void ensure_not_shared( ); 

};

std::ostream& operator << ( std::ostream& stream, const tree& t );
   // Doesn't need to be friend, because it uses only functor( ) and
   // [ ].

std::string& print_tree (const tree& t, const std::string prefix);

tree subst(const tree& t, const std::string& val, const tree& var);

tree diff(const tree& t, const std::string& var);

#endif

