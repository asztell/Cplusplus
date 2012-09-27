#include <iostream>
#include "Auto.h"
using namespace std;

namespace cs20 {

Auto::Auto( ) {

}

Auto::Auto( string make, string model, string color ) {

}


/// verbs that every auto knows how to perform .... actions
void Auto::drive() {
	cout << "drive!" << endl;
}

void Auto::honk() {
	cout << "honk!" << endl;		
}
	
void Auto::start() {
	cout << "start!" << endl;
}


void Auto::stop() {
	cout << "stop!" << endl;
}



}