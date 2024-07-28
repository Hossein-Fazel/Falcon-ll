#ifndef SPACE_SHIP_HPP
#define SPACE_SHIP_HPP

struct Locatin
{
    int _X;
    int _Y;
};

class Space_Ship
{
private:

   Locatin _locatin;

public:
    Space_Ship(/* args */);

    void _set_Location(int x , int y);
    Locatin  _get_Location();

    void _move(int up , int right , int down , int left);

};

#endif