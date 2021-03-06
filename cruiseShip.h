#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "elevator.h"

class CruiseShip
{
public:
	CruiseShip();
	CruiseShip( int, int, bool );
	void bringAllElevatorsToFloor1( int floor = 1 );
private:
	Elevator emptyWithAttendant(), onFloorSeven();
	Elevator forwardElevator(), aftElevator();
	int passenger, floor;
	bool attendant;
};
#endif
