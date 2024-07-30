#ifndef DATASTRUCT__FUNC_HPP
#define DATASTRUCT__FUNC_HPP

struct Location
{
    int _X;
    int _Y;
};

struct space_current
{
    Location end_point;
    int cell_counter = 0;
};

#endif