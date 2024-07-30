#ifndef LOG_HPP
#define LOG_HPP
#include <iostream>
#include <vector>
#include "DataStruct__Func.hpp"
using namespace std;

struct SaveThings
{
    Location __location; //from DataStruct__Func.hpp
    std::string _next_move;
    //What I See? variable
};

class log_system
{
    public:
        log_system();
        void add(Location loc, string move);
        void print();

    private:
        vector<SaveThings> logs;

};

#endif