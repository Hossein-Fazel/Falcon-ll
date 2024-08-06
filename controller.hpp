#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <bits/stdc++.h>
using namespace std;

#include "Space_Ship.hpp"
#include "map.hpp"
#include "Log.hpp"
#include "DataStruct__Func.hpp"


class controller
{
    private:
        log_system logs;
        vector<vector<int>> visited_map;
        int home_x , home_y;
        Map space_map;
        Space_Ship space_ship{0,0,0,0};
        int row, column, spaceShip_x, spaceShip_y, energy;

    public :
        controller(){};
        void run();
        void ride(Space_Ship ss, Map my_map);
        void space_object(Space_Ship ss , Map my_map);
        void worm_hole(Space_Ship ss , Map my_map);
        int get_visible_new_cells(int curr_x, int curr_y, int next_x, int next_y);
        bool __visit_2_3_(int x , int y , vector<vector<int>> map);
        vector<view_point> get_view_points();
        void algo(Space_Ship ss  , Map myMap);
};

#endif