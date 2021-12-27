#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

bool	myCmp(const vector<int>& a, const vector<int>& b)
{
	// cout << a[0] << " ok " << b[0] << endl;
	return a[0] < b[0];
}

void	display(const vector<vector<int>>& v)
{
	for( int i = 0 ; i < v.size(); i++ )
	{
		for( int j = 0 ; j < v[i].size(); j++ )
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<int> twoSum(vector<int>& nums, int target)
{
	int sum;
	vector< vector<int> > tmp;
    vector<int> ret;

	for (int i = 0; i < nums.size(); i++)
	{
		vector<int> p;

		p.push_back(nums[i]);
		p.push_back(i);
		tmp.push_back(p);
	}

	// display(tmp);
	
	sort(tmp.begin(), tmp.end(), myCmp);
	
	for (int i = 0, j = tmp.size() - 1; i < j;)
	{
		sum = tmp[i][0] + tmp[j][0];
		if (sum < target)
			i++;
		else if (sum > target)
			j--;
		else
		{
			ret.push_back(tmp[i][1]);
			ret.push_back(tmp[j][1]);
			return ret;
		}
	}
	
	return ret;
}

int main()
{
	vector<int> a = {1,1,1,1,1,4,1,1,1,1,1,7,1,1,1,1,1};
	vector<int> ret = twoSum(a, 11);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
	return 0;
}