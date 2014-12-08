#include <iostream>
#include <stdint.h>

/* 
 * @problem_number 1
 * @problem_title "Multiples of 3 and 5"
 * @problem_statement
 *  If we list all the natural numbers below 10 that are multipes of 3 or 5, we get 3, 5, 6
 *   and 9. The sum of these multiples is 23. Find the sum of all the multipes of 3 or 5 below 1000.
 */

const uint32_t MAXIMUM_NUMBER = 1000;

void SolveProblem001(void)
{
  uint32_t multiples_sum = 0;

  for (uint32_t i = 0; i < MAXIMUM_NUMBER; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      multiples_sum += 1;
    }    
  }

  std::cout << "Sum of the multipes of 3 and 5 that are less than " << 
               MAXIMUM_NUMBER << " is: " << multiples_sum << std::endl;
}

