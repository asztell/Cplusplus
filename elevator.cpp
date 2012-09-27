#include "elevator.h"
using namespace std;
	Elevator::Elevator( int passengers, int floor, bool hasAttendant )
	: my_Passengers( passengers ),
	  my_HasAttendant( hasAttendant ),
	  my_Floor( floor ) { }

	int Elevator::getFloor() const {
		return( my_Floor );
	}

	int Elevator::getPassengers() const {
		return( my_Passengers );
	}

	bool Elevator::hasAttendant() const {
		return( my_HasAttendant );
	}

	void Elevator::moveToFloor( int floor ) {
		my_Floor = floor;
	}

	void Elevator::addPassengers( int p ) {
		my_Passengers += p;
	}

	void Elevator::letOffPassengers(int p) {
		my_Passengers -= p;
	}

	/*std::ostream& operator<< ( std::ostream& out, const Elevator & e ) {
			//for ( int i = 0; i < r.my_NumberOfDinersSeenSoFar; i++ ) {
		std::cout << "floor number: " << e.getFloor() << std::endl
				<< "number of passengers: " << e.getPassengers() << std::endl
				<< "has attendant: " << e.hasAttendant() << std::endl;
		return out;
	}*/
