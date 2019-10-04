#include <taco/taco.hpp>

#include <iostream>

int main()
{
    taco::dialog dialog("Hello!");

    dialog.add_possibility("Yes", [] {
        std::cout << "Yes" << std::endl;
    });

    dialog.add_possibility("No", [] {
        std::cout << "No" << std::endl;
    });

    dialog.add_possibility("Quit", [] {});

    dialog.run();

    return 0;
}
