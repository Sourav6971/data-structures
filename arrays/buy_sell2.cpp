#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices)
    {
        int buy = 0;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] > buy)
            {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit - prices[0];
    }
};
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices);
}