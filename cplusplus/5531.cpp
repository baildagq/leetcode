#include "./utils.h"

class Solution {
public:
    /*
    int binarySearchIdx(vector<int>& nums, int target) {
        int idx = -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                idx = min(idx, mid);
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return idx;
    }
    */
    int specialArray(vector<int>& nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        // binary search x
        for (int i = 0;i <= size; i++) {
            // int idx = binarySearchIdx(nums, i);
            for (int j = 0; j < size; j++) {
                if (nums[j] >= i) {
                    if (size - j == i) {
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = {0, 0};
    printf("res: %d\n", Solution().specialArray(list));
    return 0;
}
