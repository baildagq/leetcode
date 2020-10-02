#include "./utils.h"


class NumArray {
public:
    // vector<int> numbers;
    vector<int> dp;
    NumArray(vector<int>& nums) {
        // this->numbers = nums;
        int size = nums.size();
        if (!size) return;
        dp.resize(size);
        dp[0] = nums[0];
        for (int i = 1; i < size; i ++) {
            dp[i] = dp[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (i == 0) return dp[j];
        return dp[j] - dp[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */



int main(int argc, const char** argv)
{
    vector<int> list = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(list);
    printf("%d\n", obj->sumRange(0, 2));
    printf("%d\n", obj->sumRange(2, 5));
    printf("%d\n", obj->sumRange(0, 5));
    return 0;
}
