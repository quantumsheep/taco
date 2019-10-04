#include <taco/dialog.hpp>
#include <taco/core.hpp>

#include <iostream>

void taco::dialog::up(size_t n)
{
    this->position = (this->position >= n) ? this->position - n : 0;
}

void taco::dialog::down(size_t n)
{
    size_t new_position = this->position + n;
    size_t max = this->possibilities.size();

    this->position = (new_position < max) ? new_position : max - 1;
}

void taco::dialog::display()
{
    taco::clear();

    std::cout << this->question << std::endl;

    size_t n = this->possibilities.size();

    for (size_t i = 0; i < n; i++)
    {
        std::cout << (i == this->position ? "> " : "  ") << this->possibilities[i].content << std::endl;
    }
}

void taco::dialog::run()
{
    bool running = true;

    while (running)
    {
        this->display();

        char touch = taco::getch();

        if (touch == this->up_key)
        {
            this->up();
        }

        if (touch == this->down_key)
        {
            this->down();
        }

        if (touch == this->select_key)
        {
            running = false;
            this->execute_selected();
        }
    }
}
