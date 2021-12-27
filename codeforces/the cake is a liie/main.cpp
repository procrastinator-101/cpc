#include <iostream>
#include <vector>
#include <set>

int tail;

int	find_min_vertices(std::set<int> vertices[], int n)
{
	int min;
	int ret;

	ret = 0;
	min = vertices[0].size();
	for (int i = 1; i < n; i++)
	{
		if (min == 2)
			return (ret);
		int holder = vertices[i].size();
		if (holder < min)
		{
			min = holder;
			ret = i;
		}
	}
	return (ret);
}

void get_the_cake(std::set<int> vertices[], int *explored, std::set<int> pieces[], int head, int parent, std::vector<int> &split_the_cake)
{
	int piece_nb;
	auto iter = pieces[head - 1].begin();

	for (auto k : pieces[parent - 1])
	{
		if (pieces[head - 1].find(k) != pieces[head - 1].end())
		{
			for (auto s : vertices[head - 1])
				pieces[s - 1].erase(k);
			split_the_cake.push_back(k + 1);
			break ;
		}
	}
	explored[head - 1] = 1;
	std::cout << head << ' ';
	for (auto s : vertices[head - 1])
		if (!explored[s - 1] && (pieces[head - 1].size() < 2 || pieces[s - 1].size() < 2))
			get_the_cake(vertices, explored, pieces, s, head, split_the_cake);
	for (auto s : vertices[head - 1])
		if (!explored[s - 1] && pieces[s - 1].size() == 2 && vertices[s - 1].find(tail) == vertices[s - 1].end())
			get_the_cake(vertices, explored, pieces, s, head, split_the_cake);
}

int	main()
{
	int t;
	int i;
	int j;
	int k;
	std::cin >> t;
	while (t--)
	{
		int n;
		std::cin >> n;
		std::set<int> vertices[n];
		std::set<int> pieces[n];
		std::vector<int> split_the_cake;
		int explored[n];
		for (int l = 0; l < n; l++)
			explored[l] = 0;
		k = -1;
		while (++k < n - 2)
		{
			i = -1;
			int arr[3];
			while (++i < 3)
				std::cin >> arr[i];
			while (i--)
			{
				j = 3;
				while (j--)
					if (i != j)
						vertices[arr[i] - 1].insert(arr[j]);
				pieces[arr[i] - 1].insert(k);
			}
		}
		tail = find_min_vertices(vertices, n) + 1;
		get_the_cake(vertices, explored, pieces, tail, tail, split_the_cake);
		std::cout << "\n";
		for (auto s : split_the_cake)
			std::cout << s << ' ';
		std::cout << "\n";
	}
	return (0);
}
