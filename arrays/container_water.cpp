// solution to container with most water problem on leetcode.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void optimalApproach(vector<int> &nums)
    {
        int slow = 0;
        int fast = nums.size() - 1;
        int maxArea = INT_MIN;
        while (slow < fast)
        {
            int height = min(nums[slow], nums[fast]);
            int area = height * (fast - slow);
            maxArea = max(area, maxArea);

            if (slow < fast)
                slow++;
            else
                fast--;
        }
        cout << maxArea;
    }
};

int main()
{
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    sol.optimalApproach(nums);
}