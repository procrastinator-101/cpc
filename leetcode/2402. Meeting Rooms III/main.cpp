#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <map>
#include <set>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <string>
#include <strings.h>
#include <utility>
#include <vector>
using namespace std;

struct Room
{
	long end;
	int nbMeetings;
	Room() : nbMeetings(0), end(0)
	{
	}
};

struct myclass {
  bool operator() (vector<int>& a, vector<int>& b)
{
	return a[0] < b[0];
}
} compare;

int mostBooked(int n, vector<vector<int>>& meetings)
{
	int ret;
	int candidate;
	long minStart;
	int maxMeetings;
	Room rooms[n];

	sort(meetings.begin(), meetings.end(), compare);
	for (int i = 0; i < meetings.size(); i++)
	{
		candidate = -1;
		for (int j = 0; j < n; j++)
		{
			if (rooms[j].end <= meetings[i][0])
			{
				candidate = j;
				break;
			}
		}
		if (candidate == -1)
		{
			minStart = LONG_MAX;
			for (int j = 0; j < n; j++)
			{
				if (rooms[j].end < minStart)
				{
					candidate = j;
					minStart  = rooms[j].end;
				}
			}
		}
		// cout << "candidate : " << candidate << endl;
		rooms[candidate].end = max<long>(meetings[i][0], rooms[candidate].end) +
		(meetings[i][1] - meetings[i][0]);
		rooms[candidate].nbMeetings++;
	}
	maxMeetings = 0;
	for (int i = 0; i < n; i++)
	{
		// cout << "room[" << i << "] : " << rooms[i].nbMeetings << endl;
		if (rooms[i].nbMeetings > maxMeetings)
		{
			ret			= i;
			maxMeetings = rooms[i].nbMeetings;
		}
	}
	return ret;
}


int main(int argc, char** argv)
{
	// int data[][2] = { { 0, 10 }, { 1, 5 }, { 2, 7 }, { 3, 4 } }; int n = 2;
	int data[][2] = { { 1, 20 }, { 2, 10 }, { 3, 5 }, { 4, 9 }, { 6, 8 } };
	int n		  = 3;
	vector<vector<int>> meetings;

	for (int i = 0; i < sizeof(data) / (sizeof(int) * 2); i++)
	{
		vector<int> tmp;
		tmp.push_back(data[i][0]);
		tmp.push_back(data[i][1]);
		meetings.push_back(tmp);
	}
	for (int i = 0; i < meetings.size(); i++)
	{
		for (int j = 0; j < meetings[i].size(); j++)
			cout << meetings[i][j] << " ";
		cout << endl;
	}
	int ret = mostBooked(n, meetings);
	cout << endl << "========================================" << endl;
	cout << ret;
	cout << endl << "========================================" << endl;
	return 0;
}