// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "BadIterator.h"
#include "InvalidTreeArgument.h"
#include "LevelOrderIterator.h"
#include "LevelOrderIterator.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "QueueNode.h"
#include "QueueNode.cpp"
#include "Tree.h"
#include "Tree.cpp"
#include "TreeIterator.h"
#include "TreeIterator.cpp"
#include "TreeNode.h"
#include "TreeNode.cpp"

using namespace std;
using namespace cs20;

enum CHOICE {MAKEEMPTY, ISEMPTY, SIZE, HEIGHT, QUIT, PRINT, PRINTNODE, LEVELORDER, SETROOT, SETFIRST, SETNEXT, GOTOROOT, GOFIRST, GONEXT };

CHOICE menu();
void printTree( const Tree<int>& t );

int main(int argc, char* argv[]) {
	int value;
	Tree<int> tree;
	TreeNode<int> * node = NULL;
	TreeNode<int> * firstnode = NULL;
	TreeNode<int> * nextnode = NULL;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			tree.makeEmpty();
			node = NULL;
			break;
		case ISEMPTY:
			if (tree.isEmpty()) {
				cout << "tree is empty" << endl;
			}
			else {
			cout << "tree is not empty" << endl;
			}
			break;
		case SIZE:
			if (node == NULL) {
				cout << "You silly... the current node is NULL!" << endl;
			}
			else {
				cout << "size of current node=" << TreeNode<int>::size( node ) << endl;
			}
			break;
		case HEIGHT:
			if (node == NULL) {
				cout << "You silly... the current node is NULL!" << endl;
			}
			else {
				cout << "height of current node=" << TreeNode<int>::height( node ) << endl;
			}
			break;
		case PRINT:
			printTree( tree );
			break;
		case PRINTNODE:
			if (node == NULL) {
				cout << "You silly... the current node is NULL!" << endl;
			}
			else {
				value = node->getElement();
				cout << "value of current node=" << value << endl;
			}
			break;
		case SETFIRST:
			try {
				cout << "Enter a value for node's firstchild: ";
				cin  >> value;
				firstnode = new TreeNode<int>( value );
				node->setFirstChild( firstnode );
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case SETNEXT:
			try {
				cout << "Enter a value for node's nextsibling: ";
				cin  >> value;
				nextnode = new TreeNode<int>( value );
				node->setNextSibling( nextnode );
			} catch( InvalidTreeArgument ita ) {
				cout << "InvalidTreeArgument caught!" << endl;
			}
			break;
		case SETROOT:
			cout << "Enter root value: ";
			cin  >> value;
			// not sure this is too clever...
			tree = Tree<int>( value );
			node = tree.getRoot();
			break;
		case LEVELORDER:
			try {
				LevelOrderIterator<int> iter( tree );
				iter.first();
				while( iter.isValid() ) {
					value = iter.retrieve();
					cout << value << " ";
					iter.advance();
				}
				cout << endl;
			}
			catch( BadIterator bi ) {
				cout << "badIterator exception caught!" << endl;
			}
			break;
		case GOTOROOT:
			node = tree.getRoot();			
			break;
		case GOFIRST:
			node = node->getFirstChild();
			break;
		case GONEXT:
			node = node->getNextSibling();
			break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

void printTree( const Tree<int> & t ) {
	t.printTree( cout );
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty (I)sEmpty (S)ize (H)eight setRoo(T) set(F)irstChild set(N)extSibling gotoroot(1) gofi(R)st gone(X)tsibling (P)rint printN(O)de le(V)elOrder (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = SIZE;
		break;
	case 'I':
	case 'i':
		result = ISEMPTY;
		break;
	case 'H':
	case 'h':
		result = HEIGHT;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	case 'O':
	case 'o':
		result = PRINTNODE;
		break;
	case 'T':
	case 't':
		result = SETROOT;
		break;
	case 'V':
	case 'v':
		result = LEVELORDER;
		break;
	case 'F':
	case 'f':
		result = SETFIRST;
		break;
	case 'N':
	case 'n':
		result = SETNEXT;
		break;
	case 'R':
	case 'r':
		result = GOFIRST;
		break;
	case 'X':
	case 'x':
		result = GONEXT;
		break;
	case '1':
		result = GOTOROOT;
		break;
	}

	return( result );
}
