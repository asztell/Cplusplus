#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <string>

class Elevator {
public:
	Elevator( int passengers = 0, int floor = 1, bool hasAttendant = true );
	int getFloor( ) const, getPassengers( ) const;
	bool hasAttendant( ) const;
	void moveToFloor( int );
	void addPassengers( int );
	void letOffPassengers( int );
	friend std::ostream& operator<< ( std::ostream&, const Elevator & );
private:
	int my_Passengers, my_Floor;
	bool my_HasAttendant;
};
#endif
