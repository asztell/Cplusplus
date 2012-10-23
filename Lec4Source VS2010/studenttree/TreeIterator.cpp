#ifndef TREEITERATOR_CPP
#define TREEITERATOR_CPP

#include <iostream>
#include <cstddef>
#include "TreeIterator.h"

namespace cs20 {

template <class Object>
TreeIterator<Object>::TreeIterator( const Tree<Object> & theTree ) : root( theTree.root ) , current( NULL ) {
//	all assignments performed above
}

template <class Object>
TreeIterator<Object>::~TreeIterator() {

}

template <class Object>
bool TreeIterator<Object>::isValid( ) const {
	return( (current != NULL) );
}


template <class Object>
const Object& TreeIterator<Object>::retrieve( ) const {
	if (!(isValid())) throw BadIterator();
	return( current->getElement() );
}

}

#endif