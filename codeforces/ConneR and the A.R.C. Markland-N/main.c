#include <stdio.h>

int is_in(int *arr, int size, int val)
{
	int start;
	int end;

	start = 0;
	end = size - 1;

	while (start != end)
	{
		int middle = (end - start) / 2;
		if (arr[middle] == val)
			return (1);
		else if (arr[middle] > val)
			start = middle + 1;
		else
			end = middle - 1;
	}
	if (arr[start] == val)
		return (1);
	return (0);
}

void bubble_sort(int *arr, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < n - 1)
	{
		j = -1;
		while (++j < n - i)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = arr[j];
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int i;
		int n;
		int s;
		int k;
		int closed_floors[k];

		scanf("%d", &n);
		scanf("%d", &s);
		scanf("%d", &k);

		i = -1;
		while (++i < k)
			scanf("%d", closed_floors + i);
		bubble_sort(closed_floors, k);
		i = 0;
		while (i < n - s || i < s)
		{
			if (i < n - s)
			{
				if (is_in(closed_floors, k, s + i))
					break ;
				if (is_in(closed_floors, k, s - i))
					break ;
			}
		}
		printf("%d\n", i);
	}
	return (0);
}
