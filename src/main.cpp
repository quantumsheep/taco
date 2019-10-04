#include <taco/taco.hpp>

#include <iostream>
#include <string>
#include <vector>

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

        if (touch == taco::input::up_arrow)
        {
            dialog.up();
        }

        if (touch == taco::input::down_arrow)
        {
            dialog.down();
        }

        if (touch == taco::input::enter)
        {
            dialog.execute_selected();
        }

        if (touch == taco::input::ctrl_c)
        {
            running = false;
        }
    }

    return 0;
}
