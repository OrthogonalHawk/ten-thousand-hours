#include <iostream>
#include <sstream>

#include <stdint.h>
#include <string.h>

static const uint32_t MAX_NUMBER_SIZE = 1024;
static const uint32_t TARGET_FIB_NUM_SIZE = 1000;


int main(void)
{
    uint8_t fibN[MAX_NUMBER_SIZE];
    uint8_t fibNPlus1[MAX_NUMBER_SIZE];
    uint8_t nextFib[MAX_NUMBER_SIZE];
    uint32_t fib_counter = 2;
    uint32_t fib_num_size = 1;

    // initialize all of the arrays to zero values
    memset(fibN, 0, MAX_NUMBER_SIZE);
    memset(fibNPlus1, 0, MAX_NUMBER_SIZE);
    memset(nextFib, 0, MAX_NUMBER_SIZE); 

    // set the initial Fib. numbers
    fibN[MAX_NUMBER_SIZE-1] = 1;
    fibNPlus1[MAX_NUMBER_SIZE-1] = 1;

    // calculate the next Fib. number
    while (fib_num_size > TARGET_FIB_NUM_SIZE)
    {

    } 

    std::cout << "Hello World!" << std::endl;
  
    return 0;
}
