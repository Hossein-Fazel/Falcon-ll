#ifndef MAP_HPP
#define MAP_HPP
#include <bits/stdc++.h>

using namespace std;
class Map
{
    public:
        Map(){};
        Map(int x, int y);
        void resize(int x, int y);
        void set_data(int x ,int y, int data);
        void set_info(int x, int y);


    private:
        vector<vector<int>> main_map;
        vector<vector<int>> visited_map;
        int column, row;
};


#endif