#include "Auto.h"
#include <iostream>
using namespace std;



int foo( int a, int b ) {
   int retval = 0;

   if (a == 1)
  	retval =  b;
   else if (b == 1)
 	retval =  a;
   else
	retval =  a + foo( a, b-1 ); 

   return( retval );
}



int main( ) {
	cout << foo( 5, 3 ) << endl;
	cout << foo( 2, 4 ) << endl;
	foo( 0, 0 );
}

int mainX( ) {
	using namespace std;
	using namespace cs20;

	int i = 1;
	cin >> i;

	cs20::Auto a;
	a.start();
	a.drive();
	a.honk();
	a.stop( );


	return( 0 );
}