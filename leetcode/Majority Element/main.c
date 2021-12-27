#include <stdio.h>

int majorityElement(int* nums, int numsSize)
{
	int	candidate;
	int	counter;

	candidate = nums[0];
	counter = 1;
	for (int i = 1; i < numsSize; i++)
	{
		if (!counter)
			candidate = nums[i];
		if (nums[i] == candidate)
			counter++;
		else
			counter--;
	}
	return (candidate);
}

int main()
{
	int arr[] = {2,1,5,1,1};
	printf("r = %d\n", majorityElement(arr, sizeof(arr) / sizeof(int)));
}
