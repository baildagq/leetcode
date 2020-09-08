#include "./utils.h"

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<int> numbers;
        vector<bool> dp(n+1, 0); // dp[i] 表示当前剩余石子数量为i时，当前操作玩家是否能够胜出
        int i = 1;
        while (i * i <= n)
        {
            numbers.push_back(i * i);
            i++;
        }
        for (int i = 1; i <= n; i++)
        {
            bool flag = false;
            for (auto& num : numbers)
            {
                if ((num < i && !dp[i - num]) || num == i)
                {
                    flag = true;
                    break;
                }
                if (num > i)
                {
                    break;
                }
            }
            dp[i] = flag;
        }
        return dp[n];
    }
};

int main(int argc, const char **argv)
{
    printf("%d\n", Solution().winnerSquareGame(1));
    // printf("%s\n", Solution().xxx(list).c_str());
    // printVector(Solution().xxx());
    return 0;
}
