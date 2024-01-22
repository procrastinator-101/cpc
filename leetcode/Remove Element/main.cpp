#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int	i = 0;
	int j = nums.size() - 1;
	int	ret = 0;

	while (i <= j)
	{
		if (nums[j] == val)
			j--;
		if (nums[i] != val)
		{
			i++;
			ret++;
		}
		else if (nums[j] != val)
		{
			nums[i++] = nums[j--];
			// ret++;
		}
	}
	return i;
}

int	main()
{
	vector<int> nums = {3,2,2,3};

	int ret = removeElement(nums, 3);
	for (int i = 0; i < ret; i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}