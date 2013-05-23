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

