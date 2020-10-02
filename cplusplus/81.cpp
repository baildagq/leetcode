#include "./utils.h"

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int size = nums.size();
        if (size == 0) {
            return false;
        }
        if (target == nums.front() || target == nums.back()) {
            return true;
        }
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            } else {
                int n = nums[0];
                int m = nums[mid];
                int t = target;
                if (n > m && m > t) {
                    r = mid - 1;
                } else if (n > t && t > m) {
                    l = mid + 1;
                } else if (m > n && n > t) {
                    l = mid + 1;
                } else if (m > t && t > n) {
                    r = mid - 1;
                } else if (t > n && n > m) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = {1, 3, 1, 1, 1};
    int target = 3;
    printf("res: %d\n", Solution().search(list, target));
    return 0;
}
