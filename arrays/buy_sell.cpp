#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices)
    {
        int buy = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            buy = min(prices[i], buy);
            max_profit = max(max_profit, prices[i] - buy);
        }
        return max_profit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices);
}