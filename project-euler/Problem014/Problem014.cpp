#include <iostream>
#include <stdint.h>
#include <unordered_map>

static const uint64_t MAXIMUM_STARTING_NUMBER = 1000000;


uint64_t find_next_collatz_number(uint64_t current_number)
{
    if (current_number == 1)
        return 1;
    else if (current_number % 2 == 1)
        return (current_number * 3 + 1);
    else
        return (current_number / 2);
}
 
int main(void)
{
    std::unordered_map<uint64_t, uint64_t> known_sequences;
    uint64_t max_number_of_terms = 0;
    uint64_t max_starting_number = 0;

    for (uint64_t starting_number = 1;
         starting_number < MAXIMUM_STARTING_NUMBER;
         ++starting_number)
    {
        uint64_t cur_collatz_number = starting_number;
        uint64_t number_of_terms = 1;
        
        while (cur_collatz_number != 1)
        {
            cur_collatz_number = find_next_collatz_number(cur_collatz_number);
            number_of_terms++;

            // see if we can shortcut further evaluation
            if (known_sequences.count(cur_collatz_number) == 1)
            {
                number_of_terms += (known_sequences[cur_collatz_number] - 1);
                break;
            }

        }

        // update our 'cheat sheet'
        known_sequences[starting_number] = number_of_terms;

        if (number_of_terms > max_number_of_terms)
        {
            max_number_of_terms = number_of_terms;
            max_starting_number = starting_number;
        }
    }

    std::cout << "Maximum number of terms for a starting number less than "
              << MAXIMUM_STARTING_NUMBER << " is: " << max_number_of_terms << std::endl;

    std::cout << "Found maximum steps with starting number: " << max_starting_number << std::endl; 

    return 0;
}

