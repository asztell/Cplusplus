#ifndef TREE_CPP 
#define TREE_CPP

#include <iostream>
#include <cstddef>
#include "Tree.h"
#include "TreeNode.h"
#include "InvalidTreeArgument.h"

namespace cs20 {

template <class Object>
Tree<Object>::Tree() {
	root = NULL;
}

template <class Object>
Tree<Object>::Tree( const Tree<Object>& rhs ) {
	root = NULL;
	*this = rhs;
}

template <class Object>
Tree<Object>::Tree( const Object& rootElement ) {
	root = new TreeNode<Object>( rootElement );
}

template <class Object>
Tree<Object>::~Tree() {
	makeEmpty();
}

template <class Object>
const Object & Tree<Object>::getElement() const {
	return( root->getElement() );
}

template <class Object>
bool Tree<Object>::isEmpty() const {
	return( root == NULL );
}

template <class Object>
void Tree<Object>::makeEmpty() {
	makeEmpty( root );
}

template <class Object>
TreeNode<Object> * Tree<Object>::getFirstChild( ) const {
	return( root->getFirstChild() );
}

template <class Object>
TreeNode<Object> * Tree<Object>::getNextSibling( ) const {
	return( root->getNextSibling() );
}

template <class Object>
TreeNode<Object> * Tree<Object>::getRoot( ) const {
	return( root );
}

template <class Object>
void Tree<Object>::makeEmpty( NodePtr & node ) {
	if (node != NULL) {
		NodePtr fc = node->getFirstChild();
		NodePtr ns = node->getNextSibling();

		if (fc != NULL)
			makeEmpty( fc );
		if (ns != NULL)
			makeEmpty( ns );
		delete node;
		node = NULL;
	}
}

template <class Object>
int Tree<Object>::size() const {
	return( TreeNode<Object>::size( root ) );
}

template <class Object>
int Tree<Object>::height() const {
	return( TreeNode<Object>::height( root ) );
}

template <class Object>
void Tree<Object>::setFirstChild( Tree& theFirstChild ) {
	if (theFirstChild.root == NULL)
		throw( InvalidTreeArgument() );
	TreeNode<Object> *child = new TreeNode<Object>( theFirstChild.root->getElement(), 
													theFirstChild.root->getFirstChild(),
													theFirstChild.root->getNextSibling() );
	root->setFirstChild( child );
	if (child != theFirstChild.root)
		theFirstChild.root = NULL;
}

template <class Object>
void Tree<Object>::setNextSibling( Tree& theNextSibling ) {
	if (theNextSibling.root == NULL) 
		throw( InvalidTreeArgument() );
	TreeNode<Object> *child = new TreeNode<Object>( theNextSibling.root->getElement(), 
													theNextSibling.root->getFirstChild(),
													theNextSibling.root->getNextSibling() );

	root->setNextSibling( child );
	if (child != theNextSibling.root)
		theNextSibling.root = NULL;
}

template <class Object>
void Tree<Object>::merge( const Object& rootElement,
 						  Tree & firstChild,
						  Tree & nextSibling ) {
	if ( firstChild.root == nextSibling.root && firstChild.root != NULL ) {
		cerr << "Cannot merge a tree with itself" << endl;
		throw( InvalidTreeArgument() );
	}
	else {
		NodePtr oldRoot = root;
		root = new TreeNode<Object>( rootElement, 
									 firstChild.root,
									 nextSibling.root );
		if (this != &firstChild && this != &nextSibling) 
			makeEmpty( oldRoot );
		if (this != &firstChild) 
			firstChild.root = NULL;
		if (this != &nextSibling)
			nextSibling.root = NULL;
	}
}

// Deep copy of tree
template <class Object>
const Tree<Object>& Tree<Object>::operator =( const Tree<Object>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (rhs.root != NULL) 
			root = rhs.root->duplicate();
	}
	return( *this );
}

template <class Object>	
const Object& Tree<Object>::find( const Object& item ) const throw (ValueNotFound) {
	TreeNode<Object>* node = find( item, root );
	if (node == NULL)
		throw( ValueNotFound() );
	return( node->getElement() );
}

template <class Object>	
TreeNode<Object>* Tree<Object>::find( const Object& item, TreeNode<Object>* node ) const {
	TreeNode<Object>* match = NULL;
	if (node != NULL && node->getElement() == item) {
		match = node;
	}
	if (node != NULL && match == NULL && node->getFirstChild() != NULL) {
		match = find( item, node->getFirstChild() );
	}
	if (node != NULL && match == NULL && node->getNextSibling() != NULL) {
		match = find( item, node->getNextSibling() );
	}
	return( match );
}

template <class Object>
void Tree<Object>::printTree( std::ostream & outs ) const {
	if (isEmpty())
		outs << "Empty Tree";
	else {
		TreeNode<Object> * node = getRoot();
		node->printTreeNode( outs );
	}
	outs << std::endl;
}

}

#endif
