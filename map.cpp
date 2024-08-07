#include "map.hpp"

void Map::resize(int x, int y)
{
    this->main_map.assign(x, vector<int>(y, 0));
    this->row = x;
    this->column = y;
}

Map::Map(int x, int y)
{
    this->resize(x, y);
}

void Map::set_data(int x, int y, int data)
{
    if(x >= 0 and x < this->row and y >= 0 and y < this->column)
    {
        this->main_map[x][y] = data;
    }
}

int Map::get_data(int x, int y)
{
    if(x > 0 and x < this->row and y > 0 and y < this->column)
    {
        return this->main_map[x][y];
    }
}

void Map::set_info(int x, int y , vector<vector<int>>& visited_map)
{
    if(x >= 0 and x < this->row and y >= 0 and y < this->column)
    {
        visited_map[x][y] = main_map[x][y];

        if(x + 1 < row)
            visited_map[x+1][y] = main_map[x+1][y];
        
        if(x - 1 >= 0)
            visited_map[x-1][y] = main_map[x-1][y];
        
        if(y + 1 < column)
            visited_map[x][y + 1] = main_map[x][y + 1];
        
        if(y - 1 >= 0)
            visited_map[x][y - 1] = main_map[x][y - 1];
        
        if(y + 1 < column and x + 1 < row)
            visited_map[x + 1][y + 1] = main_map[x + 1][y + 1];
        
        if(x - 1 >= 0 and y - 1 >= 0)
            visited_map[x - 1][y - 1] = main_map[x - 1][y - 1];

        if(x - 1 >= 0 and y + 1 < column)
            visited_map[x - 1][y + 1] = main_map[x - 1][y + 1];

        if(x + 1 < row and y - 1 >= 0)
            visited_map[x + 1][y - 1] = main_map[x + 1][y - 1];
    }
}

space_current Map::detect_sc(int x, int y)
{
    if(x >= 7 or x < 0) return space_current{Location{x, y}, -1};
    if(y >= 6 or y < 0) return space_current{Location{x, y}, -1};
    if(main_map[x][y] != 1 and main_map[x][y] != 2) return space_current{Location{x, y}, -1};
    if(main_map[x][y] == 0) return space_current{Location{x, y}, -1};

    space_current ans, maxx;
    maxx.cell_counter = -1;
    int temp = main_map[x][y];
    main_map[x][y] = -2;

    ans = detect_sc(x + 1, y);
    if(ans.cell_counter != -1)
    {
        ans.cell_counter++;
        if(ans.cell_counter > maxx.cell_counter) maxx = ans;
    }

    ans = detect_sc(x - 1, y);
    if(ans.cell_counter != -1)
    {
        ans.cell_counter++;
        if(ans.cell_counter > maxx.cell_counter) maxx = ans;
    }

    ans = detect_sc(x, y + 1);
    if(ans.cell_counter != -1)
    {
        ans.cell_counter++;
        if(ans.cell_counter > maxx.cell_counter) maxx = ans;
    }

    ans = detect_sc(x, y - 1);
    if(ans.cell_counter != -1)
    {
        ans.cell_counter++;
        if(ans.cell_counter > maxx.cell_counter) maxx = ans;
    }
    main_map[x][y] = temp;
    
    if(maxx.cell_counter != -1) return maxx;
    if(main_map[x][y] == 1) return space_current{Location{x, y}, 0};
    return space_current{Location{0, 0}, -1};
}

void Map::print(int x, int y)
{
    Clear();
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i == x and j == y)
            {
                cout << "* ";
                continue;
            }
            cout << main_map[i][j] << " ";
        }
        cout << '\n';
    }
}