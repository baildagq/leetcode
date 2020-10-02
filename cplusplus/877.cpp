#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include "./utils.h"

class Solution
{
public:
    // method-2：查看他人题解学到的状态转移方程
    // dp[i][j]表示：当剩下的石子堆为从i到j时，当前玩家与另一个玩家的石子数量之差的最大值
    vector<vector<int>> dp;
    bool stoneGame(vector<int> &piles)
    {
        int size = piles.size();
        dp = vector<vector<int>>(size, vector<int>(size, 0));
        for (int i = size - 1; i >= 0; i--)
        {
            dp[i][i] = 0;
            for (int j = i + 1; j < size; j++)
            {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][size - 1] > 0;
    }
};

// class Solution
// {
// method-1：自己想出的回溯方法，但是存在大量的子问题，所以需要使用动态规划进行子问题状态转移
// public:
//     vector<int> res = vector<int>(2, 0);
//     bool recall(vector<int> &piles, bool turn, int l, int r)
//     {
//         // alex'turn is 0, li'turn is 1
//         if (l > r) return res[0] > res[1];
//         res[turn] += piles[l];
//         if (recall(piles, (turn+1)%2, l+1, r)) return true;
//         res[turn] -= piles[l];
//         res[turn] += piles[r];
//         if (recall(piles, (turn+1)%2, l, r-1)) return true;
//         res[turn] -= piles[r];
//         return false;
//     }
//     bool stoneGame(vector<int> &piles)
//     {
//         int size = piles.size();
//         if (size <= 1) return true;
//         return recall(piles, true, 0, size - 1);
//     }
// };

int main(int argc, const char **argv)
{
    vector<int> list = {5, 3, 4, 5};
    printf("%d\n", Solution().stoneGame(list));
    return 0;
}
