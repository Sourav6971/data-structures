// solution to merge sorted arrays on leetcode. Merge nums1 and nums2 and and store the sorted array in nums1. Add numbers to nums1 after m digits and add n digits of num2 to num1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> returnSorted(vector<int> nums1, int m, vector<int> nums2, int n)
    {
        for (int i = 0; i <= n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        return nums1;
    }
    vector<int> pointerApproach(vector<int> nums1, int m, vector<int> nums2, int n)
    { // we can use a two pointer approach as the arrays are sorted.

        int p1 = m - 1;
        int p2 = n - 1;
        int i = m + n - 1;
        while (p2 >= 0)
        {
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[i--] = nums1[p1--];
            }
            else
            {
                nums1[i--] = nums2[p2--];
            }
        }
        return nums1;
    }
};
int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    // vector<int> out = sol.returnSorted(nums1, 3, nums2, 3);
    vector<int> out = sol.pointerApproach(nums1, 3, nums2, 3);

    for (int n : out)
    {
        cout << n << " ";
    }
}