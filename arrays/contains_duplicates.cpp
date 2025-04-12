#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{

public:
	bool optimalApproach(vector<int> nums)
	{
		unordered_set<int> check;

		for (int n : nums)
		{
			if (check.count(n))
				return true;
			else
				check.insert(n);
		}

		return false;
	}
};

int main()
{
	vector<int> nums = {1, 2, 3, 4};
	Solution sol;
	bool out = sol.optimalApproach(nums);
	string msg = out ? "Contains duplicates" : "Does not contain duplicates";
	cout << msg << " ";
}
