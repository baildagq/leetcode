#include "./utils.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int lenx = grid.size();
        if (!lenx)
            return 0;
        int leny = grid[0].size();
        if (!leny)
            return 0;

        vector<vector<int>> dp(lenx, vector<int>(leny, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < lenx; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < leny; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < lenx; i++) {
            for (int j = 1; j < leny; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[lenx - 1][leny - 1];
    }
};

int main(int argc, const char** argv)
{
    vector<vector<int>> lists = {
        { 1, 3, 1 },
        { 1, 5, 1 },
        { 4, 2, 1 }
    };
    printf("%d\n", Solution().minPathSum(lists));
    return 0;
}
