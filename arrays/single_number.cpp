// Solution to finding the number which is not repeated from an array of numbers which are repeated twice.
// Used xor operation to solve this.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void pringSingle(vector<int> nums)
    {
        int value = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            value = value ^ nums[i];
        }
        cout << value;
    }
};
int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution sol;
    sol.pringSingle(nums);
}