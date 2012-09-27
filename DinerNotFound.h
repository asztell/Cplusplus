#ifndef DINERNOTFOUND_H
#define DINERNOTFOUND_H
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
#pragma warning( disable : 4290 )

namespace cs20 {

class DinerNotFound : public std::logic_error {

public:
	DinerNotFound();
};

}
#endif
