// solving maximum subarray problem using kadane's algorithm

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void kadens(vector<int> &nums)
    {
        int sum = 0;
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum < 0)
                sum = 0;

            max_sum = max(sum, max_sum);
        }
        cout << max_sum << endl;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    sol.kadens(nums);
}