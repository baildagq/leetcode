// #include "./common.h"
/*
 * @lc app=leetcode.cn id=1186 lang=cpp
 *
 * [1186] 删除一次得到子数组最大和
 */

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int len = arr.size();
        std::vector<int> origin_max_sum(len, 0);
        std::vector<int> replace_max_sum(len, 0);
        origin_max_sum[0] = arr[0];
        replace_max_sum[0] = max(0, arr[0]);
        int res = origin_max_sum[0];
        for (auto i = 1; i < len; i ++) {
            origin_max_sum[i] = arr[i] + max(0, origin_max_sum[i - 1]);
            replace_max_sum[i] = max(arr[i] + replace_max_sum[i - 1], max(0, arr[i]) + origin_max_sum[i - 1]);
            res = max(res, max(origin_max_sum[i], replace_max_sum[i]));
        }
        return res;
    }
};

// int main() {
//     Solution solu;
//     std::vector <int> nums = {-1, -1, -1, -1};
//     std::cout << solu.maximumSum(nums) << std::endl;
// }

// @lc code=end

