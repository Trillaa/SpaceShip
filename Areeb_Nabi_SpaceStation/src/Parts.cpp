#include "Parts.h"

Parts::Parts()
{
    id = 0;
    //constructor
}

Parts::~Parts()
{
    //destructor
}

Parts::Parts(const Parts& other)
{
    id = other.id;
    //copy constructor
}

Parts& Parts::operator=(const Parts& rhs)
{
    if (this == &rhs) return *this;
    id = rhs.id;
    ///Assignment Operator
    return *this;
}
