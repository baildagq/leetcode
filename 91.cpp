#include "./utils.h"

class Solution {
    int res = 0;
    int size = 0;
    vector<int> nums;

    void find(int idx)
    {
        if (idx == (int)nums.size()) {
            res += 1;
            return;
        }
        if (nums[idx] == 0 && (idx == 0 || nums[idx - 1] > 2 || nums[idx - 1] == 0)) {
            return;
        }
        find(idx + 1);
        if ((nums[idx] == 1 || nums[idx] == 2) && (idx + 1 < (int)nums.size()) && 0 < nums[idx + 1] && nums[idx + 1] <= 6) {
            find(idx + 2);
        }
    }
public:
    int numDecodings(string s)
    {
        for (auto c : s) {
            nums.push_back(c - '0');
        }
        size = nums.size();
        if (size == 0)
            return 0;
        find(0);
        return res;
    }
};

int main(int argc, const char** argv)
{
    string s = "110";
    printf("res: %d\n", Solution().numDecodings(s));
    return 0;
}
