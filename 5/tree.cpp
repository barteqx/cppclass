#include "tree.h"

tree::tree(const tree& t) :
	pntr(t.pntr)
{
	pntr -> refcnt++;
}

tree::~tree() {
	pntr -> refcnt--;
	if (pntr -> refcnt == 0) delete pntr;
}

tree::tree( unsigned int i )
	: pntr(0)
{
	// This is a rare case where immediate initialization is not possible.
	std::ostringstream s;
	s << i;
	pntr = new trnode( s.str( ), { }, 1 );
}


void tree::operator = (const tree& t) {
	t.pntr -> refcnt++;
	pntr -> refcnt--;
	if (pntr -> refcnt == 0) delete pntr;
	pntr = t.pntr;
}

const std::string& tree::functor() const {
	return pntr -> f;
}

std::string& tree::functor() {
	ensure_not_shared();
	return pntr -> f;
}

const tree& tree::operator [] (unsigned int i) const  {
	return pntr -> subtrees[i];
}

tree& tree::operator [] (unsigned int i) {
	ensure_not_shared();
	return pntr -> subtrees[i];
}

void tree::ensure_not_shared() {
	if (pntr -> refcnt != 1) {
		pntr -> refcnt--;
		pntr = new trnode(pntr -> f, pntr -> subtrees, 1);
	}
}

unsigned int tree::nrsubtrees () const {
	return pntr -> subtrees.size();
}

std::ostream& operator << (std::ostream& stream, const tree& t) {
	t.print(stream);
	return stream;
}

void tree::print( std::ostream& stream, unsigned int indent) const {
	for( unsigned int i = 0; i < indent; ++ i )
		stream << "   ";

  stream << functor( ) << std::endl;
  for( unsigned int i = 0; i < nrsubtrees( ); ++ i )
  	(*this)[i]. print( stream, indent + 1 );
}

tree subst(const tree& t, const std::string& val, const tree& var) {
	tree new_tree = t;
	if (new_tree.functor() == val && t.nrsubtrees() == 0) new_tree = var;
	else { 
		for( unsigned int i = 0; i < t.nrsubtrees( ); ++ i ) {
			new_tree[i] = subst(t[i], val, var);
		}
	}
	return new_tree;
}

bool tree::isunsigned( ) const
{
	// Numbers don’t have subtrees:
	if( pntr -> subtrees.size( ) != 0 )
		return false;
	const std::string& s = pntr -> f;
	for( auto p = s.begin( ); p != s.end( ); ++ p )
	{
		if( *p < '0' || *p > '9' ) return false;
	}
	return true;
}

unsigned int tree::getunsigned( ) const
{
	// We make a stringstream from the string, and
	// read the unsigned from it.
	std::istringstream s(pntr -> f);
	unsigned int res = 0;
	s >> res;
	return res;
	}


tree diff(const tree& t, const std::string& var) {
	if (t.isunsigned()) return tree(0);

	 if (t.functor() == var) return tree(1);

	 if (t.functor() == "+" && t.nrsubtrees() == 2)
		return tree(t.functor(), {diff(t[0], var), diff(t[1], var)});

	 if (t.functor() == "-" && t.nrsubtrees() == 2) 
		return tree(t.functor(), {diff(t[0], var), diff(t[1], var)});

	 if (t.functor() == "*" && t.nrsubtrees() == 2) {
		tree left = tree("*", {diff(t[0], var), t[1]});
		tree right = tree("*", {diff(t[1], var), t[0]});
		return tree("+", {left, right});
	}

	 if (t.functor() == "/" && t.nrsubtrees() == 2) {
		tree mleft = tree("*", {diff(t[0], var), t[1]});
		tree mright = tree("*", {diff(t[1], var), t[0]});
		tree left = tree("-", {mleft, mright});
		tree right = tree("*", {t[1], t[1]});
		return tree("/", {left, right});
	}

	 if (t.functor() == "sin" && t. nrsubtrees() == 1)
    return tree( std::string( "*"), { tree(std::string("cos"), { t[0] }), diff(t[0], var) });

   if (t.functor() == "cos" && t. nrsubtrees() == 1)
    return tree( std::string("-"), { std::string("sin"), diff(t[0], var) });

	 if (t.functor() == "e" && t. nrsubtrees( ) == 1 && 
	 	   t[0]. functor( ) == "x" && t[0]. nrsubtrees( ) == 0 )
		return t;

   std::ostringstream err;
   err << "could not differentiate " << t;
	 throw err. str( );

}
