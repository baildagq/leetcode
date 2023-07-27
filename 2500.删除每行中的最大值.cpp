// #include "common.h"
/*
 * @lc app=leetcode.cn id=2500 lang=cpp
 *
 * [2500] 删除每行中的最大值
 */

// @lc code=start
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;
        for (auto i = 0; i < grid.size(); i ++) {
            std::sort(grid[i].begin(), grid[i].end());
        } 
        for (auto i = 0; i < grid[0].size(); i ++) {
            int tmp = grid[0][i];
            for (auto j = 0; j < grid.size(); j ++) {
                tmp = std::max(tmp, grid[j][i]);
            }
            res += tmp;
        }
        return res;
    }
};
// @lc code=end

