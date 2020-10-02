#include "./utils.h"

class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int size = stoneValue.size();
        int sum = 0;
        vector<int> dp(size, INT_MIN);
        for (int i = size - 1; i >= 0; i--)
        {
            sum += stoneValue[i];
            for (int j = 1; j <= 3; j++)
            {
                if (i+j >= size)
                {
                    dp[i] = max(dp[i], sum);
                }
                else
                {
                    dp[i] = max(dp[i], sum - dp[i + j]);
                }
                
            }
        }
        int alice = dp[0];
        int bob = sum - dp[0];
        if (alice > bob) return "Alice";
        if (alice < bob) return "Bob";
        return "Tie";
    }
};

int main(int argc, const char **argv)
{
    vector<int> list = {-2};
    printf("%s\n", Solution().stoneGameIII(list).c_str());
    return 0;
}
