// Solution to the problem calculate the length of the longest substring wihhout repitition on leetcode

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int maxLength(string s)
    {
        map<char, int> check;
        int max_length = 0;
        int curr_length = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (check.count(c))
            {
                curr_length = 0;
                i = check[c];
                // start the iteration again from the point where the similarity was first found
                check.clear();
            }
            else
            {
                curr_length++;
                check[c] = i;
            }
            max_length = max(max_length, curr_length);
        }

        return max_length;
    }
};

int main()
{
    string s = "dvdf";
    Solution sol;
    int answer = sol.maxLength(s);
    cout << answer << "";
}