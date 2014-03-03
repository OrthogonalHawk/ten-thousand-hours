
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <string.h>

static const uint32_t GRID_SIZE = 5;
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
std::cout << "Setting: " << cur_row << "," << cur_col << " to: " << spiral_number << std::endl;
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

    print_grid(); 

    return 0;
}

