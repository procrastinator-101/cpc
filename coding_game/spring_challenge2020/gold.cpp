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

typedef struct s_check
{
	unsigned int id0:1;
	unsigned int id1:1;
	unsigned int id2:1;
	unsigned int id3:1;
	unsigned int id4:1;
	unsigned int en:1;
}           t_check;


int turn;
int width;
int height;

int max_depth = 15;
int pellet_point = 4;
int super_pellet_point = 200;
int min_points = -2000000;



int action[5][2];			//index 0 (0 : speed || 1 : switch) || index 1 (0 : ROCK || 1 :SCISSORS || 2 : PAPER)
int last_move[5];		    //0 : left || 1 : up || 2 : right || 3 : down
int move_pac[5][2];			//0 : x || 1 : y

int morph[5][3];            //0 : action id || 1 : depth || 2 : r
int move_by_one[5][3];      //0 : should i move by one || 1 : depth || 2 : r

int border[][2] = {-1,0,0,-1,1,0,0,1};
int offset[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
long long super_pellet_offset[] = {65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456, 536870912,1073741824,2147483648,4294967296};

vector <int> super_pellets;
vector <int> closest_pac;

t_check explored[17][35];

namespace ft_mine
{
	int is_enemy_stronger(int m, int e)
	{
		if (!e && m == 2)
			return (-1);
		if (!m && e == 2)
			return (1);
		if (m == e)
			return (0);
		return (m > e ? 1 : -1);
	}
	//get the point p inside the grid in case of tunnels
	void get_pinside(int p[2])
	{
		if (p[0] == width)
			p[0] = 0;
		else if (p[0] == -1)
			p[0] += width;
	}

	void dead_pellets_elimination(int map[][35], int px, int py)
	{
		int i;
		int x;
		int y;
		int val;

		x = px;
		y = py;
		val = map[y][x];
		for (i = 0; val != 35 && i < width; x = x < width - 1 ? x + 1 : x = 0, val = map[y][x], i++)                   //right check
		{
			if (val >= 100 && val < 900 && val != 100 + turn)       //pellet of value 1
				map[y][x] = 0;
			if (val >= 1000 && val < 2000 && val != 1000 + turn)
				map[y][x] = 0;
			if (val == 32 || (val >= 20000 && val < 29000))
				explored[y][x].en = 1;
		}
		x = px;
		val = map[y][x];
		for (i = 0; val != 35 && i < width; x = x > 0 ? x - 1 : width - 1, val = map[y][x], i++)                   //left check
		{
			if (val >= 100 && val < 900 && val != 100 + turn)       //pellet of value 1
				map[y][x] = 0;
			if (val >= 1000 && val < 2000 && val != 1000 + turn)    //pellet of value 10
				map[y][x] = 0;
			if (val == 32 || (val >= 20000 && val < 29000))
				explored[y][x].en = 1;
		}
		x = px;
		val = map[y][x];
		for (i = 0; val != 35 && i < height; y = y > 0 ? y - 1 : height - 1, val = map[y][x], i++)                   //up check
		{
			if (val >= 100 && val < 900 && val != 100 + turn)       //pellet of value 1
				map[y][x] = 0;
			if (val >= 1000 && val < 2000 && val != 1000 + turn)
				map[y][x] = 0;
			if (val == 32 || (val >= 20000 && val < 29000))
				explored[y][x].en = 1;
		}
		y = py;
		val = map[y][x];
		for (; val != 35 && i < height; y = y < height - 1 ? y + 1 : y = 0, val = map[y][x], i++)                   //down check
		{
			if (val >= 100 && val < 900 && val != 100 + turn)       //pellet of value 1
				map[y][x] = 0;
			if (val >= 1000 && val < 2000 && val != 1000 + turn)
				map[y][x] = 0;
			if (val == 32 || (val >= 20000 && val < 29000))
				explored[y][x].en = 1;
		}
	}

	int check_explored(int x, int y, int id)
	{
		if (id == 0)
			return (explored[y][x].id0);
		if (id == 1)
			return (explored[y][x].id1);
		if (id == 2)
			return (explored[y][x].id2);
		if (id == 3)
			return (explored[y][x].id3);
		if (id == 4)
			return (explored[y][x].id4);
		return (0);
	}

	void update_explored(int x, int y, int id, bool type)
	{
		if (!type)
			explored[y][x].en = 1;
		else
		{
			if (id == 0)
				explored[y][x].id0 = 1;
			else if (id == 1)
				explored[y][x].id1 = 1;
			else if (id == 2)
				explored[y][x].id2 = 1;
			else if (id == 3)
				explored[y][x].id3 = 1;
			else if (id == 4)
				explored[y][x].id4 = 1;
		}
	}

	int forward_morph(int e)
	{
		if (e > 0)
			return (e - 1);
		return (2);
	}

	void update_morph(int depth, int id, int r, int val)
	{
		if (depth <= morph[id][1] && r < morph[id][2])
		{
			morph[id][0] = val;
			morph[id][1] = depth;
			morph[id][2] = r;
		}
	}

	void update_move_by_one(int depth, int id, int r)
	{
		if (depth <= move_by_one[id][1] && r < move_by_one[id][2])
		{
			move_by_one[id][0] = 1;
			move_by_one[id][1] = depth;
			move_by_one[id][2] = r;
		}
	}

	int is_it_closest_pac(int id, int x, int y)
	{
		int val;

		val = y * 100 + x;
		for (int i = 0; i < super_pellets.size(); i++)
		{
			if (val == super_pellets[i])
			{
				if (closest_pac[i] == id)
					return (1);
				return (0);
			}
		}
		return (0);
	}

	int check_position(int map[][35], int p[2], int mypacs[][5], int epacs[][5], int id, int *en_id)
	{
		int r;
		int temp;

		get_pinside(p);
		r = map[p[1]][p[0]];
		if (r == 35)                                                        //wall
			return (-4);
		if (r == 100 + turn)                                                //pellet of value 1
			return (pellet_point);
		if (r > 1000 && r < 2000)                                                //pellet of value 10
			return (super_pellet_point);
		if (r > 100 && r < 900)												//an old pellet of value 1
			return (pellet_point - 2);
		temp = 10000 + turn * 10;
		if (r >= temp && r < temp  + 5)                                     //friend pac
			return (-5);
		temp = 20000 + turn * 10;
		if (r >= temp && r < temp + 5)						                //an enemy pac
		{
			r -= temp;
			*en_id = r;
			if (is_enemy_stronger(mypacs[id][2], epacs[r][2]) == 1)                      //the enemy is stronger
			{
				if (epacs[r][4])				                                        //the enemy can't morph
				{
					if (mypacs[id][4])														//i can't morph
					{
						if (mypacs[id][3])														//i am on speed mode
							return (min_points + (epacs[r][3] ? 3 : 5));							//the enemy is : 3 on speed mode || 5 not on speed mode
						else																//i am not on speed mode
							return (min_points + (epacs[r][3] ? 0 : 1));									//the enemy is : 0 on speed mode || 1 not on speed mode
					}
					else																	//i can morph
						return (min_points + (epacs[r][3] ? 20 : 21));							//the enemy is : 20 on speed mode || 21 not on speed mode
				}
				else						                                            //the enemy can morph
				{
					if (mypacs[id][4])														//i can't morph
						return (min_points + (mypacs[id][3] ? 4 : 2));							//i am : 4 on speed mode || 2 not speed mode
					return (min_points + 22);												//i can morph
				}
			}
			else if (is_enemy_stronger(mypacs[id][2], epacs[r][2]) == -1)				//the enemy is weaker
			{
				if (epacs[r][4])														//the enemy can't morph
				{
					if (mypacs[id][4])														//i can't morph
					{
						if (mypacs[id][3])														//i am on speed mode
							return (pellet_point + (epacs[r][3] ? -2 : 1));							//the enemy is : -2 on speed mode || 1 not on speed mode
						else																//i am not on speed mode
							return (pellet_point + (epacs[r][3] ? -3 : -2));						//the enemy is : -3 on speed mode || -2 not on speed mode
					}
					else																	//i can morph
						return (pellet_point);
				}
				else																	//the enemy can morph
				{
					if (mypacs[id][4])														//i can't morph
						return (min_points + (mypacs[id][3] ? 6 : 5));							//i am : 6 on speed mode || 5 not on speed mode
					return (min_points + 23);												//i can morph
				}
			}
			else																		//the enemy and i have the same strength
			{
				if (epacs[r][4])															//the enemy can't morph
				{
					if (mypacs[id][4])															//i can't morph
						return (min_points + 10);
					return (min_points + (epacs[r][3] ? 25 : 26));								//i can morph : the enemy is : 25 on speed mode || 26 not on speed mode
				}
				else																		//the enemy can morph
				{
					if (mypacs[id][4])															//i can't morph
						return (min_points + (mypacs[id][3] ? 8 : 7));								//i am : 4 on speed mode || 2 not on speed mode
					return (min_points + 24);													//i can morph
				}
			}
		}
		if (check_explored(p[0], p[1], id))
			return (-3);
		for (temp = 0; temp < 5; temp++)
			if (temp != id)
				if (check_explored(p[0], p[1], temp))
					return (-2);
		if (explored[p[1]][p[0]].en)
			return (-1);
		return (0);
	}

#define ID 3
	long long check_nsquare(int map[][35], int mypacs[][5], int epacs[][5], int id, int p1[2], int s, int depth)
	{
		int p[2];
		int en_id;
		long long r;
		long long rn;
		long long rmin;

		if (depth == max_depth)
			return (0);
		rmin = min_points - 10;
		for (int i = 0; i < 3; i++, s = NEXT(s))
		{
			p[0] = p1[0] + border[s][0];
			p[1] = p1[1] + border[s][1];
			r = check_position(map, p, mypacs, epacs, id, &en_id);
			if (id == ID && depth < 6) cerr << " x = " << p[0] << " y = " << p[1] << "\tr = " << r << "\tdepth = " << depth << endl;
			if (r == min_points)                        //the enemy is too close that it can kill if move towards it
			{
				if (depth == 4 && mypacs[id][4] > 1)
					return (r);
				if (depth == 5 && (mypacs[id][4] > 2 && epacs[en_id][3] > 1))
					return (r);
				if (depth == 3)
					return (r);
			}
			if (r == min_points + 1 && mypacs[id][4] > 1 && depth == 3)   //the enemy is tooo close that it can kill if move towards it
				return (r);
			if (r == min_points + 2)
			{
				if (depth == 3)
					return (r);
				if (mypacs[id][4] > 1 && depth == 4)
					return (r);
			}
			if (r == min_points + 3)
			{
				if (depth == 6 && epacs[en_id][3] < mypacs[id][3])
				{
					update_move_by_one(depth, id, r);
					return (r);
				}
				if (depth == 5 && epacs[en_id][3] <= mypacs[id][3])
				{
					update_move_by_one(depth, id, r);
					return (r);
				}
				if (depth < 5)
					return (r);
			}
			if (r == min_points + 4 && mypacs[id][3] < 4 && depth == 4)
			{
				update_move_by_one(depth, id, r);
				return (r);
			}
			if (r == min_points + 6 && depth == 3)
			{
				update_move_by_one(depth, id, r);
				return (r);
			}

			if ((r == min_points + 22 || r == min_points + 23) && depth < 6)
			{
				update_morph(depth, id, r, -1);
				return (r);
			}
			if (r == min_points + 20 && depth < 6)
			{
				update_morph(depth, id, r, -1);
				return (r);
			}
			if (r == min_points + 21)
			{
				if (epacs[en_id][4] == depth)
					update_morph(depth, id, r, -1);
				if (depth < 5)
					return (r);
			}
			if (r == min_points + 25 && depth < 6)
			{
				update_morph(depth, id, r, forward_morph(epacs[en_id][2]));
				return (r);
			}
			if (r == min_points + 26 && epacs[en_id][4] < depth && depth < 4)
			{
				update_morph(depth, id, r, -1);
				return (r);
			}
			if (r == min_points + 24 && depth < 5)
			{
				update_morph(depth, id, r, -1);
				return (r);
			}

			if (r > -4)
			{
				if (r == super_pellet_point && is_it_closest_pac(id, p[0], p[1]))
					r += super_pellet_offset[max_depth - depth];
				else if (r > 0)
					r += offset[max_depth - depth];
				rn = check_nsquare(map, mypacs, epacs, id, p, PREV(s), depth + 1);
				if (rn < min_points + 30)
					return (rn);
				r += rn;
			}
			else if (r < min_points + 30 && depth > 5)
				r = -1 * (max_depth - depth);
			if (r > rmin)
				rmin = r;
		}
		return (rmin);
	}

	long long check_second_square(int map[][35], int mypacs[][5], int epacs[][5], int id, int p1[2], int p2[2], int s, int *lm)
	{
		int p[2];
		int en_id;
		long long r;
		long long rn;
		long long rmin;

		rmin = min_points - 10;
		for (int i = 0; i < 3; i++, s = NEXT(s))
		{
			p[0] = p1[0] + border[s][0];
			p[1] = p1[1] + border[s][1];
			r = check_position(map, p, mypacs, epacs, id, &en_id);

			if (id == ID) cerr << "p : x = " << p[0] << " y = " << p[1] << "   >>sq2 = " << r << endl;

			if (r == min_points + 5)
			{
				if (mypacs[id][4] > 1)
					return (r);
			}
			else if (r > min_points - 1 && r < min_points + 7)
				return (r);                                 //must add hiding ??????
			if ((r > min_points + 19 && r < min_points + 23) || r == min_points + 25)
			{   
				update_morph(2, id, r, forward_morph(epacs[en_id][2]));
				return (r);
			}
			if (r == min_points + 23 || r == min_points + 24)
			{   
				update_morph(2, id, r, -1);
				if (id == ID) cerr << "m = " << morph[id][0] << endl;
				return (-1);
			}
			if (r == min_points + 26)
			{
				if (epacs[en_id][4] == 1)
					update_morph(2, id, r, -1);
				else
					update_morph(2, id, r, forward_morph(epacs[en_id][2]));
				return (r);
			}


			if (r > -4)
			{
				if (r == super_pellet_point)
					r += super_pellet_offset[max_depth - 2];
				else if (r > 0)
					r += offset[max_depth - 2];
				rn = check_nsquare(map, mypacs, epacs, id, p, PREV(s), 3);
				if (id == ID) cerr << "p : x = " << p[0] << " y = " << p[1] << "   sq3 = " << rn << endl;
				if (rn < min_points + 30)
					return (rn);
				r += rn;
			}
			else if (r > -6 && r > rmin)
				p[0] = -1;

			if (id == ID)
				cerr << "r = " << r << "\trmin = " << rmin << endl;
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
		int lm;
		int temp;
		int en_id;
		int p1[2];
		int p2[2];
		int move_to_eat[2][2];
		long long r;
		long long sq1;
		long long sq2;
		long long m_sq2;

		m_sq2 = 0;
		r = min_points - 10;
		move_to_eat[0][0] = -1;
		s = last_move[id];
		for (int i = 0; i < 4; i++, s = NEXT(s))
		{
			p1[0] = mypacs[id][0] + border[s][0];
			p1[1] = mypacs[id][1] + border[s][1];
			sq1 = check_position(map, p1, mypacs, epacs, id, &en_id);
			//debugging
			if (id == ID)
			{
				cerr << "------------------------------------------------\n";
				cerr << "id  = " << id << "    p: x = " << p1[0] << " y = " << p1[1] << endl;
				cerr << "sq1 = " << sq1 << endl;
			}
			if (id == ID) cerr << " m = " << morph[id][0] << " a = " << action[id][0] << " cool = " << mypacs[id][4] << " mov = " << move_to_eat[1][0] << endl;
			if (sq1 > -4)                                 //eat or just run
			{
				if (r == super_pellet_point)
					r += super_pellet_offset[max_depth - 1];
				else if (sq1 > 0)
					sq1 += offset[max_depth - 1];
				sq2 = check_second_square(map, mypacs, epacs, id, p1, p2, PREV(s), &temp);
				if (sq2 < min_points + 7)
					continue ;
				if (sq2 < min_points + 30 && morph[id][0] > -1 && sq2 < m_sq2)
				{
					action[id][0] = 1;
					action[id][1] = morph[id][0];
					m_sq2 = sq2;
				}
				if (id == ID) cerr << "sq2 = " << sq2 << endl;
				if (sq1 + sq2 > r)
				{
					if (move_by_one[id][0])              //move by one if i am stronger, the enemy can morph and i am on speed
						p2[0] = -1;
					lm = temp;
					move_to_eat[0][0] = p1[0];
					move_to_eat[0][1] = p1[1];
					move_to_eat[1][0] = p2[0];
					move_to_eat[1][1] = p2[1];
					r = sq1 + sq2;  
				} 
			}
			else if ((sq1 > min_points + 19 && sq1 < min_points + 23) || (sq1 == min_points + 25 || sq1 == min_points + 26))
				update_morph(1, id, sq1, forward_morph(epacs[en_id][2]));
			else if (sq1 == min_points + 23 || sq1 == min_points + 24)
				update_morph(1, id, sq1, epacs[en_id][2]);          //backward morph
			if (sq1 < min_points + 30 && morph[id][0] > -1)
			{
				action[id][0] = 1;
				action[id][1] = morph[id][0];
				return ;
			}
			if (id == ID) cerr << " m = " << morph[id][0] << " a = " << action[id][0] << " cool = " << mypacs[id][4] << " mov = " << move_to_eat[1][0] << endl;
		}

		//speed up
		if (morph[id][0] != -1 && action[id][0] == -1 && !mypacs[id][4] && move_to_eat[1][0] != -1)                             //should i speed up
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
			update_explored(move_to_eat[0][0], move_to_eat[0][1], id, 1);
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
	{
		last_move[i] = 0;
	}

	turn = 1;

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
			epacs[i][0] = -1;
			mypacs[i][0] = -1;
			action[i][0] = -1;
			move_pac[i][0] = -1;

			move_by_one[i][0] = 0;
			move_by_one[i][1] = max_depth;
			move_by_one[i][2] = 0;

			morph[i][0] = -2;
			morph[i][1] = max_depth;
			morph[i][2] = 0;
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
				{
					map[mypacs[id][1]][mypacs[id][0]] = id + turn * 10 + 10000;
					ft_mine::update_explored(mypacs[id][0], mypacs[id][1], id, 1);
				}
				else
					mypacs[id][0] = -1;
			}
			else
			{
				cin >> epacs[id][0] >> epacs[id][1] >> typeId >> epacs[id][3] >> epacs[id][4];cin.ignore();
				for (j = 0; j < 4 && typeId.compare(forms[j]); j++);
				epacs[id][2] = j;
				if (j < 3)
				{
					map[epacs[id][1]][epacs[id][0]] = id + turn * 10 + 20000;
					ft_mine::update_explored(epacs[id][0], epacs[id][1], id, 0);
				}
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
			if (turn == 1 && value == 10)
			{
				super_pellets.push_back(y * 100 + x);
				closest_pac.push_back(0);
			}
		}

		if (turn > 1)
		{
			for (int i = 0; i < super_pellets.size(); i++)
			{
				x = super_pellets[i] % 100;
				y = super_pellets[i] / 100;
				int val = map[y][x];
				if (val >= 1000 && val < 19000 && val != turn + 1000)
				{
					map[y][x] = 0;
					super_pellets.erase(super_pellets.begin() + i);
					closest_pac.erase(closest_pac.begin() + i);
				}
			}
		}

		int dmin = 10000;
		for (int i = 0, d = 0; i < super_pellets.size(); i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (mypacs[j][0] != -1)
				{
					x = super_pellets[i] % 100;
					y = super_pellets[i] / 100;
					d = (mypacs[j][0] - x) * (mypacs[j][0] - x) + (mypacs[j][1] - y) * (mypacs[j][1] - y);
					if (d < dmin)
					{
						dmin = d;
						closest_pac[i] = j;
					}
				}
			}
		}

		for (int i = 0; i < 5; i++)
			if (epacs[i][0] != -1)
				cerr << "enemy = " << i << " turns left = " << epacs[i][3] << endl;
		for (int i = 0; i < 5; i++)
			if (mypacs[i][0] != -1)
				ft_mine::dead_pellets_elimination(map, mypacs[i][0], mypacs[i][1]);

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

