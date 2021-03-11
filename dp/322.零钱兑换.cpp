/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int sub_amount = 0; sub_amount <= amount; sub_amount++)
        {
            for (int coin : coins)
            {
                if (coin <= sub_amount)
                {
                    dp[sub_amount] = min(dp[sub_amount], 
                                         1 + dp[sub_amount - coin]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// @lc code=end
