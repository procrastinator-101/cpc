#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define NEXT(x)	(x < 3 ? x + 1 : 0)
#define PREV(x) (x > 0 ? x - 1 : 3)

/**
 * Grab the pellets as fast as you can!
 **/


int turn;
int width;
int height;

int max_depth;

int free_pac;

int action[5][2];			//index 0 (0 : speed || 1 : switch) || index 1 (0 : ROCK || 1 :SCISSORS || 2 : PAPER
int last_move[5];		    //0 : leftup || 1 : up || 2 : rightup || 3 : right || 4 : rightdown || 5 : down || 6 : leftdown || 7 : left
int move_pac[5][2];			//0 : x || 1 : y
int shit_moves[5];
int border[][2] = {-1,0,0,-1,1,0,0,1};

set <int> pellets;

namespace ft_mine
{
	int is_enemy_stronger(int m, int e)
	{
		if (!e && m == 2)
			return (0);
		if (!m && e == 2)
			return (1);
		return (m >= e);
	}
	//get the point p inside the grid in case of tunnels
	void get_pinside(int p[2])
	{
		if (p[0] == width)
			p[0] = 0;
		else if (p[0] == -1)
			p[0] += width;
	}

	int check_position(int map[][35], int p[2], int mypacs[][5], int epacs[][5], int id)
	{
		int r;
		int temp;

		get_pinside(p);
		r = map[p[1]][p[0]];
		if (r == 35)                                                        //wall
			return (-2);
		if (r == 100 + turn)                                                //pellet of value 1
			return (2);
		if (r > 1000 && r < 2000)                                                //pellet of value 10
			return (10);
		if (r > 100 && r < 900)
			return (1);
		temp = 10000 + turn * 10;
		if (r >= temp && r < temp  + 5)                                     //friend pac
			return (-3);
		temp = 20000 + turn * 10;
		if (r >= temp && r < temp + 5)						                //an enemy pac
		{
			r -= temp;
			if (is_enemy_stronger(mypacs[id][2], epacs[r][2]))                  //the enemy is stronger
			{
				if (epacs[r][4])				                                    //the enemy can't morph
					return (mypacs[id][4] ? -8 : -5);	                                //-8 : i can't morph || -5 : i can morph
				else						                                        //the enemy can morph
					return (mypacs[id][4] ? -9 : -7);	                                //-9 : i can't morph || -7 : i can morph
			}
			else							                                    //the enemy is weaker
			{
				if (epacs[r][4])				                                    //the enemy can't morph
					return (mypacs[id][4] ? -1 : 2);	                                //-3 : i can't morph || 1 : i can morph
				else						                                        //the enemy can morph
					return (mypacs[id][4] ? -4 : -6);	                                //-4 : i can't morph || -6 : i can morph
			}
		}
		return (0);
	}

	int check_nsquare(int map[][35], int mypacs[][5], int epacs[][5], int id, int p1[2], int s, int depth)
	{
		int r;
		int rn;
		int rmin; 
		int p[2];

		if (depth == max_depth)
			return (0);
		rmin = -10;
		for (int i = 0; i < 3; i++, s = NEXT(s))
		{
			p[0] = p1[0] + border[s][0];
			p[1] = p1[1] + border[s][1];
			r = check_position(map, p, mypacs, epacs, id);
			if (r < -7 && depth < 5)
				return (r);
			if (r < -3)
			{
				if (depth == 4)
					return (-4);
				else if (depth < 4)
					return (r);
			}
			if (r < -1)
				r = -1;
			if (r > -2)
			{
				r *= max_depth - depth;
				rn = check_nsquare(map, mypacs, epacs, id, p, PREV(s), depth + 1);
				if (rn < -7)
					return (rn);
				r += rn;
			}
			if (r > rmin)                                             
				rmin = r;
		}
		return (rmin);
	}

	int check_second_square(int map[][35], int mypacs[][5], int epacs[][5], int id, int p1[2], int p2[2], int s, int *lm)
	{
		int r;
		int rn;
		int rmin;
		int temp;
		int p[2];

		rmin = -10;
		for (int i = 0; i < 3; i++, s = NEXT(s))
		{
			p[0] = p1[0] + border[s][0];
			p[1] = p1[1] + border[s][1];
			r = check_position(map, p, mypacs, epacs, id);
			if (r < -3)
			{
				if (r == -5)
				{
					p2[0] = p[0];
					p2[1] = p[1];
				}
				return (r);
			}
			if (r > -2)
			{
				r *= max_depth - 2;
				rn = check_nsquare(map, mypacs, epacs, id, p, PREV(s), 3);
				if (rn < -7)
					return (rn);
				r += rn;
			}
			if (r > rmin)                                             
			{
				p2[0] = p[0];
				p2[1] = p[1];
				rmin = r;
				*lm = s;
			}     
		}
		return (rmin);
	}

