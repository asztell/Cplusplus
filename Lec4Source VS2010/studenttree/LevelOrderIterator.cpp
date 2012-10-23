#ifndef LEVELORDERITERATOR_CPP
#define LEVELORDERITERATOR_CPP

#include <iostream>
#include <cstddef>
#include "TreeIterator.h"
#include "LevelOrderIterator.h"
#include "Queue.h"

namespace cs20 {

template <class Object>
LevelOrderIterator<Object>::LevelOrderIterator( const Tree<Object> & theTree ) : TreeIterator<Object>( theTree ) {
	q.enqueue( root );
}

template <class Object>
LevelOrderIterator<Object>::~LevelOrderIterator() {

}

template <class Object>
void LevelOrderIterator<Object>::first( ) {
	q.makeEmpty();
	if (root != NULL) {
		q.enqueue( root );
		advance();
	}
}


template <class Object>
void LevelOrderIterator<Object>::advance( ) {
	if (q.isEmpty()) {
		if (current == NULL) 
			throw BadIterator();
		current = NULL;
	}
	else {
		current = q.dequeue();
		if (current->getNextSibling() != NULL)
			q.enqueue( current->getNextSibling() );
		if (current->getFirstChild() != NULL) 
			q.enqueue( current->getFirstChild() );
	}
}

}

#endif