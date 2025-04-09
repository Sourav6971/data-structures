// Solved the decode ways question on leetcode.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int numDecode(string s)
    {
        if (s.length() < 1)
            return 0; // No encoding possible
        if (s[0] == '0')
            return 0; // No encoding possible
        if (s.length() == 1)
            return 1; // There is only one encoding possible as the value is a single digit (A-I)

        int val1 = 1; // because we have taken care of the first character so we sill start with the second character
        int val2 = 1;

        for (int i = 1; i < s.length(); ++i)
        {
            int d1 = s[i] - '0';
            int d2 = (s[i - 1] - '0') * 10 + d1;
            int val = 0;
            if (d1 >= 1)
                val += val2;
            if (d2 >= 10 && d2 <= 26)
                val += val1;

            val1 = val2;
            val2 = val;
        }
        return val2;
    }
};