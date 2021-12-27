#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

namespace Solution 
{
        int findMaxLength(vector<int>& nums)
        {
            int k;
            int r;
            int val;
            map <int, int> results;

            r = 0;
            k = 0;
            results.insert(pair<int, int>(0, 0));
            for (int i = 1; i < nums.size() + 1; i++)
            {   
                r += nums[i - 1] ? 1 : -1;
				cout << "i = " << i << "\tr = " << r;
                auto it = results.find(r);
                if (it == results.end())
                    results.insert(pair<int, int>(r, i));
                else
                {   
                    val = i - (*it).second;
					cout << "\tval = " << val;
                    k = max(k, val);
                }   
				cout << endl;
            }   
            return (k);
        }
};

int main() 
{
  vector <int> a;
  a.push_back(0);
  a.push_back(1);
  Solution::findMaxLength(a);

  return 0;
}
