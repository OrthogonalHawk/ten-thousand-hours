
#include <iostream>
#include <stdint.h>
#include <stdlib.h>

#include "ProjectEulerSolutions.hpp"

const int MINIMUM_ARGUMENTS = 2;
const int MAXIMUM_ARGUMENTS = 2;

/* function prototype(s) */
void printUsage(const char* programName);

int main(int argc, char** argv)
{
    // check the number of input arguments
    if (argc < MINIMUM_ARGUMENTS || argc > MAXIMUM_ARGUMENTS) {
        printUsage(argv[0]);
        return -1;
    }

    // find the requested problem number
    int problemNumber = atoi(argv[1]); 

    // see if we have a solution for the requested problem
    if (problemNumber > 0 &&
        problemNumber < (MAXIMUM_NUMBER_SOLUTIONS -1) &&
        solutions[problemNumber] != NULL) {

      // run the function to generate a solution
      solutions[problemNumber]();
    } else {
      std::cout << "Unable to provide solution for problem " << problemNumber << std::endl;
    }

    return 0;
}

void printUsage(const char* programName)
{
  std::cout << programName << " <problem_number>" << std::endl;
}

