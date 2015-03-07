/* 
 * @problem_number 12
 * @problem_title "Highly Divisible Triangle Number"
 * @problem_statement
 *  The sequence of triangle numbes is generated by adding the natural numbers. So the 7th triangle
 *   number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 *      1, 3, 6, 10, 15, 21, 28, 36, 45, 55
 *
 *  Let us list the factors of the first seven triangle numbers:
 *    1: 1
 *    3: 1, 3
 *    6: 1, 2, 3, 6
 *   10: 1, 2, 5, 10
 *   15: 1, 3, 4, 15
 *   21: 1, 3, 7, 21
 *   28: 1, 2, 4, 7, 14, 28
 *
 *  We can see that 28 is the first triangle number with more than 5 divisors. What is the value
 *   of the first triangle number to have more then 500 divisors?
 */

#include <iostream>
#include <stdint.h>

#include "CommonUtilities.hpp"

namespace P012Sol {

const uint32_t MAX_ITERATIONS = 10000;
const uint32_t TARGET_NUM_DIVISORS = 500;

}


void SolveProblem012(void)
{
  uint32_t curTriangleNumber = 0;
  uint32_t maxNumDivisors = 0;
  uint32_t targetTriangleNumber = 0;

  for (uint32_t i = 1; i <= P012Sol::MAX_ITERATIONS; ++i) {
    curTriangleNumber += i;
  
    uint32_t numDivisors = getNumberOfDivisors(curTriangleNumber);
    if (numDivisors > P012Sol::TARGET_NUM_DIVISORS) {
      std::cout << "Triangle number with more than " << P012Sol::TARGET_NUM_DIVISORS
                << " divisors is: " << curTriangleNumber << std::endl;
      break;    
    }

    if (numDivisors > maxNumDivisors) {
      maxNumDivisors = numDivisors;
      targetTriangleNumber = curTriangleNumber;
    }
  }

  std::cout << "Largest number of divisors was: " << maxNumDivisors
            << " for triangle number: " << targetTriangleNumber << std::endl;
}
