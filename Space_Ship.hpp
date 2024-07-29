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
   int _energy;
   int _time;

public:
    Space_Ship(int x , int y , int energy , int time);

    void _set_Location(int x , int y);
    void _set_energy(int energy);
    void _set_time(int time);

    Locatin  _get_Location();
    int _get_energy();
    int _get_time();


    void _move(int up , int right , int down , int left);

};

#endif
