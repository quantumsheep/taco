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
