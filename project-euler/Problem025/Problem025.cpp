#include <iostream>
#include <stdint.h>

#include "LargeNumber.h"

static const uint32_t TARGET_FIB_LENGTH = 1000;

int main(void)
{
    LargeNumber fibN;
    LargeNumber fibNP1;
    LargeNumber nextFib;
    uint32_t fibTerm = 2;

    fibN.initialize(1);
    fibNP1.initialize(1);



    while (nextFib.getNumberLength() < TARGET_FIB_LENGTH)
    {
        nextFib = fibN + fibNP1;

        fibN = fibNP1;
        fibNP1 = nextFib;

        ++fibTerm;
    }

    std::cout << "The first Fibonacci number with more than " << TARGET_FIB_LENGTH
              << " digits is: " << nextFib.toString() << std::endl;

    std::cout << "This number is the " << fibTerm 
              << " number in the Fibonacci series." << std::endl;

    return 0;
}
