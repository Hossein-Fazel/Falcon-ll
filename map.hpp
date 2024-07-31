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
        void set_info(int x, int y , vector<vector<int>> & visited_map);
        int get_data(int x, int y);

        int _get_row() {return row;}
        int _get_column(){return column;}

        const vector<vector<int>> __get_main_map(){return main_map;};
        // can i do this? no its violates the principles of oop but with 'const', i think it could be better
        
        space_current detect_sc(int x, int y);


    private:
        vector<vector<int>> main_map;
        int column, row;
};


#endif