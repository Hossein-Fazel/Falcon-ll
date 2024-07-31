#include <bits/stdc++.h>
#include "DataStruct__Func.hpp"
#include "Space_Ship.hpp"
#include "map.hpp"

void ride(Space_Ship ss, Map my_map)
{
    space_current sc = my_map.detect_sc(ss._get_Location()._X , ss._get_Location()._Y);

    if(sc.cell_counter != -1)
    {
        int energy_consumption = sc.cell_counter * 2;
        int time_spent = sc.cell_counter;
        ss._set_Location(sc.end_point._X, sc.end_point._Y);
        ss._set_energy(ss._get_energy() - energy_consumption);
        ss._set_time(ss._get_time() + time_spent);
    }
}

void space_object(Space_Ship ss , Map my_map)
{
        if(my_map.__get_main_map()[ss._get_Location()._X + 1][ss._get_Location()._Y] == 3)
        {
            ss._move(0,3);
            ss._set_energy(ss._get_energy() - 12);
            ss._set_time  (ss._get_time() + 9);
            return;
        } 

        if(my_map.__get_main_map()[ss._get_Location()._X - 1][ss._get_Location()._Y] == 3)
        {
            ss._move(0,-3);
            ss._set_energy(ss._get_energy() - 12); 
            ss._set_time  (ss._get_time() + 9);
            return;
        } 

        if(my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y + 1] == 3)
        {
            ss._move(-3,0);
            ss._set_energy(ss._get_energy() - 12); 
            ss._set_time  (ss._get_time() + 9);
            return;
        } 

        if(my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y-1] == 3)
        {
            ss._move(3,0);
            ss._set_energy(ss._get_energy() - 12); 
            ss._set_time  (ss._get_time() + 9);
            return;
        } 
}

void worm_hole(Space_Ship ss , Map my_map)
{
    if (my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y] == 4)
    {
        for (int i{0} ; i < my_map._get_row() ;i++ )
        {
            for (int j{0} ; j < my_map._get_column() ;j++ )
            {
                if (my_map.__get_main_map()[i][j] == 4 && j != ss._get_Location()._Y && i != ss._get_Location()._X )
                {
                    ss._set_Location(i,j);
                    ss._set_energy(ss._get_energy() / 2);
                    return;
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> visited_map;

    Map space_map;
    int row, column, spaceShip_x, spaceShip_y, energy;
    
    cin >> row >> column;
    space_map.resize(row, column);

    cin >> spaceShip_x >> spaceShip_y >> energy;
    Space_Ship space_ship(spaceShip_x, spaceShip_y, energy, 0);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            int cell_data; cin >> cell_data;
            space_map.set_data(i, j, cell_data);
        }
    }

    do
    {
        vector<int> data;

        int y = space_ship._get_Location()._Y;
        int x = space_ship._get_Location()._X;

        space_map.set_info(x ,y , visited_map);
        bool is_home = false;

        if(visited_map[x][y] != 0 and visited_map[x][y] != 2)
            data.push_back(visited_map[x][y]);   

        if(x + 1 < row and visited_map[x+1][y] != 0 and visited_map[x+1][y] != 2 )
        {
            data.push_back(visited_map[x+1][y]); 
            is_home = 1;
        }

        if(x - 1 > 0 and visited_map[x-1][y] != 0 and visited_map[x-1][y] != 2)
        {
            data.push_back(visited_map[x-1][y]);
            is_home = 1;
        }
        
        if(y + 1 < column and visited_map[x][y+1] != 0 and visited_map[x][y+1] != 2)
        {
            data.push_back(visited_map[x][y+1]);
            is_home = 1;
        }
        
        if(y - 1 > 0 and visited_map[x][y-1] != 0 and visited_map[x][y-1] != 2)
        {
            data.push_back(visited_map[x][y-1]);
            is_home = 1;
        }
        
        if(y + 1 < column and x + 1 < row and visited_map[x+1][y+1] != 0 and visited_map[x+1][y+1] != 2)
        {
            data.push_back(visited_map[x+1][y+1]);
            is_home = 1;
        }
        
        if(x - 1 > 0 and y - 1 > 0 and visited_map[x-1][y-1] != 0 and visited_map[x-1][y-1] != 2)
        {
            data.push_back(visited_map[x-1][y-1]);
            is_home = 1;
        }

        if(x - 1 > 0 and y + 1 < column and visited_map[x-1][y+1] != 0 and visited_map[x-1][y+1] != 2)
        {
           data.push_back(visited_map[x-1][y+1]);
            is_home = 1;
        }

        if(x + 1 < row and y - 1 > 0 and visited_map[x+1][y-1] != 0 and visited_map[x+1][y-1] != 2)
        {
            data.push_back(visited_map[x+1][y-1]);
            is_home = 1;
        }


        if ( data.size() == 0)
        {
            int random_X;
            int random_Y;
            do
            {
                random_X = -1+ (rand() % 3);
                random_Y = -1+ (rand() % 3);

                space_ship._move(random_X , random_Y);
                
            } while( space_ship._move(random_X,random_Y));
        }


    } while (visited_map[space_ship._get_Location()._X][space_ship._get_Location()._Y] != 5);
    
}