/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtrace(0, board);
        return ret;
    }

private:
    vector<vector<string>> ret;

    void backtrace(int row, vector<string>& board)
    {
        if ( row == board.size() )
        {
            ret.push_back(board);
            return;
        }

        int n = board[row].size();
        for ( int col = 0; col < n; col++ )
        {
            if ( is_valid(board, row, col) )
            {
                board[row][col] = 'Q';
                backtrace(row + 1, board);
                board[row][col] = '.';
            }
        }
    }

    bool is_valid(vector<string>& board, int row, int col)
    {
        int n = board.size();

        for ( int i = 0; i < row; i++ )
        {
            if ( board[i][col] == 'Q' )
            {
                return false;
            }
        }

        for ( int i = row - 1, j = col + 1;
              i >= 0 && j < n;
              i--, j++ )
        {
            if ( board[i][j] == 'Q' )
            {
                return false;
            }
        }

        for ( int i = row - 1, j = col - 1;
              i >= 0 && j >= 0;
              i--, j-- )
        {
            if ( board[i][j] == 'Q' )
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
