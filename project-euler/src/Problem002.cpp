#include <iostream>
#include <stdint.h>

/* 
 * @problem_number 2 
 * @problem_title "Even Fibonacci Numbers"
 * @problem_statement
 *  Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting
 *   with 1 and 2, the first 10 terms are: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... 
 *  By considering the terms in the Fibonacci sequence whose values do not exceed four million, find
 *   the sum of the even-valued terms.
 */

namespace P002Sol {

const uint32_t MAXIMUM_SEQUENCE_NUMBER = 4000000;

uint32_t findNextFibonacciNumber(uint32_t num1, uint32_t num2)
{
  uint32_t nextNumber = num1 + num2;
  
  if (nextNumber > MAXIMUM_SEQUENCE_NUMBER)
    return 0;
  else {
    if (nextNumber % 2 == 0)
      return (findNextFibonacciNumber(num2, nextNumber) + nextNumber);
    else
      return findNextFibonacciNumber(num2, nextNumber);
  }
  
}

} // end of P002Sol namespace

void SolveProblem002(void)
{
  uint32_t num1 = 1;
  uint32_t num2 = 2;
  uint32_t evenSum = num2 + P002Sol::findNextFibonacciNumber(num1, num2);

  std::cout << "Sum of even Fibonacci numbers less than " << P002Sol::MAXIMUM_SEQUENCE_NUMBER
            << " is " << evenSum << std::endl;
}

