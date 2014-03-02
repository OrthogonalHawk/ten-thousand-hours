
#include <iostream>
#include <stdint.h>

enum {
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
} MONTH;

enum {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} DAY;

struct {
    uint32_t year;
    MONTH month;
    DAY day;
} DAY_TRACKER;

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

    switch (current_day.month)
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
    }

    return new_day;
}

int main(void)
{
    return 0;
}

