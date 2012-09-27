#include "elevator.h"
#include "cruiseShip.h"
#include <iostream>
#include <stdio.h>





int main() {
	using namespace std;
	Elevator emptyWithAttendant();
	// an elevator with no passengers on floor 1
	cout << emptyWithAttendant;
	Elevator onFloorSeven();
	onFloorSeven( 1, 7, false );
	// an elevator with 1 passenger on floor 7
	cout << onFloorSeven;
	getchar();
	return 0;
}
