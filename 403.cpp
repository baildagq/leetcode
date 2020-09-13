#include "./utils.h"

class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(vector<int>& stones, int idx, int stepLen)
    {
        // for (int i = 0; i < idx; i++) {
        //     printf(" ");
        // }
        // printf("idx: %d stepLen: %d\n", idx, stepLen);

        // 到达最后一个石子
        int size = stones.size();
        if (idx == size - 1)
            return true;
        // 以步长stepLen到达过石子idx，并且过河失败
        if (dp[idx][stepLen] == 0)
            return false;

        vector<int> diff = { -1, 0, 1};
        for (auto& v : diff) {
            // 可以跳到下一个石子，并在下一个石子后成功过河
            int nextIdx = idx + 1;
            int nextLen = stepLen + v;
            while (nextIdx < size && stones[idx] + nextLen >= stones[nextIdx]) {
                if (stones[idx] + nextLen == stones[nextIdx] && dfs(stones, nextIdx, nextLen)) {
                    return true;
                }
                nextIdx += 1;
            }
        }
        dp[idx][stepLen] = 0;
        return false;
    }

    bool canCross(vector<int>& stones)
    {
        int size = stones.size();
        dp = vector<vector<int>>(size + 1, vector<int>(size + 1, 1));
        return dfs(stones, 0, 0);
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = {0,1,3,5,6,8,12,17};
    printf("res: %d\n", Solution().canCross(list));
    return 0;
}
