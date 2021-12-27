#include <stdio.h>

int subarraySum(int* nums, int numsSize, int k)
{
    int i, j, r;
	int sums[numsSize + 1];

	r = 0;
	sums[0];
	for (i = 0; i < numsSize; i++)
		sums[i + 1] = sums[i] + nums[i];
	for (i = numsSize; i > 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
			if (sums[i] - sums[j] == k)
				r++;
	}
	return (r);
}

int main()
{
	int arr[] = {1, 1, 1};
	printf("r = %d\n" ,subarraySum(arr, sizeof(arr) / sizeof(int), 2));
}
