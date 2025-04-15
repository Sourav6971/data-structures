// Solution to the leetcode problem to find the product of the elements of the array except itself
#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    vector<int> productSelf(vector<int> nums)
    {
        int count_zeros = 0;
        int product = 1;
        for (int n : nums)
        {
            if (n == 0)
                count_zeros++;
            else
                product *= n;
        }
        if (count_zeros >= 2)
            return (vector<int>(nums.size(), 0));

        vector<int> out;
        for (int n : nums)
        {
            if (count_zeros == 1)
            {
                if (n == 0)
                    out.push_back(product);
                else
                    out.push_back(0);
            }
            else
            {
                out.push_back(product / n);
            }
        }
        return out;
    }
};

int main()
{
    vector<int> nums = {2, 1, 2, 2, 3, 4};
    Solution sol;
    vector<int> out = sol.productSelf(nums);
    for (int n : out)
    {
        cout << n << " ";
    }
}