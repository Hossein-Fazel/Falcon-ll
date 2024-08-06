#ifndef DATASTRUCT__FUNC_HPP
#define DATASTRUCT__FUNC_HPP

#ifdef _WIN32
    #include <windows.h>
    #define Clear() system("cls")
#elif __linux__
    #include <stdio.h>  
    #define Clear() system("clear")
#else
    #error "Unsupported operating system"
#endif

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

struct view_point
{
    Location location;
    int count_new_cells;

    bool operator<(const view_point& ins) { return count_new_cells > ins.count_new_cells;}
};

#endif