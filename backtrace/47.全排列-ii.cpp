/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> choice_idx;
        backtrace(nums, choice_idx);
        return ret;
    }

private:
    vector<vector<int>> ret;

    void backtrace(vector<int>& nums, vector<int>& choice_idx)
    {
        if ( nums.size() == choice_idx.size() )
        {
            vector<int> res;
            for ( int& idx : choice_idx )
            {
                res.push_back(nums[idx]);
            }
            ret.push_back(res);
        }


        for ( int idx = 0; idx < nums.size(); idx++ )
        {
            if ( find(choice_idx.begin(), choice_idx.end(), idx)
                    == choice_idx.end() )
            {
                if ( idx > 0 && nums[idx] == nums[idx - 1])
                {
                    continue;
                }
                else
                {
                    choice_idx.push_back(idx);
                    backtrace(nums, choice_idx);
                    choice_idx.pop_back();
                }
            }
        }
    }
};
// @lc code=end
