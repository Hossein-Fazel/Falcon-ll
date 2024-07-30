#ifndef MAP_HPP
#define MAP_HPP
#include <bits/stdc++.h>
#include "DataStruct__Func.hpp"

using namespace std;
class Map
{
    public:
        Map(){};
        Map(int x, int y);
        void resize(int x, int y);
        void set_data(int x ,int y, int data);
        void set_info(int x, int y);
        int get_data(int x, int y);
        
        space_current detect_sc(int x, int y, int pre_x, int pre_y);


    private:
        vector<vector<int>> main_map;
        vector<vector<int>> visited_map;
        int column, row;
};


#endif