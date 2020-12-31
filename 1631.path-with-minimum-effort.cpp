/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 *
 * https://leetcode-cn.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (33.31%)
 * Total Accepted:    3.7K
 * Total Submissions: 10.6K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子
 * (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从
 * 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
 * 
 * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
 * 
 * 请你返回从左上角走到右下角的最小 体力消耗值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
 * 输出：2
 * 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
 * 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
 * 输出：1
 * 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * 输出：0
 * 解释：上图所示路径不需要消耗任何体力。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == heights.length
 * columns == heights[i].length
 * 1 
 * 1 
 * 
 * 
 */

class Solution {
private:
    const vector<vector<int>> dirs { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

public:
    bool canreach(int val, vector<vector<int>>& heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        queue<pair<int, int>> que;
        vector<vector<int>> find(rows, vector<int>(cols, 0));

        que.push({ 0, 0 });
        find[0][0] = 1;

        while (!que.empty()) {
            auto x = que.front().first;
            auto y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && find[nx][ny] == 0 && abs(heights[nx][ny] - heights[x][y]) <= val) {
                    que.push({ nx, ny });
                    find[nx][ny] = 1;
                }
            }
        }
        if (find[rows - 1][cols - 1] != 0) {
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int res = 0;
        int rows = heights.size();
        if (rows == 0) {
            return res;
        }
        int cols = heights[0].size();
        if (cols == 0) {
            return res;
        }

        // method-1: binary search
        // after find the first available result
        // mid can always get through
        // r === mid - 1
        // so res = r + 1
        int l = 0, r = 999999;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (canreach(mid, heights)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res = r + 1;
        return res;
    }
};
