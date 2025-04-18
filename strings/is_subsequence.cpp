// This is more of a stack type question where the order of the characters was also important hence instead of using an array we used a stack.

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        stack<char> check;
        for (char c : s)
        {
            check.push(c);
        }
        for (int i = t.length() - 1; i >= 0; i--)
        {
            if (check.empty())
                break;
            char ch = t[i];
            if (check.top() == ch)
                check.pop();
        }
        if (check.size() == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    string s = "ahbgdc";
    string t = "abc";
    Solution sol;
    cout << sol.isSubsequence(t, s);
}