#include "./utils.h"

// method-1: tle
class Solution {
public:
    bool solve = false;
    int minCount = INT_MAX;
    int sumCount = 0;

    bool dfs(vector<int>& coins, int idx, int amount) {
        if (amount == 0) {
            this->solve = true;
            this->minCount = min(this->minCount, this->sumCount);
            return true;;
        }
        if (idx >= int(coins.size())) {
            return false;
        }
        int num = amount / coins[idx];
        for (int j = num; j >= 0; j --) {
            this->sumCount += j;
            if (!this->solve || this->sumCount < this->minCount) {
                if (dfs(coins, idx + 1, amount - j * coins[idx])){
                    return true;
                }
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

/*
class Solution {
// 思考一下，应该也是一个背包问题？只是由最大的利润变成最小数量
public:
    int coinChange(vector<int>& coins, int amount) {
        
    }
};
*/


int main(int argc, const char** argv)
{
    // vector<int> list = {4, 3};
    // int amount = 10;
    vector<int> list = {288,160,10,249,40,77,314,429};
    int amount = 9208;
    printf("res: %d\n", Solution().coinChange(list, amount));
    return 0;
}
