/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for ( char c : t )
        {
            need[c] += 1;
        }

        int len   = std::numeric_limits<int>::max();
        int valid = 0;
        int star  = 0;
        int left = 0, right = 0;

        while ( right < s.size() )
        {
            char c = s[right];
            right++;

            if ( need.count(c) )
            {
                window[c]++;
                if ( window[c] == need[c] )
                {
                    valid++;
                }
            }

            while ( valid == need.size() )
            {
                if ( right - left < len )
                {
                    star = left;
                    len  = right - left;
                }

                char d = s[left];
                left++;

                if ( need.count(d) )
                {
                    if ( window[d] == need[d] )
                    {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        if ( len == std::numeric_limits<int>::max())
        {
            return "";
        }
        else
        {
            return s.substr(star, len);
        }
    }
};
// @lc code=end
