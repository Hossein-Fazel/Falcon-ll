#include <bits/stdc++.h>
#include "DataStruct__Func.hpp"
#include "Space_Ship.hpp"
#include "map.hpp"

void ride(Space_Ship ss, Map my_map)
{
    space_current sc = my_map.detect_sc(ss._get_Location()._X , ss._get_Location()._Y, -1, -1);

    if(sc.cell_counter != -1)
    {
        int energy_consumption = sc.cell_counter * 2;
        int time_spent = sc.cell_counter;
        ss._set_Location(sc.end_point._X, sc.end_point._Y);
        ss._set_energy(ss._get_energy() - energy_consumption);
        ss._set_time(ss._get_time() - time_spent);
    }
}