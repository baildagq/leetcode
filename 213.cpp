#include "./utils.h"


class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (!size) return 0;
        vector<int> dp1(size, 0);
        vector<int> dp2(size, 0);

        int res1 = 0, res2 = 0;
        for (int i = 0;i < size - 1; i++) {
            dp1[i] = max((i-1 >= 0 ? dp1[i-1] : 0), (i-2 >= 0 ? dp1[i-2] : 0) + nums[i]);
            res1 = max(res1, dp1[i]);
        }
        for (int i = 1;i < size; i++) {
            dp2[i] = max((i-1 >= 0 ? dp2[i-1] : 0), (i-2 >= 0 ? dp2[i-2] : 0) + nums[i]);
            res2 = max(res2, dp2[i]);
        }
        return max(res1, res2);
    }
};


int main(int argc, const char** argv)
{
    vector<int> list = {};
    printf("res: %d\n", Solution().rob(list));
    return 0;
}
