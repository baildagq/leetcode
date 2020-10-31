/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 *
 * https://leetcode-cn.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (74.31%)
 * Total Accepted:    6.1K
 * Total Submissions: 8.2K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * 有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
 * 
 * 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
 * 
 * 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
 * 
 * 返回尽可能高的分数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * 输出：39
 * 解释：
 * 转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] 是 0 或 1
 * 
 * 
 */
class Solution {
public:
    void reverseCol(vector<vector<int>>& A, int idx) {
        int n = A.size();
        for (int i = 0;i < n; i++) A[i][idx] = 1 - A[i][idx];
    }

    void reverseRow(vector<vector<int>>& A, int idx) {
        int m = A[0].size();
        for (int i = 0; i < m; i++) A[idx][i] = 1 - A[idx][i];
    }

    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        if (n == 0) return 0;
        int m = B.size();
        if (m == 0) return 0;

        // if A[i][0] == 1, reverse row
        for (int i = 0; i < n; i++) {
            if (A[i][0] == 0) reverseRow(A, i);
        }
        // i from 2 to m, if 
    }
};
