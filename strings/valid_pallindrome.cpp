// Solution to the leetcode problem to check if a sentence is pallindrome or not, considering only the aplhabets and digits.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPallen(string s)
    {
        string s1 = "";
        for (char c : s)
        {
            if (isalpha(c) || isdigit(c))
                s1 += c;
        }
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        // transform function is present in the algorithm library helps us to convert a string to lower case or upper case
        int slow = 0;
        int fast = s1.length() - 1;
        while (slow < fast)
        {
            if (s1[slow] != s1[fast])
                return false;
            slow++;
            fast--;
        }
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    string out = sol.isPallen(s) ? "True" : "False";
    cout << out << endl;
}