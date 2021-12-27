#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Grab the pellets as fast as you can!
 **/

namespace ft_mine
{
    void ft_distance(int pellet[3], int pacs[][4], int pacs_size, unsigned long long *distance, int move[3])
    {
        int                 p;
        unsigned long long  d;
        unsigned long long  dm;
        unsigned long long  de;

        p = -1;
        dm = -1; 
        de = -1; 
        for (int i = 0; i < pacs_size; i++)
        {
           d = (pellet[0] - pacs[i][2]) * (pellet[0] - pacs[i][2]) + (pellet[1] - pacs[i][3]) * (pellet[1] - pacs[i][3]);
            if (pacs[i][1])
            {   
                if (d < dm)
                {   
                    dm = d;
                    p = pacs[i][0];
                }
            }
            else if (d < de)
                de = d;
        }
        if (dm < *distance)
        {
            *distance = dm;
            move[0] = p;
            move[1] = pellet[0];
            move[2] = pellet[1];
        }
    }
}


int main()
{
    int width;
    int height;

    int myScore;
    int opponentScore;
    int visiblePacCount;

    int pac_id;                 // pac number (unique within a team)
    bool mine;                  // true if this pac is yours
    int x;                      // position in the grid
    int y;                      // position in the grid
    int speed_turns_left;       // unused in wood leagues
    int ability_cooldown;       // unused in wood leagues

    int visiblePelletCount;

    cin >> width >> height; cin.ignore();

    string map[height];

    for (int i = 0; i < height; i++)
        getline(cin, map[i]);

    while (1)
    {
        cin >> myScore >> opponentScore; cin.ignore();
        cin >> visiblePacCount; cin.ignore();

        int pacs[visiblePacCount][4];           //0 : pacid || 1 : ismine || 2 : x || 3 : y

        for (int i = 0; i < visiblePacCount; i++)
        {
            string typeId; // unused in wood leagues
            cin >> pacs[i][0] >> pacs[i][1] >> pacs[i][2] >> pacs[i][3] >> typeId >> speed_turns_left >> ability_cooldown; cin.ignore();
        }
        cin >> visiblePelletCount; cin.ignore();

        int pellets[visiblePelletCount][3];     //0 : x || 1 : y || 2 : value

        int simple_move[visiblePacCount][3];
        int super_move[visiblePacCount][3];
        unsigned long long super_distances[visiblePacCount];
        unsigned long long simple_distances[visiblePacCount];

        for (int i = 0; i < visiblePacCount; i++)
        {
            super_distances[i] = -1;
            simple_distances[i] = -1;
        }
        for (int i = 0; i < visiblePelletCount; i++)
        {
            cin >> pellets[i][0] >> pellets[i][1] >> pellets[i][2]; cin.ignore();
            for (int j = 0; j < visiblePacCount; j++)
            {
                if (pellets[i][2] == 10)
                    ft_mine::ft_distance(pellets[i], pacs, visiblePacCount, super_distances + j, super_move[j]);
                else
                    ft_mine::ft_distance(pellets[i], pacs, visiblePacCount, simple_distances + j, simple_move[j]);
            }
        }
        for (int j = 0; j < visiblePacCount; j++)
        {
            if (super_distances[j] < simple_distances[j])
                cout << "MOVE " << super_move[j][0] << ' ' << super_move[j][1] << ' ' << super_move[j][2];
            else
                cout << "MOVE " << super_move[j][0] << ' ' << simple_move[j][1] << ' ' << simple_move[j][2];
            if (j < visiblePacCount - 1)
                cout << " | ";
            else
                cout << endl;
        }
    }
}

