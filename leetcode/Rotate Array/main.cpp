#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k)
{
	size_t	n = nums.size();
	size_t	r = k % n;
	size_t	i;

	if (r == n / 2 && n % 2 == 0)
	{
		i = -1;
		while (++i < r)
			swap(nums[i], nums[i + r]);
	}
	else
	{
		i = r;
		while (1)
		{
			swap(nums[0], nums[i]);
			i = (i + r) % n;
			cout << i << endl;
			if (!i)
				return ;
		}
	}
}

int main()
{
	vector<int> nums;

	for (int i = 0; i < 6; i++)
		nums.push_back(i);
	rotate(nums, 2);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';

}