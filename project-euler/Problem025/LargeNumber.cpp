#include "LargeNumber.h"

#include <iostream>
#include <sstream>


LargeNumber::LargeNumber(void)
    : number_array(NULL)
{
    initialize(0);
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
    number_array = new uint8_t[MAXIMUM_LARGE_NUMBER_LENGTH];

    // zero out the array
    memset(number_array, 0, MAXIMUM_LARGE_NUMBER_LENGTH);
}

std::string LargeNumber::toString(void)
{
    std::stringstream number_repr;

    for (uint32_t i = getNumberLength(); i > 0; i--)
    {
        number_repr << (uint32_t)number_array[i-1];
    }

    return number_repr.str();
}

uint32_t LargeNumber::getNumberLength(void)
{
    for (uint32_t i = (MAXIMUM_LARGE_NUMBER_LENGTH-1); i >= 1; --i)
    {
        if (number_array[i] != 0)
        {
            return i;
        }
    }

    return 1;
}

LargeNumber& LargeNumber::operator=(const LargeNumber &rhs)
{
    // only do assignment if RHS is a different object
    if (this != &rhs)
    {
        this->initialize(0);        
    }

    // copy from one number to another
    memcpy(this->number_array, rhs.number_array, MAXIMUM_LARGE_NUMBER_LENGTH);
    
    return *this;
}

LargeNumber& LargeNumber::operator+=(const LargeNumber &rhs)
{
    uint32_t carry_over = 0;
    uint32_t cur_sum = 0;

    for (uint32_t i = 0; i < MAXIMUM_LARGE_NUMBER_LENGTH; ++i)
    {
        cur_sum = number_array[i] + rhs.number_array[i] + carry_over;

        number_array[i] = cur_sum % 10;
        carry_over = cur_sum > 9 ? 1 : 0;
    }

    return *this;
}

const LargeNumber LargeNumber::operator+(const LargeNumber &other) const
{
    return LargeNumber(*this) += other;
}

bool LargeNumber::operator==(const LargeNumber &other) const
{
    bool ret_value = true;

    for (uint32_t i = 0; i < MAXIMUM_LARGE_NUMBER_LENGTH; ++i)
    {
        if (number_array[i] != other.number_array[i])
        {
            ret_value = false;
            break;
        }
    }

    return ret_value;    
}

bool LargeNumber::operator!=(const LargeNumber &other) const
{
    return !(*this == other);
}

