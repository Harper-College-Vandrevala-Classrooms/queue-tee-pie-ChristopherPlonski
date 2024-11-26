#ifndef CUTIE_HPP
#define CUTIE_HPP

#include <string>

using namespace std;

class Cutie {

public:
	virtual string description() = 0;     // All cuties need to have a description of what makes them cute.
	virtual int cuteness_rating() = 0; // All cuties get a cuteness rating out of ten.

};

#endif // !CUTIE_HPP