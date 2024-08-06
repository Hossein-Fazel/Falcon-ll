#include "Log.hpp"


log_system::log_system()
{
}

bool log_system::_find_loc(int x , int y)
{
    for (int i{0} ; i < logs.size() ; ++i)
    {
        if (logs[i].__location._X == x && logs[i].__location._Y == y ) return true;
    }
    return false;

}

void log_system::add(Location loc, string move, int energy, int time)
{
    SaveThings temp;
    temp.__location = loc;
    temp._next_move = move;
    temp._elapsed_time = time;
    temp._energy_left = energy;

    this->logs.push_back(temp);
}

void log_system::print()
{
    for(const auto item : this->logs)
    {
        cout << "Current Location :  " << "x = " << item.__location._X << ",  y = " << item.__location._Y << endl;
        cout << "Energy left      :  " << item._energy_left << endl;
        cout << "Elapsed time     :  " << item._elapsed_time << endl;
        // cout << "What i see ?"
        cout << "The next move    :  " << item._next_move << endl;
        cout << "\t\t ______________________________________ \n\n";
    }
}