#ifndef TREENODE_CPP
#define TREENODE_CPP

#include <iostream>
#include <cstddef>
#include "TreeNode.h"

namespace cs20 {

template <class Object>
TreeNode<Object>::TreeNode( const Object& theElement,
						    TreeNode<Object> * theFirstChild,
							TreeNode<Object> * theNextSibling ) {
	element = theElement;
	firstChild = theFirstChild;
	nextSibling = theNextSibling;
}

template <class Object>
int TreeNode<Object>::size( TreeNode<Object> * node ) {
	if (node == NULL ) 
		return( 0 );
	else
		return( 1 + size( node->firstChild ) + size( node->nextSibling ) );
}

template <class Object>
int TreeNode<Object>::height( TreeNode<Object> * node ) {
	if (node == NULL ) 
		return( -1 );
	else
		return( max( height( node->firstChild ) + 1, height( node->nextSibling ) ) );
}

template <class Object>
TreeNode<Object> * TreeNode<Object>::duplicate( ) const {
	TreeNode<Object> * newNode = new TreeNode<Object>( element );
	if (firstChild != NULL) {
		newNode->firstChild = firstChild->duplicate();
	}
	if (nextSibling != NULL) {
		newNode->nextSibling = nextSibling->duplicate();
	}
	return( newNode );
}

template <class Object>
void TreeNode<Object>::printTreeNode( std::ostream & outs ) const {
	Object o = element;
	outs << o << " ";
	if (firstChild != NULL) 
		firstChild->printTreeNode( outs );
	else
		outs << "FCNULL ";
	if (nextSibling != NULL)
		nextSibling->printTreeNode( outs );
	else
		outs << "NSNULL ";
	outs << endl;
}

template <class Object>
const Object& TreeNode<Object>::getElement() const {
	return( element );
}

template <class Object>
TreeNode<Object>* TreeNode<Object>::getFirstChild() const {
	return( firstChild );
}

template <class Object>
TreeNode<Object>* TreeNode<Object>::getNextSibling() const {
	return( nextSibling );
}

template <class Object>
void TreeNode<Object>::setFirstChild( TreeNode<Object>* node ) {
	firstChild = node;
}

template <class Object>
void TreeNode<Object>::setNextSibling( TreeNode<Object>* node ) {
	nextSibling = node;
}

}
#endif