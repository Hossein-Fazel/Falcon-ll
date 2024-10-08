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
    algo(); // --------------------------------------------------------------------------------------------------
}


void controller::ride(Space_Ship& ss, Map& my_map)
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

void controller::space_object(Space_Ship& ss , Map& my_map)
{
    if(ss._get_Location()._X + 1 < row and my_map.__get_main_map()[ss._get_Location()._X + 1][ss._get_Location()._Y] == 3)
    {
        ss._set_Location(ss._get_Location()._X + 3 , ss._get_Location()._Y );
        ss._set_energy(ss._get_energy() - 12);
        ss._set_time  (ss._get_time() + 9);
        return;
    } 

    if(ss._get_Location()._X - 1 >= 0 and my_map.__get_main_map()[ss._get_Location()._X - 1][ss._get_Location()._Y] == 3)
    {
        ss._set_Location(ss._get_Location()._X - 3 , ss._get_Location()._Y );
        ss._set_energy(ss._get_energy() - 12); 
        ss._set_time  (ss._get_time() + 9);
        return;
    } 

    if(ss._get_Location()._Y + 1 < column and my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y + 1] == 3)
    {
        ss._set_Location(ss._get_Location()._X , ss._get_Location()._Y + 3);
        ss._set_energy(ss._get_energy() - 12); 
        ss._set_time  (ss._get_time() + 9);
        return;
    } 

    if(ss._get_Location()._Y - 1 >= 0 and my_map.__get_main_map()[ss._get_Location()._X][ss._get_Location()._Y-1] == 3)
    {
        ss._set_Location(ss._get_Location()._X , ss._get_Location()._Y - 3);
        ss._set_energy(ss._get_energy() - 12); 
        ss._set_time  (ss._get_time() + 9);
        return;
    }
}

