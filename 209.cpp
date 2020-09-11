#include "./utils.h"

class Solution {
public:
    /*
     * O(n^2) 做法，实在是太不巧妙了
     * 可以通过双指针的方法，实现O(n)
     * start, end初始均为0，然后每次迭代 end += 1
     * 进行求和，while sum >= s, start ++
     */
    int minSubArrayLen(int s, vector<int>& nums)
    {
        vector<int> sum;
        int size = nums.size();

        sum.assign(nums.begin(), nums.end());

        for (int i = 0; i < size; i++) {
            if (sum[i] >= s)
                return 1;
        }

        for (int len = 1; len < size; len++) {
            for (int n = 0; n < size - len; n++) {
                sum[n] = sum[n] + nums[n + len];
                if (sum[n] >= s) {
                    return len + 1;
                }
            }
        }
        return 0;
    }
};

int main(int argc, const char** argv)
{
    int s = 8;
    vector<int> list = { 2, 3, 1, 2, 4, 3 };
    printf("%d\n", Solution().minSubArrayLen(s, list));
    return 0;
}
