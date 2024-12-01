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

void whsileBlowers(bool* people, bool* visited, map<int, vector<int>>& acquaintances, int person, int n)
{
	if (!people[person] || visited[person])
		return;
	visited[person]	   = true;
	vector<int>& meets = acquaintances[person];
	for (int i = 0; i < meets.size(); i++)
	{
		people[meets[i]] = true;
		whsileBlowers(people, visited, acquaintances, meets[i], n);
	}
}


void simultaneousMeetings(bool* people, int n, vector<vector<int>>& meetings)
{
	bool visited[n];
	map<int, vector<int>> acquaintances;

	bzero(visited, sizeof(visited));
	for (int i = 0; i < meetings.size(); i++)
	{
		acquaintances[meetings[i][0]].push_back(meetings[i][1]);
		acquaintances[meetings[i][1]].push_back(meetings[i][0]);
	}
	for (map<int, vector<int>>::iterator it = acquaintances.begin();
		 it != acquaintances.end(); ++it)
	{
		if (people[it->first])
			whsileBlowers(people, visited, acquaintances, it->first, n);
	}
}

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
{
	bool people[n];
	vector<int> ret;
	map<int, vector<vector<int>>> secretMeetings;
	for (int i = 0; i < meetings.size(); i++)
	{
		secretMeetings[meetings[i][2]].push_back(
		vector<int>(meetings[i].begin(), meetings[i].begin() + 2));
	}

	bzero(people, sizeof(people));
	people[0]			= true;
	people[firstPerson] = true;
	for (map<int, vector<vector<int>>>::iterator it = secretMeetings.begin();
		 it != secretMeetings.end(); ++it)
	{
		simultaneousMeetings(people, n, secretMeetings[it->first]);
	}

	for (int i = 0; i < n; i++)
	{
		if (people[i])
			ret.push_back(i);
	}
	return ret;
}

int main(int argc, char** argv)
{
	int data[][3]	= { { 3, 1, 3 }, { 1, 2, 2 }, { 0, 3, 3 } };
	int n			= 4;
	int firstPerson = 3;
	vector<vector<int>> meetings;

	for (int i = 0; i < sizeof(data) / (sizeof(int) * 3); i++)
	{
		vector<int> tmp;
		tmp.push_back(data[i][0]);
		tmp.push_back(data[i][1]);
		tmp.push_back(data[i][2]);
		meetings.push_back(tmp);
	}
	for (int i = 0; i < meetings.size(); i++)
	{
		for (int j = 0; j < meetings[i].size(); j++)
			cout << meetings[i][j] << " ";
		cout << endl;
	}
	vector<int> ret = findAllPeople(n, meetings, firstPerson);
	cout << endl << "========================================" << endl;
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl << "========================================" << endl;
	return 0;
}