	void ft_play(int map[][35], int mypacs[][5], int epacs[][5], int id)
	{
		int s;
		int r;
		int lm;
		int sq1;
		int sq2;
		int temp;
		int p1[2];
		int p2[2];
		int move_to_eat[2][2];

		r = -1;
		move_to_eat[0][0] = -1;
		s = last_move[id];
		for (int i = 0; i < 4; i++, s = NEXT(s))
		{
			p1[0] = mypacs[id][0] + border[s][0];
			p1[1] = mypacs[id][1] + border[s][1];
			sq1 = check_position(map, p1, mypacs, epacs, id);


			if (sq1 > -1)                                 //eat or just run
			{
				sq1 *= max_depth - 1;
				sq2 = check_second_square(map, mypacs, epacs, id, p1, p2, PREV(s), &temp);
				if (sq2 < -7)
					continue ;
				if (sq2 == -5)
				{
					int en;

					en = map[p2[1]][p2[0]] - 20000 - turn * 10;
					action[id][0] = 1;
					action[id][0] = epacs[en][2] ? epacs[en][2] - 1 : 2;
					return ;
				}
				if (sq1 + sq2 > r)
				{
					if (sq2 < -1)
						p2[0] = -1;  
					lm = temp;
					move_to_eat[0][0] = p1[0];
					move_to_eat[0][1] = p1[1];
					move_to_eat[1][0] = p2[0];
					move_to_eat[1][1] = p2[1];
					r = sq1 + sq2;  
				}
			}
			else if (sq1 == -5)                                       //get stronger
			{
				int en;

				en = map[p1[1]][p1[0]] - 20000 - turn * 10;
				action[id][0] = 1;
				action[id][0] = epacs[en][2] ? epacs[en][2] - 1 : 2;
				return ;
			}
		}
		if (action[id][0] == -1 && !mypacs[id][4] && move_to_eat[1][0] != -1)                             //should i speed up
		{
			action[id][0] = 0;
			return ;
		}
		if (move_to_eat[0][0] != -1)
		{
			if (move_to_eat[1][0] != -1)
			{
				move_pac[id][0] = move_to_eat[1][0];
				move_pac[id][1] = move_to_eat[1][1];
			}
			else
			{
				move_pac[id][0] = move_to_eat[0][0];
				move_pac[id][1] = move_to_eat[0][1]; 
			}
			map[move_to_eat[0][1]][move_to_eat[0][0]] = 10000 + turn * 10 + id;
			map[mypacs[id][1]][mypacs[id][0]] *= -1;
			last_move[id] = lm;
		}
	}
}

int main()
{
	int myScore;
	int opponentScore;
	int visiblePacCount;
	int visiblePelletCount;

	int x;
	int y;
	int value;

	int id;
	int mine;

	string forms[4];

	forms[0] = "ROCK";
	forms[1] = "SCISSORS";
	forms[2] = "PAPER";
	forms[3] = "DEAD";

	int mypacs[5][5];           //0 : x || 1 : y || 2 : type || 3 : speed_turns_left || 4 : cooldown
	int epacs[5][5];            //same as mypacs

	for (int i = 0; i < 5; i++)
		last_move[i] = 0;

	turn = 1;
	max_depth = 6;

	cin >> width >> height; cin.ignore();

	int map[17][35];

	for (int i = 0; i < height; i++)
	{
		string row;
		getline(cin, row);
		for (int j = 0; j < width; j++)
			map[i][j] = row[j];
	}

	while (1)
	{
		for (int i = 0; i < 5; i++)
		{
			mypacs[i][0] = -1;
			action[i][0] = -1;
			move_pac[i][0] = -1;
		}

		cin >> myScore >> opponentScore; cin.ignore();
		cin >> visiblePacCount; cin.ignore();

		for (int i = 0, j; i < visiblePacCount; i++)
		{
			string typeId;
			cin >> id >> mine;
			if (mine)
			{
				cin >> mypacs[id][0] >> mypacs[id][1] >> typeId >> mypacs[id][3] >> mypacs[id][4];cin.ignore();
				for (j = 0; j < 4 && typeId.compare(forms[j]); j++);
				mypacs[id][2] = j;
				if (j < 3)
					map[mypacs[id][1]][mypacs[id][0]] = id + turn * 10 + 10000;
				else
					mypacs[id][0] = -1;
			}
			else
			{
				cin >> epacs[id][0] >> epacs[id][1] >> typeId >> epacs[id][3] >> epacs[id][4];cin.ignore();
				for (j = 0; j < 4 && typeId.compare(forms[j]); j++);
				epacs[id][2] = j;
				if (j < 3)
					map[epacs[id][1]][epacs[id][0]] = id + turn * 10 + 20000;
				else
					epacs[id][0] = -1;
			}
		}
		cin >> visiblePelletCount; cin.ignore();

		//geting the pellets into the map
		for (int i = 0; i < visiblePelletCount; i++)
		{
			cin >> x >> y >> value; cin.ignore();
			map[y][x] = turn + (value == 10 ? 1000 : 100);
		}

		//map for debuguing purpose
		for (int j = 0; j < width; j++)
			cerr << j << '\t';
		cerr << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cerr << map[i][j] << '\t';
			cerr << endl;
		}

		for (int i = 0; i < 5; i++)
			if (mypacs[i][0] != -1)
				ft_mine::ft_play(map, mypacs, epacs, i);

		int p = 0;
		for (int i = 0; i < 5; i++)
		{
			if (mypacs[i][0] == -1)
				continue ;
			if (p)
				cout << " | ";
			if (action[i][0] > -1)
			{
				if (action[i][0])
					cout << "SWITCH " << i << ' ' << forms[action[i][1]];
				else
					cout << "SPEED " << i;
			}
			else if (move_pac[i][0] != -1)
				cout << "MOVE " << i << ' ' << move_pac[i][0] << ' ' << move_pac[i][1];
			p++;
		}
		cout << endl;
		turn++;
	}
}

