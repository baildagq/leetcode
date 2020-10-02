#include "./utils.h"

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int size = nums.size();
        if (!size) return 0;
        vector<int> maxPos(size, 0);
        vector<int> maxNeg(size, 0);

        if (nums[0] > 0) maxPos[0] = nums[0];
        if (nums[0] < 0) maxNeg[0] = nums[0];

        int res = nums[0];
        for (int i = 1; i < size; i++) {
            if (nums[i] == 0) {
                maxPos[i] = maxNeg[i] = 0;
            } else if (nums[i] > 0) {
                maxPos[i] = max(nums[i], maxPos[i - 1] * nums[i]);
                maxNeg[i] = maxNeg[i - 1] * nums[i];
            } else {
                maxPos[i] = maxNeg[i - 1] * nums[i];
                maxNeg[i] = min(nums[i], maxPos[i - 1] * nums[i]);
            }
            res = max(res, maxPos[i]);
        }
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = {-2, 0};
    printf("%d\n", Solution().maxProduct(list));
    return 0;
}
