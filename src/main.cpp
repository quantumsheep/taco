#include <taco/taco.hpp>

#include <iostream>
#include <string>
#include <vector>

enum class Input
{
    Enter = 10,

    UpArrow = 65,
    DownArrow = 66,
    RightArrow = 67,
    LeftArrow = 68,
};

int main()
{

    taco::dialog dialog("Hello!");

    bool running = true;

    dialog.add_possibility("Yes", [&] {
        running = false;
        std::cout << "Yes" << std::endl;
    });

    dialog.add_possibility("No", [&] {
        running = false;
        std::cout << "No" << std::endl;
    });

    dialog.add_possibility("Quit", [&] {
        running = false;
    });

    while (running)
    {
        dialog.display();

        char touch = taco::getch();

        if (touch == static_cast<char>(Input::UpArrow))
        {
            dialog.up();
        }

        if (touch == static_cast<char>(Input::DownArrow))
        {
            dialog.down();
        }

        if (touch == static_cast<char>(Input::Enter))
        {
            dialog.execute_selected();
        }
    }

    return 0;
}
