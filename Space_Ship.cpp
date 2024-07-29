#include "Space_Ship.hpp"


Space_Ship::Space_Ship(int x , int y , int energy , int time)
{
    this->_set_Location(x,y);
    this->_set_energy(energy);
    this->_set_time(time);
}

void Space_Ship::_set_Location(int x , int y)
{
    this->_locatin._X = x;
    this->_locatin._Y = y;
}
void Space_Ship::_set_energy(int energy)
{
    this->_energy = energy;
}
void Space_Ship::_set_time(int time)
{
    this->_time = time;
}


Locatin Space_Ship::_get_Location()
{
    return this->_locatin;
}
int Space_Ship::_get_energy()
{
    return this->_energy;
}
int Space_Ship::_get_time()
{
    return this->_time;
}


void Space_Ship::_move(int up , int right , int down , int left)
{
    this->_locatin._X += (right - left);
    this->_locatin._Y += (up - down); 
}
