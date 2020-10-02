#include "./utils.h"

/*
// method-1: 回溯方法，tle，复杂度为 amount ** n，因为每个硬币的尝试次数为 amount / coins[i]
class Solution {
public:
    bool solve = false;
    int minCount = INT_MAX;
    int sumCount = 0;
    // vector<int> res;

    bool dfs(vector<int>& coins, int idx, int amount) {
        if (amount == 0) {
            this->solve = true;
            this->minCount = min(this->minCount, this->sumCount);
            // printVector(res);
            return true;;
        }
        if (idx >= int(coins.size())) {
            return false;
        }
        int num = amount / coins[idx];
        for (int j = num; j >= 0; j --) {
            this->sumCount += j;
            if (!this->solve || this->sumCount < this->minCount) {
                // if (dfs(coins, idx + 1, amount - j * coins[idx])){
                //     return true;
                // }
                dfs(coins, idx + 1, amount - j * coins[idx]);
            }
            this->sumCount -= j;
        }
        return false;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        dfs(coins, 0, amount);
        return this->solve ? this->minCount : -1;
    }
};
*/

// method-2: 动态规划
class Solution {
private:
    vector<int> dp;
    int dfs(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        if (dp[amount] != 0) return dp[amount];
        
        int res = INT_MAX;
        for (auto& coin : coins) {
            int value = dfs(coins, amount - coin);
            if (0 <= value && value < res) {
                res = value + 1;
            }
        }
        dp[amount] = res == INT_MAX ? -1 : res;
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<int>(amount + 1, 0);
        return dfs(coins, amount);
    }
};


int main(int argc, const char** argv)
{
    // vector<int> list = {4, 3};
    // int amount = 10;
    vector<int> list = {288,160,10,249,40,77,314,429};
    int amount = 9208;
    list = {186,419,83,408};
    amount = 6249;
    printf("res: %d\n", Solution().coinChange(list, amount));
    return 0;
}
