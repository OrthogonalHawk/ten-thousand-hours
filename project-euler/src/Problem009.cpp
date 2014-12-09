
#include <iostream>
#include <stdint.h>

/* 
 * @problem_number 9
 * @problem_title "Special Pythagorean Triplet"
 * @problem_statement
 *  A Pythagorean Triplet is a set of three natural numbers, a < b < c, for which,
 *
 *       a^2 + b^2 = c^2
 *
 *  For example: 3^2 + 4^2 = 9 + 16 = 25 = 5^2
 *
 *  There exists exactly one Pythagorean Triplet for which a + b + c = 1000. Find
 *   the product a * b * c.
 */

namespace P009Sol {

static const uint32_t MAX_NUMBER = 1000;

}

void SolveProblem009(void)
{
    for (uint32_t a = 1; a < P009Sol::MAX_NUMBER; ++a)
    {
        for (uint32_t b = a; b < P009Sol::MAX_NUMBER; ++b)
        {
            for (uint32_t c = b; c < P009Sol::MAX_NUMBER; ++c)
            {
                if ((c*c) == (a*a + b*b) && ((a+b+c) == P009Sol::MAX_NUMBER))
                {
                    std::cout << "Identified Pythagorean Triplet (a,b,c)=("
                              << a << "," << b << "," << c << ")=" << P009Sol::MAX_NUMBER << std::endl;
                    std::cout << " Resulting product abc=" << a * b * c << std::endl;
                    return;
                }
            }
        }
    }
}

