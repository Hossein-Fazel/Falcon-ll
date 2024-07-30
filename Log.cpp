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
        cout << "Current Location : " << item.__location._X << "  " << item.__location._Y << endl;
        // cout << "What i see ?"
        cout << "The next move : " << item._next_move << endl;
        cout << "\t\t********************************** \n\n";
    }
}