#include "./utils.h"


class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 0;

        dp = vector<int>(size, 0);
        for (int i = 0;i < size; i ++) {
            dp[i] = max((i-1 >= 0 ? dp[i-1] : 0), (i-2 >= 0 ? dp[i-2] : 0) + nums[i]);
        }
        return dp.back();
    }
};



int main(int argc, const char** argv)
{
    // vector<int> list = {2, 7, 9, 3, 1};
    vector<int> list = {};
    printf("res: %d\n", Solution().rob(list));
    return 0;
}