void controller::worm_hole(Space_Ship& ss , Map& my_map)
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
    if(curr_x < 0 or curr_x >= row or curr_y < 0 or curr_y >= column ) return -1;
    if(next_x < 0 or next_x >= row or next_y < 0 or next_y >= column ) return -1;
    
    if(curr_x == row -1 or curr_y == column - 1 or curr_x == 0 or curr_y == 0)
    {
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

bool controller::__visit_2_3_(int x , int y , vector<vector<int>>& map)
{
    return map[x][y] == 2 || map[x][y] == 3 ? true : false;  
}

bool controller::is_home(int& home_x, int& home_y)
{
    int x = space_ship._get_Location()._X;
    int y = space_ship._get_Location()._Y;

    this->space_map.set_info(x, y, this->visited_map);

    if(x + 1 < row and visited_map[x+1][y] == 5)
    {
        home_x = x + 1;
        home_y = y;
        return 1;
    }
        
    
    if(x - 1 >= 0 and visited_map[x-1][y] == 5)
    {
        home_x = x - 1;
        home_y = y;
        return 1;
    } 
    
    if(y + 1 < column and visited_map[x][y + 1] == 5)
    {
        home_x = x;
        home_y = y + 1;
        return 1;
    }
        
    
    if(y - 1 >= 0 and visited_map[x][y - 1] == 5)
    {
        home_x = x;
        home_y = y - 1;
        return 1;
    }
           
    if(y + 1 < column and x + 1 < row and visited_map[x + 1][y + 1] == 5)
    {
        home_x = x + 1;
        home_y = y + 1;
        return 1;
    }
    
    if(x - 1 >= 0 and y - 1 >= 0 and visited_map[x - 1][y - 1] == 5)
    {
        home_x = x - 1;
        home_y = y - 1;
        return 1;
    }
        
    if(x - 1 >= 0 and y + 1 < column and visited_map[x - 1][y + 1] == 5)
    {
        home_x = x - 1;
        home_y = y + 1;
        return 1;
    }

    if(x + 1 < row and y - 1 >= 0 and visited_map[x + 1][y - 1] == 5)
    {
        home_x = x + 1;
        home_y = y - 1;
        return 1;
    }

    return 0; 
}


void controller::algo()
{
    int home_x= -1 , home_y = -1;
    bool is_first = true;
    while(!is_home(home_x, home_y))
    {
        bool flag_do_action {false};

        this->space_map.set_info(space_ship._get_Location()._X, space_ship._get_Location()._Y, visited_map);
        this->space_map.print(space_ship._get_Location()._X, space_ship._get_Location()._Y);

        vector<view_point> points = get_view_points();

        // normal move
        for(auto i : points)
        {
            if(!(logs._find_loc(i.location._X, i.location._Y)) && !(__visit_2_3_(i.location._X , i.location._Y , visited_map)))
            {
                string move = "move to x : " + to_string(i.location._X) + ", y : " + to_string(i.location._Y);
                logs.add(Location{space_ship._get_Location()._X, space_ship._get_Location()._Y}, move, space_ship._get_energy(), space_ship._get_time());
                
                space_ship._move(i.location._X - space_ship._get_Location()._X, i.location._Y - space_ship._get_Location()._Y);
                flag_do_action = true;
                is_first = true;
                break;
            }
        }

        // use objects
        if (!flag_do_action)
        {
            if (visited_map[this->space_ship._get_Location()._X][this->space_ship._get_Location()._Y] == 4 and logs.check_last("use wormhole") == false)
            {
                string move = "use wormhole";
                logs.add(Location{space_ship._get_Location()._X, space_ship._get_Location()._Y}, move, space_ship._get_energy(), space_ship._get_time());

                worm_hole(this->space_ship , this->space_map);
                flag_do_action = true;
                is_first = true;
            }

            else if (visited_map[this->space_ship._get_Location()._X][this->space_ship._get_Location()._Y] == 1 and logs.check_last("use space current") == false)
            {
                string move = "use space current";
                logs.add(Location{space_ship._get_Location()._X, space_ship._get_Location()._Y}, move, space_ship._get_energy(), space_ship._get_time());
                
                ride(this->space_ship , this->space_map);
                flag_do_action = true;
                is_first = true;
            }

            else if(logs.check_last("use space object") == false)
            {
                int temp_x = space_ship._get_Location()._X;
                int temp_y = space_ship._get_Location()._Y;

                space_object(this->space_ship , this->space_map);
                
                if(temp_x != space_ship._get_Location()._X or temp_y != space_ship._get_Location()._Y)
                {
                    string move = "use space object";
                    logs.add(Location{temp_x, temp_y}, move, space_ship._get_energy(), space_ship._get_time());
                    flag_do_action = true;
                    is_first = true;
                }
            }
        }

        // random move
        if (!flag_do_action)
        {
            while(1)
            {
                // cout << "t1";
                srand(time(0));
                view_point vp;
                try
                {
                    vp = points[rand() % points.size()];
                }
                catch(const std::exception& e)
                {
                    cout << "shittttt...";
                    exit(0);
                }
                

                bool check;
                if(is_first) check = !(__visit_2_3_(vp.location._X , vp.location._Y , visited_map));
                else check = !(__visit_2_3_(vp.location._X , vp.location._Y , visited_map)) and !logs.check_last(vp.location._X , vp.location._Y);

                if(check)
                {
                    string move = "move to x : " + to_string(vp.location._X) + ", y : " + to_string(vp.location._Y);
                    logs.add(Location{space_ship._get_Location()._X, space_ship._get_Location()._Y}, move, space_ship._get_energy(), space_ship._get_time());
                    
                    space_ship._move(vp.location._X - space_ship._get_Location()._X, vp.location._Y - space_ship._get_Location()._Y);
                    flag_do_action = true;
                    is_first = false;
                    break;
                }
            }
        }
        _SLEEP(1);
    }

    string move = "move to home x : " + to_string(home_x) + ", y : " + to_string(home_y);
    logs.add(Location{space_ship._get_Location()._X, space_ship._get_Location()._Y}, move, space_ship._get_energy(), space_ship._get_time());

    int temp = abs(home_x - space_ship._get_Location()._X) + abs(home_y - space_ship._get_Location()._Y);
    space_ship._set_Location(home_x, home_y);
    space_ship._set_energy(space_ship._get_energy() - temp);
    space_ship._set_time(space_ship._get_time() + temp);

    logs.print();
}