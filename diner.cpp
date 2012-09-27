#include <iostream>
#include <string>
#include <cstdlib>
#include "diner.h"
#include "restaurant.h"
#pragma warning( disable : 4290 )

namespace cs20 {

	Diner::Diner() : my_Name( "none" ), my_Table( "none" ),
		my_NumberOfTimesServed( 0 ) {}

	Diner::Diner( std::string name, std::string table )
	{ my_Name = name; my_Table = table; }

	std::string Diner::getName() const {
		return ( my_Name );
	}

	void Diner::setName( std::string name ) {
		my_Name = name;
	}

	std::string Diner::getTable() const {
		return ( my_Table );
	}

	void Diner::setTable( std::string table ) {
		my_Table = table;
	}

	int Diner::getNumberOfTimesServed() const {
		return ( my_NumberOfTimesServed );
	}

	void Diner::increaseNumberOfTimesServed( int amount=1 ) {
		my_NumberOfTimesServed = amount + my_NumberOfTimesServed;
	}

	std::ostream& operator<< ( std::ostream& out, const Diner & d ) {
		std::cout << "Diner name: " << d.getName() << std::endl
				  << "Table number: " << d.getTable() << std::endl;
		return out;
	}

}
