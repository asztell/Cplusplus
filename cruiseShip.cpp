#include "cruiseShip.h"
#include "elevator.h"


	CruiseShip::CruiseShip() : passenger(0), floor(0), attendant(false) {}

	CruiseShip::CruiseShip( int passengerCount, int floorCount, bool attendantOn ) {
		passenger = passengerCount;
		floor = floorCount;
		attendant = attendantOn;
	}

	void CruiseShip::bringAllElevatorsToFloor1(int floorNumber) {
		floor = floorNumber;
	}

	/*std::ostream& operator<< ( std::ostream& out, const Elevator & e ) {
				//for ( int i = 0; i < r.my_NumberOfDinersSeenSoFar; i++ ) {
				std::cout << "floor number: " << e.emptyWithAttendant.getFloor() << std::endl
						<< "number of passengers: " << e.emptyWithAttendant.getPassengers() << std::endl
						<< "has attendant: " << e.emptyWithAttendant.hasAttendant() << std::endl;
		return out;	}*/
