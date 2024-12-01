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

struct Route
{
	int city;
	int price;

	Route() : city(0), price(0)
	{
	}
	Route(int city, int price) : city(city), price(price)
	{
	}
};

int dfs(vector<vector<Route>>& routes, int city, int dst, int k, int flights)
{
	int ret;
	int dist;

	if (k <= flights - 1)
		return -1;
	cout << "----------------------------------------------" << endl;
	cout << city << " - " << flights << endl;
	ret						  = -1;
	vector<Route>& candidates = routes[city];
	for (int i = 0; i < candidates.size(); i++)
	{
		if (candidates[i].city == dst)
		{
			dist = candidates[i].price;
			ret	 = ret == -1 ? dist : min(ret, dist);
		}
		else
		{
			dist = dfs(routes, candidates[i].city, dst, k, flights + 1);
			if (dist != -1)
			{
				dist += candidates[i].price;
				ret = ret == -1 ? dist : min(ret, dist);
			}
		}
		cout << candidates[i].city << " | " << dist << endl;
	}
	cout << "----------------------------------------------" << endl;
	return ret;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
	vector<vector<Route>> routes(n);


	for (int i = 0; i < flights.size(); i++)
	{
		routes[flights[i][0]].push_back(Route(flights[i][1], flights[i][2]));
	}
	return dfs(routes, src, dst, k, 0);
}

int main(int argc, char** argv)
{
	// int data[][3] = { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 },
	// 	{ 1, 3, 600 }, { 2, 3, 200 } };
	// int n		  = 4;
	// int src		  = 0;
	// int dst		  = 3;
	// int k		  = 1;
	int data[][3] = { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } };
	int n		  = 3;
	int src		  = 0;
	int dst		  = 2;
	int k		  = 1;
	vector<vector<int>> trust;

	for (int i = 0; i < sizeof(data) / (sizeof(int) * 3); i++)
	{
		vector<int> tmp;
		tmp.push_back(data[i][0]);
		tmp.push_back(data[i][1]);
		tmp.push_back(data[i][2]);
		trust.push_back(tmp);
	}
	for (int i = 0; i < trust.size(); i++)
	{
		for (int j = 0; j < trust[i].size(); j++)
			cout << trust[i][j] << " ";
		cout << endl;
	}
	int ret = findCheapestPrice(n, trust, src, dst, k);
	cout << endl << "========================================" << endl;
	cout << ret;
	cout << endl << "========================================" << endl;
	return 0;
}