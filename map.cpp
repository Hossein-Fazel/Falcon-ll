#include "map.hpp"

void Map::resize(int x, int y)
{
    this->main_map.assign(x, vector<int>(y, 0));
    this->visited_map.assign(x, vector<int>(y, 0));
    this->row = x;
    this->column = y;
}

Map::Map(int x, int y)
{
    this->resize(x, y);
}

void Map::set_data(int x, int y, int data)
{
    if(x > 0 and x < this->row and y > 0 and y < this->column)
    {
        this->main_map[x][y] = data;
    }
}

int Map::get_data(int x, int y)
{
    if(x > 0 and x < this->row and y > 0 and y < this->column)
    {
        return this->visited_map[x][y];
    }
}

void Map::set_info(int x, int y)
{
    if(x > 0 and x < this->row and y > 0 and y < this->column)
    {
        visited_map[x][y] = main_map[x][y];

        if(x + 1 < row)
            visited_map[x+1][y] = main_map[x+1][y];
        
        if(x - 1 > 0)
            visited_map[x-1][y] = main_map[x-1][y];
        
        if(y + 1 < column)
            visited_map[x][y + 1] = main_map[x][y + 1];
        
        if(y - 1 > 0)
            visited_map[x][y - 1] = main_map[x][y - 1];
        
        if(y + 1 < column and x + 1 < row)
            visited_map[x + 1][y + 1] = main_map[x + 1][y + 1];
        
        if(x - 1 > 0 and y - 1 > 0)
            visited_map[x - 1][y - 1] = main_map[x - 1][y - 1];

        if(x - 1 > 0 and y + 1 < column)
            visited_map[x - 1][y + 1] = main_map[x - 1][y + 1];

        if(x + 1 < row and y - 1 > 0)
            visited_map[x + 1][y - 1] = main_map[x][y - 1];
    }
}