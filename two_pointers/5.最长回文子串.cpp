/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans("");
        for ( int i = 0; i < s.size(); i++ )
        {
            string first = palindrome(s, i, i);
            string second = palindrome(s, i, i + 1);

            ans = ans.size() >= first.size() ? ans : first;
            ans = ans.size() >= second.size() ? ans : second;
        }

        return ans;
    }

    string palindrome(string& s, int i, int j)
    {
        while ( i >= 0 && j < s.size() && s[i] == s[j] )
        {
            i --;
            j ++;
        }
        i = i + 1;
        j = j - 1;
        // printf("%d %d \n", i + 1, j - i - 1);
        return s.substr(i, j - i + 1); 
    }
};
// @lc code=end
