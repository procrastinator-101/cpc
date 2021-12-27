#include <stdio.h>

int main()
{
	int q;
	int size;
	vector<int> judge_requests;

	scanf("%d", &q);
	int requests[q][4];

	for (int i = 0; i < q; i++)
	{
		scanf("%d", requests[i]);
		scanf("%d", requests[i] + 1);
		scanf("%d", requests[i] + 2);
		scanf("%d", requests[i] + 3);
		if (!requests[i][1])
			judge_requests.push_back(i);
	}
	size = judge_requests.size();
	int delays[size];
	int results[size];
	for (int i = 0; i < q; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int s = judge_requests[j];
			if (requests[i][2] <= requests[s][2])
			{
				if (!requests[i][1] && i != s)
					continue ;
				if (requests[i][0])
					results[s] += requests[i] + ;
			}
		}
	}
}
