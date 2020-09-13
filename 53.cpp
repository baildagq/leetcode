#include "./utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        // int size = nums.size();
        // if (!size) return 0;
        // vector<int> fi(size);
        // int res = nums[0];
        // fi[0] = nums[0];
        // for (int i = 1; i < size; i++) {
        //     fi[i] = max(fi[i-1] + nums[i], nums[i]);
        //     res = max(res, fi[i]);
        // }
        // return res;

        int size = nums.size();
        int pre = INT_MIN;
        for (int i = 0; i < size; i++) {
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
        }
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = { 1, 2, 3, 4, 5 };
    printf("%d\n", Solution().maxSubArray(list));
    return 0;
}
