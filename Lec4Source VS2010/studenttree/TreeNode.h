#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <cstddef>

namespace cs20 {

template <class Object>
class TreeNode {
public:
	TreeNode( const Object& theElement = Object(), 
			  TreeNode * theFirstChild = NULL, 
			  TreeNode * theNextSibling = NULL);
	TreeNode * duplicate() const;

	static int size( TreeNode * t );
	static int height( TreeNode * t );

	// no references to a TreeNode are returned
	// publicly by either Tree or TreeIterator
	// these methods are only called by Tree and
	// TreeIterator
	const Object& getElement() const;
	TreeNode* getFirstChild() const;
	TreeNode* getNextSibling() const;
	void setFirstChild( TreeNode* node );
	void setNextSibling( TreeNode* node );

	void printTreeNode( std::ostream & outs ) const;

private:
	Object element;
	TreeNode* firstChild;
	TreeNode* nextSibling;
};

}

#endif