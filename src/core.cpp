#include <taco/core.hpp>

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
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
    // The following code attempts to manually reproduce the same behaviour as the
    // getch function from Windows' conio.h

    // Cache the existing terminal attributes
    struct termios cachedAttributes, customAttributes;
    tcgetattr(STDIN_FILENO, &cachedAttributes);

    // Copy them, and change the flags needed to achieve getch-style behaviour
    customAttributes = cachedAttributes;
    customAttributes.c_lflag &= ~(ICANON | ECHO);

    // Set the attributes to the new ones, read a character with getchar
    tcsetattr(STDIN_FILENO, TCSANOW, &customAttributes);
    int ch = getchar();

    // Restore the original terminal attribute setup
    tcsetattr(STDIN_FILENO, TCSANOW, &cachedAttributes);

    // Return the character that was read
    return ch;
#endif // _WIN32
}
