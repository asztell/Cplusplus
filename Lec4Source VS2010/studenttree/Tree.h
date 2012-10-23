#ifndef TREE_H
#define TREE_H
// Visual Studio .NET does not support declared exceptions...
#pragma warning( disable:4290 )
#include <iostream>
#include "TreeNode.h"
#include "ValueNotFound.h"

namespace cs20 {

template <class Object>
class TreeIterator;

template <class Object>
class Tree {
public:
	Tree();
	Tree( const Object& rootElement );
	Tree( const Tree& rhs );
	~Tree();

	bool isEmpty() const;
	void makeEmpty();
	int size() const;
	int height() const;
	void merge( const Object& rootElement,
				Tree& firstChild,
				Tree& nextSibling );
	void setFirstChild( Tree& theFirstChild );
	TreeNode<Object> * getFirstChild( ) const;
	void setNextSibling( Tree& theNextSibling ); 
	TreeNode<Object> * getNextSibling( ) const;
	const Object& find( const Object& item ) const throw (ValueNotFound);
	
	const Tree& operator =( const Tree& rhs );
	void printTree( std::ostream & outs ) const;

	const Object & getElement() const;
	TreeNode<Object> * getRoot( ) const;
private: 
	typedef TreeNode<Object>* NodePtr;
	
	NodePtr root;
	void makeEmpty( NodePtr &t );
	TreeNode<Object>* find( const Object& item, TreeNode<Object>* node ) const;
	friend class TreeIterator<Object>;

};

}

#endif
