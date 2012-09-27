#ifndef DINER_H
#define DINER_H
#include <string>
#pragma warning( disable : 4290 )

namespace cs20 {

	class Diner {

	public:
		Diner();
		Diner( std::string, std::string );

		std::string getName() const;
		void setName( std::string name );

		std::string getTable() const;
		void setTable( std::string table );

		int getNumberOfTimesServed() const;
		void increaseNumberOfTimesServed( int amount );

		friend std::ostream& operator<< ( std::ostream&, const Diner & );

	private:
		std::string my_Name;
		std::string my_Table;
		int my_NumberOfTimesServed;
	};

}

#endif
