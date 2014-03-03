
#include <iostream>
#include <sstream>
#include <stdint.h>

enum MONTH_IN_YEAR 
{
    JAN = 0,
    FEB,
    MAR,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUG,
    SEPT,
    OCT,
    NOV,
    DEC
};

enum DAY_OF_WEEK
{
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

struct DAY_TRACKER
{
    uint32_t year;
    MONTH_IN_YEAR month;
    uint32_t day;
    DAY_OF_WEEK weekday;
};

bool is_leap_year(uint32_t year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;    
        }
        else
            return true;
    }
    else
        return false;
}

struct DAY_TRACKER get_next_day(struct DAY_TRACKER current_day)
{
    struct DAY_TRACKER new_day = current_day;
    bool increment_month = false;

    switch (new_day.weekday)
    {
        case SUNDAY: new_day.weekday = MONDAY; break;
        case MONDAY: new_day.weekday = TUESDAY; break;
        case TUESDAY: new_day.weekday = WEDNESDAY; break;
        case WEDNESDAY: new_day.weekday = THURSDAY; break;
        case THURSDAY: new_day.weekday = FRIDAY; break;
        case FRIDAY: new_day.weekday = SATURDAY; break;
        case SATURDAY: new_day.weekday = SUNDAY; break;
    }

    switch (new_day.month)
    {
        case FEB:
            if (is_leap_year(new_day.year))
            {
                if (++new_day.day > 29)
                {
                    new_day.day = 1;
                    increment_month = true;
                }
            }
            else
            {
                if (++new_day.day > 28)
                {
                    new_day.day = 1;
                    increment_month = true;
                }
            }
            break;

        case APRIL:
        case JUNE:
        case SEPT:
        case NOV:
            if (++new_day.day > 30)
            {
                new_day.day = 1;
                increment_month = true;
            }
            break;

        case JAN:
        case MAR:
        case MAY:
        case JULY:
        case AUG:
        case OCT:
        case DEC:
            if (++new_day.day > 31)
            {
                new_day.day = 1;
                increment_month = true;
            }
            break;

        default:
            std::cout << "ERROR - unhandled month!" << std::endl;
            break;
    }

    if (increment_month)
    {
        switch (new_day.month)
        {
            case JAN: new_day.month = FEB; break;
            case FEB: new_day.month = MAR; break;
            case MAR: new_day.month = APRIL; break;
            case APRIL: new_day.month = MAY; break;
            case MAY: new_day.month = JUNE; break;
            case JUNE: new_day.month = JULY; break;
            case JULY: new_day.month = AUG; break;
            case AUG: new_day.month = SEPT; break;
            case SEPT: new_day.month = OCT; break;
            case OCT: new_day.month = NOV; break;
            case NOV: new_day.month = DEC; break;
            case DEC: new_day.month = JAN;
                new_day.year++;
                break;
        }
    }

    return new_day;
}

std::string print_day(DAY_TRACKER day)
{
    std::stringstream output;

    output << "Year: " << day.year << " Month: " << day.month << " Day: " << day.day
           << " Day of Week: " << day.weekday;

    return output.str();
}

int main(void)
{
    struct DAY_TRACKER cur_day;
    uint32_t num_Sundays = 0;

    // initialize the day
    cur_day.weekday = MONDAY;
    cur_day.year = 1900;
    cur_day.day = 1;
    cur_day.month = JAN;

    while (cur_day.year < 2001)
    {
        cur_day = get_next_day(cur_day);

        if (cur_day.year >= 1901)
        {
            if (cur_day.day == 1 && cur_day.weekday == SUNDAY)
                num_Sundays++;
        }
    }

    std::cout << "Found " << num_Sundays << " Sundays." << std::endl;
    std::cout << " Final day: " << print_day(cur_day) << std::endl;

    return 0;
}

