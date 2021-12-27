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
    void ft_distance(int pac[4], int pellets[][3], int visiblePelletCount, int move[3])
    {
        unsigned long long  d;
        unsigned long long  dis;

        dis = -1;
        for (int i = 0; i < visiblePelletCount; i++)
        {
            d = (pellets[i][0] - pac[2]) * (pellets[i][0] - pac[2]) + (pellets[i][1] - pac[3]) * (pellets[i][1] - pac[3]);
            if (d < dis)
            {   
                dis = d;
                move[1] = pellets[i][0];
                move[2] = pellets[i][1];
            }
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

        int move[visiblePacCount][3];
        for (int i = 0; i < visiblePacCount; i++)
            move[i][0] = pacs[i][0];
        for (int i = 0; i < visiblePelletCount; i++)
            cin >> pellets[i][0] >> pellets[i][1] >> pellets[i][2]; cin.ignore();
        for (int j = 0; j < visiblePacCount; j++)
            if (pacs[j][1])
                ft_mine::ft_distance(pacs[j], pellets, visiblePelletCount, move[j]);
        int p = 0;
        for (int j = 0; j < visiblePacCount; j++)
        {
            if (!pacs[j][1])
                continue ;
            if (p)
                cout << " | ";
            cout << "MOVE " << move[j][0] << ' ' << move[j][1] << ' ' << move[j][2];
            p++;
        }
        cout << endl;
    }
}


