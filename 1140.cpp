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
    /*
 * 动态规划，不过自己没有想出来，看到题解做出来的
 * 自己做题过程中，也想到了dp[i][j]这样的想法，也想到了从后向前推导，但是心里太不静了，所以并没有进行很深入的思考
 * 正确的解题思路为：dp[i][m] 表示当前执行的玩家在[i:len-1]这段路程上起始为M时能够获得的最大值
 * 转移方程为：
 * dp[i][m] = sum[i:len-1] if (i+2M >= len)
 * dp[i][m] = max(dp[i][m], sum[i:len-1] - dp[i+x][max(m,x)])  1<=x<=2m
 */
public:
    int stoneGameII(vector<int> &piles)
    {
        int size = piles.size();
        int sum = 0;
        vector<vector<int>> dp(size, vector<int>(size + 1, 0));
        for (int i = size - 1; i >= 0; i--)
        {
            sum += piles[i];
            for (int m = 1; m <= size; m++)
            {
                if (i + 2 * m >= size)
                {
                    dp[i][m] = sum;
                }
                else
                {
                    for (int x = 1; x <= 2 * m; x++)
                    {
                        dp[i][m] = max(dp[i][m], sum - dp[i + x][max(m, x)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};

int main(int argc, const char **argv)
{
    vector<int> list = {2,7,9,4,4};
    printf("%d\n", Solution().stoneGameII(list));
    return 0;
}
