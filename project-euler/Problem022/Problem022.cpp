
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>


uint32_t calculate_letter_score(std::string name)
{
    uint32_t letter_score = 0;

    for (uint32_t i = 0; i < name.length(); ++i)
    {
        letter_score += (name[i] - 'A' + 1);
    }

    return letter_score;
}

int main(void)
{
    std::vector<std::string> all_names;
    std::ifstream inputFile("names.txt");
    std::string delimiter = ",";

    std::string line;
    while (std::getline(inputFile, line))
    {
        // now that we have the line, split it into the individual name values
        uint32_t pos = 0;
        std::string name;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            name = line.substr(1, pos-2); // account for the double quotes bracketing the name
            all_names.push_back(name);
 
            // remove the extracted string from the input line
            line.erase(0, pos + delimiter.length());
        }
        
        // make sure that we get the last name
        name = line.substr(1, line.length()-2);
        all_names.push_back(name);
    }

    // sort the list of names into alphabetical order
    std::sort(all_names.begin(), all_names.end());

    uint64_t cumulative_score = 0;
    // go through each name and calculate the cumulative score
    for (uint32_t i = 0; i < all_names.size(); ++i)
    {
        cumulative_score += (calculate_letter_score(all_names[i]) * (i+1));
    }

    std::cout << "Found cumulative name score: " << cumulative_score << std::endl;

    return 0;
}

