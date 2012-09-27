#include "DinerNotFound.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>
#pragma warning( disable : 4290 )

namespace cs20 {

	DinerNotFound::DinerNotFound() : logic_error( "diner not found" ) {}

}
