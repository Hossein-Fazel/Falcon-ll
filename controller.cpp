#include "controller.hpp"


void controller::run()
{
    cin >> row >> column;
    space_map.resize(row, column);
    visited_map.assign(row , vector<int>(column , 0));

    cin >> spaceShip_x >> spaceShip_y >> energy;
    space_ship._set_Location(spaceShip_x, spaceShip_y);
    space_ship._set_time(0);
    space_ship._set_energy(energy);

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            int cell_data; cin >> cell_data;
            space_map.set_data(i, j, cell_data);
        }
    }
}


void controller::ride(Space_Ship ss, Map my_map)
{
    space_current sc = my_map.detect_sc(ss._get_Location()._X , ss._get_Location()._Y);

    if(sc.cell_counter != -1)
    {
        int energy_consumption = sc.cell_counter * 2;
        int time_spent = sc.cell_counter;
        ss._set_Location(sc.end_point._X, sc.end_point._Y);
        ss._set_energy(ss._get_energy() - energy_consumption);
        ss._set_time(ss._get_time() + time_spent);
    }
}

void controller::space_object(Space_Ship ss , Map my_map)
{
    if(my_map.__get_main_map()[ss._get_Location()._X + 1][ss._get_Location()._Y] == 3)
    {
        ss._set_Location(ss._get_Location()._X + 3 , ss._get_Location()._Y );
        ss._set_energy(ss._get_energy() - 12);
        ss._set_time  (ss._get_time() + 9);
        return;
    } 

    if(my_map.__get_main_map()[ss._get_Location()._X - 1][ss._get_Location()._Y] == 3)
    {
        ss._set_Location(ss._get_Location()._X - 3 , ss._get_Location()._Y );
        ss._set_energy(ss._get_energy() - 12); 
        ss._set_time  (ss._get_time() + 9);
        return;
    } 

    if(my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y + 1] == 3)
    {
        ss._set_Location(ss._get_Location()._X , ss._get_Location()._Y - 3);
        ss._set_energy(ss._get_energy() - 12); 
        ss._set_time  (ss._get_time() + 9);
        return;
    } 

    if(my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y-1] == 3)
    {
        ss._set_Location(ss._get_Location()._X , ss._get_Location()._Y +3);
        ss._set_energy(ss._get_energy() - 12); 
        ss._set_time  (ss._get_time() + 9);
        return;
    }
}

void controller::worm_hole(Space_Ship ss , Map my_map)
{
    if (my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y] == 4)
    {
        for (int i{0} ; i < my_map._get_row() ;i++ )
        {
            for (int j{0} ; j < my_map._get_column() ;j++ )
            {
                if (my_map.__get_main_map()[i][j] == 4 && j != ss._get_Location()._Y && i != ss._get_Location()._X )
                {
                    ss._set_Location(i,j);
                    ss._set_energy(ss._get_energy() / 2);
                    return;
                }
            }
        }
    }
}

int controller::get_visible_new_cells(int curr_x, int curr_y, int next_x, int next_y)
{
    if(curr_x == row -1 or curr_y == column - 1 or curr_x == 0 or curr_y == 0)
    {
        cout << "t1\n";
        // corners :
        if(next_x == 0 and next_y == 0)
            return 0;
        
        if(next_x == row - 1 and next_y == 0)
            return 0;
        
        if(next_x == 0 and next_y == column - 1)
            return 0;

        if(next_x == row - 1 and next_y == column - 1)
            return 0;

        // edges : 
        if(next_x == row - 1 or next_y == column - 1)
            return 2;
        if(next_x == 0 or next_y == 0)
            return 2;
        
        //middle :
        if(next_x > 0 and next_x < row - 1 and next_y > 0 and next_y < column - 1)
            return 3;
    }

    else if(curr_x > 0 and curr_x < row - 1 and curr_y > 0 and curr_y < column - 1)
    {
        // edges :
        if(next_x == row -1 or next_y == column - 1)
            return 0;
        if(next_x == 0 or next_y == 0)
            return 0;
        
        // middle :
        if(next_x > 0 and next_x < row - 1 and next_y > 0 and next_y < column - 1)
            return 3;
    }

    return -1;
}

vector<view_point> controller::get_view_points()
{
    int x = space_ship._get_Location()._X;
    int y = space_ship._get_Location()._Y;

    vector<view_point> points;

    int temp {};

    temp = get_visible_new_cells(x, y, x + 1, y);
    if(temp != -1) points.push_back(view_point{Location{x+1, y}, temp});

    temp = get_visible_new_cells(x, y, x - 1, y);
    if(temp != -1) points.push_back(view_point{Location{x-1, y}, temp});

    temp = get_visible_new_cells(x, y, x, y + 1);
    if(temp != -1) points.push_back(view_point{Location{x, y+1}, temp});

    temp = get_visible_new_cells(x, y, x, y - 1);
    if(temp != -1) points.push_back(view_point{Location{x, y-1}, temp});

    sort(points.begin(), points.end());

    return points;
}