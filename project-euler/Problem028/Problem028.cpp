
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <string.h>

static const uint32_t GRID_SIZE = 1001;
uint32_t number_grid[GRID_SIZE][GRID_SIZE];

enum DIRECTION
{
    RIGHT = 0,
    LEFT,
    DOWN,
    UP
};

void print_grid(void)
{
    for (uint32_t row = 0; row < GRID_SIZE; ++row)
    {
        for (uint32_t col = 0; col < GRID_SIZE; ++col)
        {
            std::cout << std::setw(2) << number_grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    // create and initialize the grid
    memset(number_grid, 0, GRID_SIZE * GRID_SIZE);

    // populate the spiral grid
    int32_t cur_row = (GRID_SIZE / 2);
    int32_t cur_col = (GRID_SIZE / 2);
  
    int32_t down_turn_col  = cur_col + 1;
    int32_t left_turn_row  = cur_row + 1;
    int32_t up_turn_col    = cur_col - 1;
    int32_t right_turn_row = cur_row - 1;

    DIRECTION next_direction = RIGHT; 
    uint32_t spiral_number = 1;

    do
    {
        // set the next spiral number
        number_grid[cur_row][cur_col] = spiral_number++;

        // find the next spiral location
        switch (next_direction)
        {
            case RIGHT:
                cur_col++;
                if (cur_col == down_turn_col)
                {
                    next_direction = DOWN;
                    down_turn_col++;
                }
                break;
            case LEFT:
                cur_col--;
                if (cur_col == up_turn_col)
                {
                    next_direction = UP;
                    up_turn_col--;
                }
                break;
            case DOWN:
                cur_row++;
                if (cur_row == left_turn_row)
                {
                    next_direction = LEFT;
                    left_turn_row++;
                }
                break;
            case UP:
                cur_row--;
                if (cur_row == right_turn_row)
                {
                    next_direction = RIGHT;
                    right_turn_row--;
                } 
                break;
        }
    } while (!(cur_row == 0 && cur_col == (GRID_SIZE-1)));

    // write the last number
    number_grid[cur_row][cur_col] = spiral_number;

    // sum the numbers on the diagonals
    uint32_t diagonal_sum = 0;
    for (uint32_t i = 0; i < GRID_SIZE; ++i)
    {
        diagonal_sum += number_grid[i][i];
        diagonal_sum += number_grid[GRID_SIZE-1-i][i];
    }
    diagonal_sum--; // double counted the very center, so reduce our count by 1

    std::cout << "Found diagonal sum: " << diagonal_sum << std::endl;

    return 0;
}

