#ifndef VALUENOTFOUND_H
#define VALUENOTFOUND_H
#include <iostream>
#include <string>

namespace cs20 {

class ValueNotFound : public std::logic_error {
public:
	ValueNotFound( const std::string& msg = "" );
};

}

#endif