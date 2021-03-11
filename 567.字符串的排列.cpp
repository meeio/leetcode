/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> need, window;

        for ( char c : s1 )
        {
            need[c]++;
        }

        int left = 0, right = 0, valid = 0;

        while ( right < s2.size() )
        {
            char c = s2[right];
            
            if ( need.count(c) > 0 )
            {
                window[c]++;
                if ( window[c] == need[c] )
                {
                    valid ++;
                }
            }
            else
            {
                for (char c : s1)
                {
                    window[c] = 0;
                }
                valid = 0;
            }

            printf("at pos %d - %c with valid %d \n", right, c, valid);

            right++;

            if (valid == need.size())
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
