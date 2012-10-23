#include <iostream>
#include "Stack.h"
#include "EmptyStack.h"
#include "StackNode.h"
#include "Stack.cpp"
#include "StackNode.cpp"

using namespace std;
using namespace cs20;

enum CHOICE {MAKEEMPTY, PUSHSQ, ISEMPTY, EXISTSONCE, POP, TOP, TOPANDPOP, QUIT, PRINT };

CHOICE menu();

int main(int argc, char* argv[]) {
	int value;
	Stack<int> stack;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			stack.makeEmpty();
			break;
		case ISEMPTY:
			if (stack.isEmpty()) {
				cout << "stack is empty" << endl;
			}
			else {
				cout << "stack is not empty" << endl;
			}
			break;
		case EXISTSONCE:
			cin >> value;
			if (stack.existsOnce( value )) {
				cout << "node exists once" << endl;
			}
			else {
				cout << "node exists MORE than once!" << endl;
			}
			break;
		case TOP:
			try {
				value = stack.top();
				cout << "Here's the value on top: ";
				cout << value << endl;
			} catch( EmptyStack es ) {
				cout << "You silly... don't try topping an empty stack!" << endl;			
			}
			break;
		case POP:
			try {
				stack.pop();
			} catch( EmptyStack es ) {
				cout << "You silly... don't try popping an empty stack!" << endl;
			}
			break;
		case PUSHSQ:
			cout << "Please provide perfect square int to push: ";
			cin  >> value; 
			stack.push( value );
			break;
		case TOPANDPOP:
			try {
				value = stack.topAndPop();
				cout << "Here's the value on top that got popped: ";
				cout << value << endl;
			} catch( EmptyStack es ) {
				cout << "You silly... don't try topAndPopping an empty stack!" << endl;
			}
			break;
		case PRINT:
			stack.printStack( cout );
			cout << endl;
			break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty (E)xistsOnce p(U)shSQ p(O)p (T)op top(A)ndpop (P)rint (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'A':
	case 'a':
		result = TOPANDPOP;
		break;
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'E':
	case 'e':
		result = EXISTSONCE;
		break;
	case 'U':
	case 'u':
		result = PUSHSQ;
		break;
	case 'O':
	case 'o':
		result = POP;
		break;
	case 'T':
	case 't':
		result = TOP;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	}

	return( result );
}

void sample() {
	Stack<int> s1;
	Stack<int> s2;
	cout << "making s1" << endl;
	s1.push( 1 );
	s1.push( 2 );
	cout << "print s1" << endl;
	s1.printStack( cout );
	cout << endl;

	cout << "s2 = s1" << endl;

	s2 = s1;
	cout << "print s2" << endl;
	s2.printStack( cout );
	cout << endl;

	s1.pop();
	cout << "pop s1" << endl;

	cout << "print s2" << endl;
	s2.printStack( cout );
	cout << endl;

	cout << "print s1" << endl;
	s1.printStack( cout );
	cout << endl;

}
