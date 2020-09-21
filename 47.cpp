#include "./utils.h"

class Solution {
    vector<vector<int>> res;
    vector<int> item;
    vector<int> nums;
    vector<int> visited;
    int backtraceNum = 0;

    void backtrace(int idx) {
        backtraceNum += 1;
        /*
         * idx: current fill item's idx'th bit
         */
        if (idx == int(nums.size())) {
            res.emplace_back(item);
            return;
        }
        int size = nums.size();
        for (int i = 0;i < size; i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i-1])) {
                // 对于一段连续相等的值 val, 如果上一个值与当前值相同
                // 如果上一个值没有被选中，当前值也不应被选中，跳过
                continue;
            }
            visited[i] = 1;
            item.emplace_back(nums[i]);
            backtrace(idx + 1);
            item.pop_back();
            visited[i] = 0;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        int size = nums.size();
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        visited = vector<int>(size, 0);
        backtrace(0);
        // printf("backNum: %d\n", backtraceNum);
        return res;
    }
};

int main(int argc, const char** argv)
{
    vector<int> list = { 1, 1, 2 };
    vector<vector<int>> res = Solution().permuteUnique(list);
    printVector2D(res);
    return 0;
}
