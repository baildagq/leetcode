#include "./utils.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int size = nums.size();
        vector<int> res;
        if (!size) {
            return res;
        }
        // split nums into blocks which block's size = k
        // left[i]: the max value between nums[i] and this block's right bound
        // right[i]: the max value between this block's left bound and nums[i]
        vector<int> left = vector<int>(size, 0);
        vector<int> right = vector<int>(size, 0);

        left[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            if ((i + 1) % k == 0) {
                left[i] = nums[i];
            } else {
                left[i] = max(left[i + 1], nums[i]);
            }
        }
        right[0] = nums[0];
        for (int i = 1; i < size; i++) {
            if (i % k == 0) {
                right[i] = nums[i];
            } else {
                right[i] = max(right[i - 1], nums[i]);
            }
        }
        for (int i = 0; i < size - k + 1; i++) {
            res.push_back(max(left[i], right[i + k - 1]));
        }
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    vector<int> res = Solution().maxSlidingWindow(list, k);
    printVector(res);
    return 0;
}
