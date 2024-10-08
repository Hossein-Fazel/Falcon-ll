#ifndef LOG_HPP
#define LOG_HPP
#include <iostream>
#include <vector>
#include "DataStruct__Func.hpp"
using namespace std;

struct SaveThings
{
    Location __location; //from DataStruct__Func.hpp
    string _next_move;
    int _energy_left;
    int _elapsed_time;
    //What I See? variable
};

class log_system
{
    public:
        log_system();
        void add(Location loc, string move, int energy, int time);
        bool _find_loc(int x ,int y);
        bool check_last(int x, int y);
        bool check_last(string str);
        void print();

    private:
        vector<SaveThings> logs;

};

#endif