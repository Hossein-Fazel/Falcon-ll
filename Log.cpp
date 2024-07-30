#include "log.hpp"


log_system::log_system()
{
}

void log_system::add(Location loc, string move)
{
    SaveThings temp;
    temp.__location = loc;
    temp._next_move = move;

    this->logs.push_back(temp);
}

void log_system::print()
{
    for(const auto item : this->logs)
    {
        cout << "Current Location :  " << "x = " << item.__location._X << ",  y = " << item.__location._Y << endl;
        cout << "Energy left      :  " << item._energy_left << endl;
        cout << "Time left        :  " << item._time_left << endl;
        // cout << "What i see ?"
        cout << "The next move    :  " << item._next_move << endl;
        cout << "\t\t********************************** \n\n";
    }
}