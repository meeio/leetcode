/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
public:
    int openLock(vector<string>& deadends, string target)
    {
        int step = 0;

        if ( target == "0000" )
            return step;

        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> to_visited;

        to_visited.push("0000");

        while ( !to_visited.empty() )
        {
            int sz = to_visited.size();

            for ( int i = 0; i < sz; i++ )
            {
                string code = to_visited.front();
                to_visited.pop();

                if ( deads.count(code) )
                    continue;

                if ( code == target )
                    return step;


                for ( int i = 0; i < 4; i++ )
                {
                    string plus = plus_one(code, i);
                    if ( !visited.count(plus) )
                    {
                        to_visited.push(plus);
                        visited.insert(plus);
                    }

                    string down = down_one(code, i);
                    if ( !visited.count(down) )
                    {
                        to_visited.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }

        return -1;
    }

private:
    string plus_one(string code, int idx)
    {
        if ( code[idx] == '9' )
            code[idx] = '0';
        else
            code[idx] += 1;
        return code;
    }

    string down_one(string code, int idx)
    {
        if ( code[idx] == '0' )
            code[idx] = '9';
        else
            code[idx] -= 1;
        return code;
    }
};
// @lc code=end
