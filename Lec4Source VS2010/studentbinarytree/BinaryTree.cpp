#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "BinaryTree.h"

namespace cs20 {

template <class Object>
BinaryTree<Object>::BinaryTree() {
	root = NULL;
}

template <class Object>
BinaryTreeNode<Object> * BinaryTree<Object>::getRoot() const {
	return( root );
}

template <class Object>
BinaryTree<Object>::BinaryTree( const BinaryTree<Object>& rhs ) {
	root = NULL;
	*this = rhs;
}

template <class Object>
BinaryTree<Object>::BinaryTree( const Object& rootElement ) {
	root = new BinaryTreeNode<Object>( rootElement );
}

template <class Object>
BinaryTree<Object>::~BinaryTree() {
	makeEmpty();
}

template <class Object>
bool BinaryTree<Object>::isEmpty() const {
	return( root == NULL );
}

template <class Object>
void BinaryTree<Object>::makeEmpty() {
	makeEmpty( root );
}

template <class Object>
void BinaryTree<Object>::makeEmpty( NodePtr & node ) {
	if (node != NULL) {
		NodePtr r = node->getRightSide();
		NodePtr l = node->getLeftSide();

		if (r != NULL)
			makeEmpty( r );
		if (l != NULL)
			makeEmpty( l );
		delete node;
		node = NULL;
	}
}

template <class Object>
int BinaryTree<Object>::size() const {
	return( BinaryTreeNode<Object>::size( root ) );
}

template <class Object>
int BinaryTree<Object>::height() const {
	return( BinaryTreeNode<Object>::height( root ) );
}

template <class Object>
void BinaryTree<Object>::setRightSide( BinaryTree& theRightSide ) {
	if (theRightSide.root == NULL)
		throw( InvalidTreeArgument() );
	BinaryTreeNode<Object> *child = new BinaryTreeNode<Object>( theRightSide.root->getElement(), 
																theRightSide.root->getLeftSide(),
																theRightSide.root->getRightSide() );
	root->setRightSide( child );
	if (child != theRightSide.root)
		theRightSide.root = NULL;
}

template <class Object>
void BinaryTree<Object>::setLeftSide( BinaryTree& theLeftSide ) {
	if (theLeftSide.root == NULL) 
		throw( InvalidTreeArgument() );
	BinaryTreeNode<Object> *child = new BinaryTreeNode<Object>( theLeftSide.root->getElement(), 
																theLeftSide.root->getLeftSide(),
																theLeftSide.root->getRightSide() );
	root->setLeftSide( child );
	if (child != theLeftSide.root)
		theLeftSide.root = NULL;
}

template <class Object>
void BinaryTree<Object>::merge( const Object& rootElement,
 								BinaryTree & left,
								BinaryTree & right ) {
	if ( left.root == right.root && left.root != NULL ) {
		cerr << "Cannot merge a tree with itself" << endl;
		throw( InvalidTreeArgument() );
	}
	else {
		NodePtr oldRoot = root;
		root = new BinaryTreeNode<Object>( rootElement, 
							 			   left.root,
										   right.root );
		if (this != &left && this != &right) 
			makeEmpty( oldRoot );
		if (this != &left) 
			left.root = NULL;
		if (this != &right)
			right.root = NULL;
	}
}

// Deep copy of tree
template <class Object>
const BinaryTree<Object>& BinaryTree<Object>::operator =( const BinaryTree<Object>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (rhs.root != NULL) 
			root = rhs.root->duplicate();
	}
	return( *this );
}

template <class Object>
void BinaryTree<Object>::printTree( std::ostream& out ) const {
	if (root == NULL) {
		out << "NULL" << std::endl;
	}
	else {
		printTree( root, out );
		out << std::endl;
	}
}

template <class Object>
void BinaryTree<Object>::printTree( NodePtr subtree, std::ostream & out ) const {
	if (subtree == NULL) {
		out << "NULL";
	}
	else {
		out << subtree->getElement();
		out << " ";
		printTree( subtree->getLeftSide(), out );
		out << " ";
		printTree( subtree->getRightSide(), out );
		out << " ";
	}
}

}
#endif