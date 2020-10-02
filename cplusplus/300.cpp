#include "./utils.h"

// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         int res = 1;
//         int size = nums.size();
//         if (size == 0)
//             return res;
//         vector<int> dp(size, 1);
//         for (int i = size - 2; i >= 0; i--)
//         {
//             for (int j = i+1; j < size; j++)
//             {
//                 if (nums[i] < nums[j])
//                 {
//                     dp[i] = max(dp[i], 1 + dp[j]);
//                 }
//                 if (nums[i] == nums[j])
//                 {
//                     dp[i] = max(dp[i], 1 + dp[j]);
//                     break;
//                 }
//             }
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        int res = 1;
        vector<int> dp(size, 1);
        for (int i = size - 2; i >= 0; i--)
        {
            for (int j = i+1; j < size; j++)
            {
                if (nums[i] < nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
                if (nums[i] == nums[j])
                {
                    dp[i] = max(dp[i], dp[j]);
                    break;
                }
            }
            // printf("%d %d %d\n", i, nums[i], dp[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(int argc, const char **argv)
{
    vector<int> list = {1,3,6,7,9,4,10,5,6};
    printf("%d\n", Solution().lengthOfLIS(list));
    // printf("%s\n", Solution().xxx(list).c_str());
    // printVector(Solution().xxx());
    return 0;
}
