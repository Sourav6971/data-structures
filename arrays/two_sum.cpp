// solution to the famous two sum problem on leetcode.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void optimal(vector<int> nums, int target)
    {
        // optimal approach is using hashmap
        vector<int> output;
        unordered_map<int, int> _map;
        cout << "Result using unordered_set:" << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int complement = target - num;
            auto it = _map.find(complement);
            if (it != _map.end())
            {
                cout << it->second << " ";
                cout << i << endl;
            }
            _map[num] = i;
        }
    }

    void goodApproach(vector<int> nums, int target)
    {
        // This can also be a good approach by using the find function of vector class
        vector<int> result;
        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1)
        {
            auto it2 = find(it1 + 1, nums.end(), target - *it1);
            if (it2 != nums.end())
            {
                result.push_back(it1 - nums.begin());
                result.push_back(it2 - nums.begin());
                break;
            }
        }
        cout << "Result using find method" << endl;
        for (int n : result)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    void sortedArray(vector<int> &nums, int target)
    {
        // two pointer approach and it works only for sorted arrays. This approach cannot be implemented for unsorted ones.
        int slow = 0, fast = nums.size() - 1;
        cout << "Solution using two pointers for a sorted array" << endl;
        while (slow < fast)
        {
            int value = nums[slow] + nums[fast];
            if (value == target)
            {
                cout << slow << " " << fast << endl;
            }
            if (value < target)
            {
                slow++;
            }
            else
            {
                fast--;
            }
        }
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    sol.goodApproach(nums, target);
    sol.optimal(nums, target);
    sol.sortedArray(nums, target);
}
