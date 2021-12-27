#include <stdio.h>

int remove_duplicates(int *nums, int nums_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++j < nums_size)
	{
		if (nums[i] != nums[j])
			nums[++i] = nums[j];
	}
	printf("i = %d j = %d num_size = %d\n", i, j, nums_size);
	return (nums_size ? i + 1 : 0);
}

int main()
{
	int arr[1] = {};
	int size = remove_duplicates(arr, 1);
	printf("size = %d\n", size);
	for (int i = 0; i < size; i++)
		printf("%d, ", arr[i]);
	printf("\n");
	return (0);
}
