#include <vector>

using namespace std;

namespace solution
{
	bool divide_into_groups(vector <int> edges[], int groups[], int k, int p)
	{
		groups[k] = p;
		for (auto s : edges[k])
		{
			if (groups[s] < 0)
			{
				if (!divide_into_groups(edges, groups, s, !p))
					return (0);
			}
			else if (groups[s] == p)
				return (0);
		}
		return (1);
	}

	bool possibleBipartition(int n, vector<vector<int>>& dislikes)
	{
		int r;
		int a,b;
		int groups[n];
        vector <int> edges[n];

		for (int i = 0; i < n; i++)
			groups[i] = -1;
		for (auto v : dislikes)
		{
			a = v[0] - 1;
			b = v[1] - 1;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		r = divide_into_groups(edges, groups, 0, 0); 
		for (int i = 1; i < n && r; i++)
			r = divide_into_groups(edges, groups, i, groups[i]); 
		return (r);
    }
}
