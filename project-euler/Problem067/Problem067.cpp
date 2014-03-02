
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>
#include <vector>

uint32_t convert_string_to_number(std::string number_as_string)
{
    uint32_t number;
    std::stringstream convert(number_as_string);
    convert >> number;
    
    return number;
}

std::vector<uint32_t> convert_string_to_numbers(std::string numbers_as_string)
{
    std::vector<uint32_t> numbers;
    std::string delimiter = " ";
    std::string string_to_parse = numbers_as_string;
    uint32_t pos = 0;

    while ((pos = string_to_parse.find(delimiter)) != std::string::npos)
    {
        std::string number_as_string = string_to_parse.substr(0, pos);
        numbers.push_back(convert_string_to_number(number_as_string));

        // remove the extracted string
        string_to_parse.erase(0, pos + delimiter.length());
    }

    // make sure that we get the last one
    numbers.push_back(convert_string_to_number(string_to_parse));

    return numbers;    
}

int main(void)
{
    std::vector<std::string> numbers_as_strings;
    std::ifstream inputFile("triangle.txt");
  
    // read in all of the lines from the input file 
    std::string line;
    while (std::getline(inputFile, line))
    {
        numbers_as_strings.push_back(line);
    }

    // initialize the algorithm with the line from the bottom of the period
    std::vector<uint32_t> base_numbers = convert_string_to_numbers(numbers_as_strings.back());
    numbers_as_strings.pop_back();

    while (numbers_as_strings.size() > 0)
    {
        // get the next line from the triangle
        std::vector<uint32_t> next_numbers = convert_string_to_numbers(numbers_as_strings.back());
        numbers_as_strings.pop_back();

        std::vector<uint32_t> next_base;
        for (uint32_t i = 0; i < next_numbers.size(); ++i)
        {
            // calculate the best combination for this number and its possible bases
            uint32_t left_sum = next_numbers[i] + base_numbers[i];
            uint32_t right_sum = next_numbers[i] + base_numbers[i+1];
            (left_sum > right_sum) ? next_base.push_back(left_sum) : next_base.push_back(right_sum);
        }

        // now that we have a new base row, reassign it for the next evaluation
        base_numbers = next_base;
    }

    std::cout << "Only remaining base number is: " << base_numbers[0] << std::endl;

    return 0;
}

