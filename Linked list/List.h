#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "ListNode.h"
#include "ListIterator.h"

namespace cs20 {

template <class Object>
class List {
public:
	List();
	List( const List& rhs );
	~List();

	bool isEmpty() const;
	void makeEmpty();
	ListIterator<Object> zeroth() const;
	ListIterator<Object> first() const;
	void insert( const Object& data,
				 const ListIterator<Object> &iter );
	void insert( const Object& data );
	ListIterator<Object> findPrevious( const Object& data ) const;
	void insert_back( const Object& data );
	void remove( const Object& data );
	bool List<Object>::isInDecreasingOrder() const;
	const List& operator =( const List& rhs );
private:
	ListNode<Object> * head;
	ListNode<Object> * tail;
	
};

}
#endif