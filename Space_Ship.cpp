#include "Space_Ship.hpp"


Space_Ship::Space_Ship(/* args */)
{
}

void Space_Ship::_set_Location(int x , int y)
{
    this->_locatin._X = x;
    this->_locatin._Y = y;
}

Locatin  Space_Ship::_get_Location()
{
    return this->_locatin;
}


void Space_Ship::_move(int up , int right , int down , int left)
{
    this->_locatin._X += (right - left);
    this->_locatin._Y += (up - down); 
}
