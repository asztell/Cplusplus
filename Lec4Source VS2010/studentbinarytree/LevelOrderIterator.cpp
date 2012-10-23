#ifndef LEVELORDERITERATOR_CPP
#define LEVELORDERITERATOR_CPP

#include "LevelOrderIterator.h"

namespace cs20 {

template <class Object>
LevelOrderIterator<Object>::LevelOrderIterator( const BinaryTree<Object> & theTree ) : BinaryTreeIterator<Object>( theTree ) {
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
		//if (current->leftSide != NULL)
		//	q.enqueue( current->leftSide );
		//if (current->rightSide != NULL) 
		//	q.enqueue( current->rightSide );
		if (current->getLeftSide() != NULL)
			q.enqueue( current->getLeftSide() );
		if (current->getRightSide() != NULL) 
			q.enqueue( current->getRightSide() );
	}
}

}

#endif