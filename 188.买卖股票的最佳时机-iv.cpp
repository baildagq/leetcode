#include <vector>
#include <cstdio>

using namespace std;
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int day = prices.size();
        // sub chance when buy stock 
        // hold_y[i][j] indict when i day end, left j chance, hold stock, current max profit
        vector<vector<int>> hold_y = vector<vector<int>>(day, vector<int>(k + 1, 0)); 
        // hold_n[i][j] indict when i day end, left j chance, not hold stock, current max profit
        vector<vector<int>> hold_n = vector<vector<int>>(day, vector<int>(k + 1, 0));
        // initialize
        hold_y[0][k - 1] = -(prices[0]);

        for (auto i = 1; i < day; i++)
        {
            for (auto j = k; j > 0; j--)
            {
                auto use_chance = k - j;
                auto min_daynum = use_chance * 2;
                if (i )
                hold_y[i][j] = max(hold_y[i - 1][j], hold_n[i - 1][j + 1] - prices[i]);

                hold_n[i][j] = max(hold_n[i - 1][j], hold_y[i - 1][j] + prices[i]);
            }
        }

        for (auto j = 0; j < k; j++)
        {
            for (auto i = 0; i < day; i++)
            {
                printf("%d ", hold_y[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for (auto j = 0; j < k; j++)
        {
            for (auto i = 0; i < day; i++)
            {
                printf("%d ", hold_n[i][j]);
            }
            printf("\n");
        }

        int res = 0;
        for (int j = 0; j < k; j ++)
        {
            res = max(res, hold_n[day - 1][j]);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    int k = 2;
    vector<int> prices{3,2,6,5,0,3};
    printf("%d\n", Solution().maxProfit(k, prices));
    return 0;
}
