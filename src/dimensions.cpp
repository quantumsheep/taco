#include <taco/dimensions.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

const taco::size taco::dimensions()
{
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return taco::size{
        csbi.srWindow.Right - csbi.srWindow.Left + 1,
        csbi.srWindow.Bottom - csbi.srWindow.Top + 1,
    };
#else
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    return taco::size{size.ws_col, size.ws_row};
#endif
}
