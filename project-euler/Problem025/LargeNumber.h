#ifndef LARGE_NUMBER_H
#define LARGE_NUMBER_H

#include <stdint.h>
#include <string.h>

class LargeNumber
{
public:

    static const uint32_t MAXIMUM_LARGE_NUMBER_LENGTH = 2048;

    LargeNumber(void);
    virtual ~LargeNumber(void);

    void initialize(uint32_t startingValue);

    LargeNumber & operator=(const LargeNumber &rhs);

private:

    uint8_t* number_array;
    uint32_t number_len;
};

#endif // LARGE_NUMBER_H 
