#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace solution
{
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
	{
		vector <vector<int>>			ret;
		multimap <unsigned, int>		distances;

		for (int i = 0; i < points.size(); i++)
			distances.insert(pair<unsigned, int>(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
		for (auto it = distances.begin(); k && it != distances.end(); k--, it++)
		{
			vector <int> temp;

			temp.push_back(points[it->second][0]);
			temp.push_back(points[it->second][1]);
			ret.push_back(temp);
		}
		return (ret);
    }
}

int main()
{
	int k;
	int n;
	vector <vector<int>> points;
	vector <vector<int>> ret;

	cout << "enter k : ";
	cin >> k;
	cout << "enter n : ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a,b;
		vector <int> temp;

		cin >> a >> b;
		temp.push_back(a);
		temp.push_back(b);
		points.push_back(temp);
	}
	ret = solution::kClosest(points, k);
	for (auto s : ret)
		cout << s[0] << ' ' << s[1] << endl;
	return (0);
}
