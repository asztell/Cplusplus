#ifndef LEVELORDERITERATOR_H
#define LEVELORDERITERATOR_H
#include <iostream>
#include "Tree.h"
#include "TreeIterator.h"
#include "Queue.h"

namespace cs20 {

template <class Object>
class LevelOrderIterator : public TreeIterator<Object> {
public:
	LevelOrderIterator( const Tree<Object>& theTree );
	virtual ~LevelOrderIterator();

	void advance();
	void first();
	
protected:
	Queue<const TreeNode<Object> *> q;
};

}

#endif