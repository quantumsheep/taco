#include <taco/taco.hpp>

#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> board = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    const size_t board_size = board.size();

    std::string board_str = "";

    for (size_t y = 0; y < board.size(); y++)
    {
        for (size_t x = 0; x < board[y].size(); x++)
        {
            if (board[y][x] == 1)
            {
                board_str += '*';
            }
            else
            {
                board_str += ' ';
            }
        }

        board_str += '\n';
    }

    int player_x = 0;
    int player_y = 0;

    bool running = true;
    while (running)
    {
        taco::clear();

        int pos = player_y * board_size + player_x + player_y;
        std::string board_new = board_str;
        board_new[pos] = '0';

        std::cout << board_new;

        char key = taco::getch();

        if (key == taco::input::up_arrow)
        {
            if (player_y > 0)
            {
                player_y--;
            }
        }
        else if (key == taco::input::down_arrow)
        {
            if (player_y < board_size - 1)
            {
                player_y++;
            }
        }
        else if (key == taco::input::right_arrow)
        {
            if (player_x < board_size - 1)
            {
                player_x++;
            }
        }
        else if (key == taco::input::left_arrow)
        {
            if (player_x > 0)
            {
                player_x--;
            }
        }

        if (key == taco::input::ctrl_c)
        {
            running = false;
        }
    }

    return 0;
}
