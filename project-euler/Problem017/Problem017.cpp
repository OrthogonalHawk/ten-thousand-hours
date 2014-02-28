#include <iostream>
#include <sstream>
#include <string>
#include <stdint.h>

static const uint32_t MAXIMUM_NUMBER = 1000;

static const uint32_t NUM_SINGLE_DIGITS = 10;
static const uint32_t NUM_TENS_DIGITS = 10;

std::string SingleDigitStrings[NUM_SINGLE_DIGITS] = {"", "one", "two", "three", "four", "five",
                                                     "six", "seven", "eight", "nine"};

std::string TensDigitStrings[NUM_TENS_DIGITS] = {"", "", "twenty ", "thirty ", "forty ", "fifty ",
                                                 "sixty ", "seventy ", "eighty ", "ninety "};
std::string HundredsDigitString = " hundred ";

std::string ThousandsDigitString = " thousand ";

uint32_t count_characters(std::string number)
{
    uint32_t num_characters = 0;

    for (uint32_t i = 0; i < number.length(); ++i)
    {
        if (number[i] != ' ' &&
            number[i] != 0)
        {
            num_characters++;
        }
    }

    return num_characters;
}

int main(void)
{
    uint32_t number_characters_used = 0;
    uint32_t cur_number = 1;

    do
    {
        // assemble the next number
        uint32_t thousandsDigit = (cur_number / 1000);
        uint32_t hundredsDigit  = (cur_number / 100 ) - thousandsDigit * 10;
        uint32_t tensDigit      = (cur_number / 10  ) - hundredsDigit * 10 - thousandsDigit * 100;
        uint32_t onesDigit      = (cur_number % 10  );

        std::stringstream numberString;

        if (thousandsDigit != 0)
            numberString << SingleDigitStrings[thousandsDigit] << ThousandsDigitString;

        if (hundredsDigit != 0)
        {
            numberString << SingleDigitStrings[hundredsDigit] << HundredsDigitString;

            if (tensDigit != 0 || onesDigit != 0)
                numberString << "and ";
        }

        if (tensDigit != 0)
        {
            if (tensDigit >= 2)
            {
                // handle all numbers between 20 and 99
                numberString << TensDigitStrings[tensDigit];
                numberString << SingleDigitStrings[onesDigit];
            }
            // handle the numbers between 10 and 19
            else
            {
                switch (onesDigit)
                {
                    case 0: numberString << " ten "; break;
                    case 1: numberString << " eleven "; break;
                    case 2: numberString << " twelve "; break;
                    case 3: numberString << " thirteen "; break;
                    case 4: numberString << " fourteen "; break;
                    case 5: numberString << " fifteen "; break;
                    case 6: numberString << " sixteen "; break;
                    case 7: numberString << " seventeen "; break;
                    case 8: numberString << " eighteen "; break;
                    case 9: numberString << " nineteen "; break;
                }
            }
        }
        else
        {
            // handle the number between 0-9
            numberString << SingleDigitStrings[onesDigit]; 
        }

        std::cout << "Current Number Representation: " << numberString.str() << std::endl;
        number_characters_used += count_characters(numberString.str());

        cur_number += 1;
    } while (cur_number <= MAXIMUM_NUMBER);

    std::cout << "These numbers used: " << number_characters_used << " characters!!!" << std::endl;

    return 0;
}

