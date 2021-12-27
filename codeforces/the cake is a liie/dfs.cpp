void get_the_cake(std::set<int> vertices[], int *explored, int start)
{
	if (!explored[start])
	{
		explored[start] = 1;
		std::cout << start + 1 << ' ';
		for (auto s : vertices[start])
			if (!explored[s - 1])
				get_the_cake(vertices, explored, s - 1);
	}
}
