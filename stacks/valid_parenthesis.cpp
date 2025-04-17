#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool validParenthesis(string s)
    {
        stack<char> stk;
        if (!s.length())
            return false;

        for (char c : s)
        {
            if (c == '[' || c == '{' || c == '(')
                stk.push(c);
            else
            {
                switch (c)
                {
                case ']':
                {
                    if (stk.top() != '[')
                        return false;
                    else
                        stk.pop();
                    break;
                }
                case '}':
                {
                    if (stk.top() != '{')
                        return false;
                    else
                        stk.pop();
                    break;
                }
                case ')':
                {
                    if (stk.top() != '(')
                        return false;
                    else
                        stk.pop();
                    break;
                }
                }
            }
            if (stk.size() == 0)
                return true;
        }
        return false;
    }
};

int main()
{
    string s = "{[)]}";
    Solution sol;
    cout << sol.validParenthesis(s) << endl;
}