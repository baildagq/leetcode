/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (51.39%)
 * Total Accepted:    14.8K
 * Total Submissions: 28.8K
 * Testcase Example:  '2'
 *
 * 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
 * 
 * 示例:
 * 
 * 输入: 2
 * 输出: 91 
 * 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 * 
 * 
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n >= 11) return 0;
        if (n == 0 || n == 10) return 1;

        int res = 10;
        int num = 9;
        int mul = 9;
        for (int i = 1; i < n; i++) {
            num *= mul;
            mul -= 1;
            res += num;
        }
        return res;
    }
};
