
#include <iostream>
#include <stdint.h>

static const uint32_t MAX_NUMBER = 1000;

int main(void)
{
    for (uint32_t a = 1; a < MAX_NUMBER; ++a)
    {
        for (uint32_t b = a; b < MAX_NUMBER; ++b)
        {
            for (uint32_t c = b; c < MAX_NUMBER; ++c)
            {
                if ((c*c) == (a*a + b*b) && ((a+b+c) == MAX_NUMBER))
                {
                    std::cout << "Found product: " << a * b * c << std::endl;
                    std::cout << a << "," << b << "," << c << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

