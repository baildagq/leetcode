/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (45.28%)
 * Total Accepted:    161.6K
 * Total Submissions: 356.9K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        if (n == 0) return res;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1;i < n; i++) {
            // int base = INT_MIN;
            for (int j = i - 1; j >= 0; j--) {
                // if (nums[j] < nums[i] && nums[j] > base) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                    // base = nums[j];
                }
                // // 剪枝，提前结束遍历
                // if (base + 1 >= nums[i]) break;
            }
            dp[i] += 1;
        }
        for (int i = 0;i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};
