#pragma once

namespace taco
{
#ifdef _WIN32
enum class input
{
    ctrl_c = 3,

    enter = 13,

    up_arrow = 72,
    down_arrow = 80,
    right_arrow = 77,
    left_arrow = 75,
};
#else
enum class input
{
    ctrl_c = -1,

    enter = 10,

    up_arrow = 65,
    down_arrow = 66,
    right_arrow = 67,
    left_arrow = 68,
};
#endif
} // namespace taco

inline bool operator==(const char &c, const taco::input &in)
{
    return c == static_cast<char>(in);
}

inline bool operator!=(const char &c, const taco::input &in)
{
    return !(c == in);
}
