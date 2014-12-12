#include <iostream>
#include <stdint.h>
#include <string.h>

/* 
 * @problem_number 4 
 * @problem_title "Largest Palindrome product"
 * @problem_statement
 *  A palindromic number reads the same both ways. The largest palindrome made from the product of
 *   two 2-digit numbers is 9009 = 91 x 99. Find the largest palindrome made from the product of
 *   two 3-digit numbers.
 */

namespace P004Sol {

const uint32_t MAXIMUM_NUMBER = 999;

bool isPalindrome(char* buffer, uint32_t length)
{
  if (length % 2 != 0)
    return false;

  for (uint32_t i = 0; i < (length / 2); ++i) {
    if (buffer[i] != buffer[length - i - 1])
      return false;
  }

  return true;
}

} // end P004Sol namespace

void SolveProblem004(void)
{
  char digitBuffer[32];
  uint32_t maxPalindromeLen = 0;
  uint32_t maxPalindrome = 0;

  for (uint32_t i = P004Sol::MAXIMUM_NUMBER; i > 0; --i) {
    for (uint32_t j = P004Sol::MAXIMUM_NUMBER; j > 0; --j) {

      // clear the digit buffer
      memset(digitBuffer, 0, 32);

      // calculate the new product
      uint32_t product = i * j;

      // convert the number into a string
      sprintf(digitBuffer, "%d", product);

      uint32_t len = strlen(digitBuffer);

      // if the length is not even, skip over this number
      if (len % 2 != 0)
        continue;

      if (P004Sol::isPalindrome(digitBuffer, len)) {
        if (len >= maxPalindromeLen && maxPalindrome < product) {
          maxPalindromeLen = len;
          maxPalindrome = product;
        }
      }
    }
  }

  std::cout << "Largest palindrome which is the product of two 3-digit numbers is: "
            << maxPalindrome << std::endl;
}

