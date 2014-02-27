#ifndef LARGE_NUMBER_H
#define LARGE_NUMBER_H

#include <string>

#include <stdint.h>
#include <string.h>

class LargeNumber
{
public:

    static const uint32_t MAXIMUM_LARGE_NUMBER_LENGTH = 2048;

    LargeNumber(void);
    virtual ~LargeNumber(void);

    void initialize(uint32_t startingValue);
    std::string toString(void);
    uint32_t getNumberLength(void);

    LargeNumber& operator=(const LargeNumber &rhs);
    LargeNumber& operator+=(const LargeNumber &rhs);
    const LargeNumber operator+(const LargeNumber &other) const;
 
    bool operator==(const LargeNumber &other) const;
    bool operator!=(const LargeNumber &other) const;

private:

    uint8_t* number_array;
};

#endif // LARGE_NUMBER_H 
