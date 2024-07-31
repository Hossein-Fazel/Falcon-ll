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
            ss._move(0,3,0,0);
            ss._set_energy(ss._get_energy() - 12); // if we get logic error then could be here!
            ss._set_time  (ss._get_time() + 9);
            return;
        } 

        if(my_map.__get_main_map()[ss._get_Location()._X - 1][ss._get_Location()._Y] == 3)
        {
            ss._move(0,0,0,3);
            ss._set_energy(ss._get_energy() - 12); 
            ss._set_time  (ss._get_time() + 9);
            return;
        } 

        if(my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y + 1] == 3)
        {
            ss._move(0,0,3,0);
            ss._set_energy(ss._get_energy() - 12); 
            ss._set_time  (ss._get_time() + 9);
            return;
        } 

        if(my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y-1] == 3)
        {
            ss._move(3,0,0,0);
            ss._set_energy(ss._get_energy() - 12); 
            ss._set_time  (ss._get_time() + 9);
            return;
        } 
}

void worm_hole(Space_Ship ss , Map my_map)
{
    if (my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y] == 4)
    {
        Location sec_Four_loc;
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
    Map space_map;
    int row, column, spaceShip_x, spaceShip_y, energy;
    
    // map data
    cin >> row >> column;
    space_map.resize(row, column);

    // spaceship data
    cin >> spaceShip_x >> spaceShip_y >> energy;
    Space_Ship space_ship(spaceShip_x, spaceShip_y, energy, 0);

    //getting map cells
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            int cell_data; cin >> cell_data;
            space_map.set_data(i, j, cell_data);
        }
    }
}