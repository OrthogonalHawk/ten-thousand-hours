#include <iostream>
#include <stdint.h>

uint32_t getNumberOfDivisors(uint32_t number)
{
  uint32_t numDivisors = 0;

  // add 1 for the number itself (since we only iterate through number / 2)
  numDivisors++;

  if (number != 1) {

    for (uint32_t i = 1; i <= (number / 2); ++i) {
      if (number % i == 0)
        numDivisors++;
    }

  }

  return numDivisors;
}
