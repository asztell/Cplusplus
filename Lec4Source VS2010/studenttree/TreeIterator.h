#ifndef TREEITERATOR_H
#define TREEITERATOR_H
#include <iostream>
#include "TreeNode.h"
#include "Tree.h"
#include "BadIterator.h"

namespace cs20 {

template <class Object>
class TreeIterator {
public:
	TreeIterator( const Tree<Object>& theTree );
	virtual ~TreeIterator();

	bool isValid() const;
	virtual void advance() = 0;
	virtual void first() = 0;
	const Object& retrieve() const;
	
protected:
	const TreeNode<Object> * current;
	const TreeNode<Object> * root;

};

}
#endif