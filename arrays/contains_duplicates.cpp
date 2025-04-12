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
	bool bruteForce(vector<int> nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] == nums[j])
					return true;
			}
		}
		return false;
	}
};

int main()
{
	vector<int> nums = {4, 2, 3, 4};
	Solution sol;
	// bool out = sol.optimalApproach(nums);
	bool out = sol.bruteForce(nums);
	string msg = out ? "Contains duplicates" : "Does not contain duplicates";
	cout << msg << " ";
}
