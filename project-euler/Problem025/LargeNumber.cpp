#include "LargeNumber.h"

LargeNumber::LargeNumber(void)
    : number_array(NULL),
      number_len(MAXIMUM_LARGE_NUMBER_LENGTH)
{
    // empty
}

LargeNumber::~LargeNumber(void)
{
    // free the memory array if it exists
    if (number_array != NULL)
    {
        delete[] number_array;
    }
}

void LargeNumber::initialize(uint32_t startingValue)
{
    if (number_array != NULL)
    {
        // free the existing memory
        delete [] number_array;
    }

    // create the new array
    number_array = new uint8_t[number_len];

    // zero out the array
    memset(number_array, 0, number_len);
}

LargeNumber& LargeNumber::operator=(const LargeNumber &rhs)
{
    // only do assignment if RHS is a different object
    if (this != &rhs)
    {
        this->initialize(0);        
    }

    // copy from one number to another (revisit if the lengths can vary)
    memcpy(this->number_array, rhs.number_array, this->number_len);
    
    return *this;
}

