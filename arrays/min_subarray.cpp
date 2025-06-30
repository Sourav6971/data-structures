#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int bruteForce(vector<int> nums, int target)
    {
        int count = 0, min_count = INT_MAX;
        int pointer = 0;
        int curr_sum = 0;
        int i = 0;
        int flag = 0;
        while (i < nums.size())
        {

            curr_sum += nums[i];
            count++;
            cout << "count= " << count << endl;
            i++;
            if (curr_sum >= target)
            {
                flag++;
                cout << curr_sum << " " << pointer << " " << min_count << endl;
                min_count = min(min_count, count);
                count = 0;
                curr_sum = 0;
                pointer++;
                i = pointer;
            }
        }
        if (flag == 0)
            return 0;
        return min_count;
    }
    int minSubarray(vector<int> nums, int target)
    {
        int min_count = INT_MAX;
        int sum = 0;
        int count = 0;
        int left = 0, right = 0;
        while (left < nums.size())
        {

            if (sum >= target)
            {

                sum -= nums[left++];
                min_count = min(count, min_count);
                count--;
            }
            else
            {
                sum += nums[right++];
                count++;
            }
        }
        return min_count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << sol.minSubarray(nums, target) << endl;
}