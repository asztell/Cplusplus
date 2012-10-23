#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

namespace cs20 {

template <class Object>
Stack<Object>::Stack() {
	topNode = NULL;
}

template <class Object>
Stack<Object>::Stack( const Stack<Object>& rhs ) {
	topNode = NULL;
	*this = rhs;
}

template <class Object>
Stack<Object>::~Stack() {
	makeEmpty();
    delete topNode;
}

template <class Object>
bool Stack<Object>::isEmpty() const {
	return( (topNode == NULL) );
}

template <class Object>
void Stack<Object>::makeEmpty() {
	while (!isEmpty()) {
		pop();
	}
}

template <class Object>
void Stack<Object>::push( const Object& data ) {
	double sqrtdata = double sqrt(data->getElement());
	int castedData = (int)sqrt(data->getElement());
	if (sqrtdata == castedData) {
		StackNode<Object>* newNode = new StackNode<Object>( data, topNode );
		topNode = newNode;
	} else {
		cout << "Sorry, buddy, square roots only!" << endl;
	}
}

template <class Object>
void Stack<Object>::pop() {
	if (isEmpty()) {
		throw EmptyStack();
	}
	StackNode<Object> *oldTop = topNode;
	topNode = topNode->getNext();
	delete oldTop;
}

template <class Object>
const Object& Stack<Object>::top( ) const {
	if (isEmpty()) {
		throw EmptyStack();
	}
	StackNode<Object> node = *topNode;
	return( node.getElement() );
}

template <class Object>
Object Stack<Object>::topAndPop( ) {
	Object o = top();
	pop();
	return( o );
}

template <class Object>
bool Stack<Object>::existsOnce( const Object& o) const {
	//while loop to look through the stack values using topNode
	int counter = 0;
	StackNode<Object>* node = topNode;
	if ( topNode == NULL ) {
		cout << "Empty Stack!" << endl;
	}
	while ( node != NULL ) {
		if ( o == node->getElement() ) {
		counter++;
		}
		node = node->getNext();
	}
	if ( counter >= 2 ) {
		return false;
	} else if ( counter == 0 ) {
		cout << "Node value doesn't exist - Try again" << endl;
		return false;
	} else {
		return true;
	}
} 

// Deep copy of linked Stack
template <class Object>
const Stack<Object>& Stack<Object>::operator =( const Stack<Object>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (!(rhs.isEmpty())) {
			StackNode<Object> * rhsTopNode = rhs.topNode;
			StackNode<Object> * myTopNode = new StackNode<Object>( rhsTopNode->getElement() );
			topNode = myTopNode;

			rhsTopNode = rhsTopNode->getNext();
			while (rhsTopNode != NULL) {
				myTopNode->setNext( new StackNode<Object>( rhsTopNode->getElement() ) );
				myTopNode = myTopNode->getNext();
				rhsTopNode = rhsTopNode->getNext();
			}
		}
	}
	return( *this );
}

template <class Object>	
std::ostream& Stack<Object>::printStack( std::ostream& outs ) const {
	if (isEmpty()) {
		outs << "Empty Stack";
	}
	else {
		outs << "TOP: ";
		StackNode<Object> * node = topNode;
		while (node != NULL) {
			outs << node->getElement();
			outs << "\n     ";           /// for visual alignment
			node = node->getNext();
		}
	}
	return( outs );
}

}

#endif