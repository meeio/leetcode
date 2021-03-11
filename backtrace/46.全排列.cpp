/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<int> choice;
        backtrace(nums, choice);
        return ret; 
    }

private:
    vector<vector<int>> ret;

    void backtrace(vector<int>& nums, vector<int>& choice)
    {
        if ( nums.size() == choice.size() )
        {
            ret.emplace_back(choice);
        }

        for ( int& num : nums )
        {
            if ( find(choice.begin(), choice.end(), num) == choice.end() )
            {
                choice.push_back(num);
                backtrace(nums, choice);
                choice.pop_back();
            }
        }
    }
};
// @lc code=end
