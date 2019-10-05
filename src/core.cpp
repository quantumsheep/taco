#include <taco/core.hpp>

#include <iostream>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

void taco::clear()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

char taco::getch()
{
#ifdef _WIN32
    return _getch();
#else
    // Cache the existing terminal attributes
    termios original_attr;
    tcgetattr(STDIN_FILENO, &original_attr);

    termios new_attr = original_attr;
    new_attr.c_lflag &= ~(ICANON | ECHO);

    // Use the new attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
    int ch = getchar();

    // Restore the original attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &original_attr);

    return ch;
#endif
}
