#pragma once

namespace taco
{
struct size
{
    int columns;
    int rows;
};

const taco::size dimensions();
inline const int columns() { return taco::dimensions().columns; }
inline const int rows() { return taco::dimensions().rows; }
} // namespace taco
