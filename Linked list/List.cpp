#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

namespace cs20 {
template <class Object>
List<Object>::List() {
	head = new ListNode<Object>;
	tail = new ListNode<Object>;
}

template <class Object>
List<Object>::List( const List<Object>& rhs ) {
	head = new ListNode<Object>;
	tail = new ListNode<Object>;
	*this = rhs;
}

template <class Object>
List<Object>::~List() {
	makeEmpty();
    delete head;
}

template <class Object>
bool List<Object>::isEmpty() const {
	return( head->nextIsNull() );
}

template <class Object>
void List<Object>::makeEmpty() {
	while (!isEmpty()) {
		remove( first().retrieve() );
	}
}

template <class Object>
ListIterator<Object> List<Object>::zeroth() const {
	return( ListIterator<Object>( head ) );
}

template <class Object>
ListIterator<Object> List<Object>::first() const {
    return( ListIterator<Object>( head->getNext() ) );
}

template <class Object>
void List<Object>::insert( const Object& data,
 						   const ListIterator<Object> &iter ) {
	if (iter.isValid()) {
		ListNode<Object>* newnode = new ListNode<Object>( data, iter.current->getNext() );
		iter.current->setNext( newnode );
	}
}

template <class Object>
void List<Object>::insert( const Object& data ) {
	// insert after the header node
	ListNode<Object>* newnode = new ListNode<Object>( data, head->getNext() );
	if ( isEmpty() ) {
		head->setNext( newnode );
		tail = newnode;
	} else {
		head->setNext( newnode );
	}
}

template <class Object>
void List<Object>::insert_back( const Object& data ) {
	ListNode<Object>* newnode = new ListNode<Object>( data, tail->getNext() );
	if ( isEmpty() ) {
		head->setNext( newnode );
		tail = newnode;
	} else {
		tail->setNext( newnode );
		tail = newnode;
	}
}

template <class Object>
ListIterator<Object> List<Object>::findPrevious( const Object& data ) const {
	ListNode<Object>* node = head;
	while( node->getNext() != NULL && node->getNext()->getElement() != data ) {
		node = node->getNext();
	}
	if (node->getNext() == NULL) {
		node = NULL;
	}
	return ListIterator<Object>( node );
}

template <class Object>
void List<Object>::remove( const Object& data ) {
	ListNode<Object>* frontFinger, * backFinger;
	backFinger = head;
	frontFinger = head->getNext();

	while ( frontFinger != NULL ) {
		if ( data == frontFinger->getElement() ) {
			if (frontFinger == tail ) {
				backFinger->setNext( NULL );
				tail = backFinger;
				delete frontFinger;
				frontFinger = NULL;
			} else {
				backFinger->setNext( frontFinger->getNext() );
				delete frontFinger;
				frontFinger = NULL;
			}
		} else {
			backFinger = frontFinger;
			frontFinger = frontFinger->getNext();
		}
	}
}

template <class Object>
bool List<Object>::isInDecreasingOrder() const {
	//use remove
	ListNode<Object> * frontFinger, * backFinger;
	bool listIsDecreasing = false;
	backFinger = head->getNext();
	frontFinger = backFinger->getNext();
	for ( ; frontFinger != tail ; frontFinger = backFinger->getNext() ) {
		if( backFinger->getElement() < frontFinger->getElement() ) {
			//we know that list is increasing on this iteration,
			//therefore there's no way that the list can ever be decreasing
			//=> we can exit the loop, we're done.
			listIsDecreasing = false;
			break;
		} else if ( backFinger->getElement() == frontFinger->getElement() ) {
			//curr. node equals next node, it's still possible that the list
			//can be decreasing, therefore we have to continue checking
			backFinger = frontFinger;
			continue;
		} else { //backFinger is greater than frontFinger
			//the list looks like it's decreasing, so we set the listIsDecreasing flag
			//to true, however it's still possible for one of the future nodes
			//to be greater, so we must continue checking until the end.
			listIsDecreasing = true;
			backFinger = frontFinger;
			continue;
		}		
	}

	if( backFinger == NULL ) {
		listIsDecreasing = false;
	}
	return ( listIsDecreasing );
}
// Deep copy of linked list
template <class Object>
const List<Object>& List<Object>::operator =( const List<Object>& rhs ) {
	if ( this != &rhs ) {
		makeEmpty();
		
		ListIterator<Object> rightiter = rhs.first( );
		ListIterator<Object> myiterator = zeroth();
		while( rightiter.isValid() ) {
			insert( rightiter.retrieve(), myiterator );
			rightiter.advance();
			myiterator.advance();
		}
	}
	return( *this );
}

}

#endif