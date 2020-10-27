/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (54.34%)
 * Total Accepted:    45.8K
 * Total Submissions: 84.2K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出：3
 * 解释：
 * 长度最长的公共子数组是 [3, 2, 1] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 * 
 * 
 */


class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        int n = A.size();
        int m = B.size();
        // dp[i][j] 表示以A[i]和B[j]对齐并结束的最长子序列的长度
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = (A[0] == B[0]) ? 1 : 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = (A[i] == B[0]) ? 1 : 0;
        }
        for (int j = 1; j < m; j++) {
            dp[0][j] = (A[0] == B[j]) ? 1 : 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = ((A[i] == B[j]) ? dp[i-1][j-1] + 1 : 0);
            }
        }
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << dp[i][j] << " ";
                res = max(res, dp[i][j]);
            }
            // cout << endl;
        }
        return res;
    }
};

