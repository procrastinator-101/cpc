#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace solution
{
	bool check_prerequisites(int course, int courses_status[], vector<int> courses[])
	{
		bool r;

		if (courses_status[course] == 1)
			return (0);
		if (courses_status[course] == 2)
			return (1);
		r = 1;
		courses_status[course] = 1;
		for (int i = 0; i < courses[course].size() && r; i++)
			r = check_prerequisites(courses[course][i], courses_status, courses);
		courses_status[course] = 2;
		return (r);
	}

	bool canFinish(int num_courses, vector<vector<int>>& prerequisites)
	{
		bool			r;
		int				courses_status[num_courses];
		vector <int>	courses[num_courses];

		for (auto s : prerequisites)
			courses[s[0]].push_back(s[1]);
		for (int i = 0; i < num_courses; i++)
			courses_status[i] = 0;
		for (int i = 0; i < num_courses; i++)
		{
			for (auto k : courses[i])
				cout << k << ' ';
			cout << endl;
		}
		r = 1;
		for (int i = 0; i < num_courses && r; i++)
			if (courses_status[i] == 0)
				r = check_prerequisites(i, courses_status, courses);
		return (r);
	}
}

int main()
{
	int a, b, n;
	vector<vector<int>> prerequisites;

	cout << "enter the number of courses : ";
	cin >> n;
	while (1)
	{
		cin >> a;
		if (a < 0)
			break ;
		cin >> b;
		vector <int> v;
		v.push_back(a);
		v.push_back(b);
		prerequisites.push_back(v);
	}
	for (auto s : prerequisites)
	{
		for (auto k : s)
			cout << k << ' ';
		cout << endl;
	}
	bool r = solution::canFinish(n, prerequisites);
	cout << "r = " << r << endl;
}
