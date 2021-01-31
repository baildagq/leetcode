/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 *
 * https://leetcode-cn.com/problems/count-sorted-vowel-strings/description/
 *
 * algorithms
 * Medium (79.83%)
 * Total Accepted:    6K
 * Total Submissions: 7.7K
 * Testcase Example:  '1'
 *
 * 给你一个整数 n，请返回长度为 n 、仅由元音 (a, e, i, o, u) 组成且按 字典序排列 的字符串数量。
 * 
 * 字符串 s 按 字典序排列 需要满足：对于所有有效的 i，s[i] 在字母表中的位置总是与 s[i+1] 相同或在 s[i+1] 之前。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 1
 * 输出：5
 * 解释：仅由元音组成的 5 个字典序字符串为 ["a","e","i","o","u"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 2
 * 输出：15
 * 解释：仅由元音组成的 15 个字典序字符串为
 * ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
 * 注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 33
 * 输出：66045
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1  
 * 
 * 
 */
class Solution {
public:
    int countVowelStrings(int n)
    {
        if (n == 0) {
            return 0;
        }
        // 1: 5
        // 2: 5 + 4 + 3 + 2 + 1
        // 3: 5*(5 + 4 + 3 + 2 + 1) + 4*4 + 3*3 + 2*2 + 1*1
        int res[6] = { 1, 1, 1, 1, 1, 1 };
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                for (int k = j + 1; k <= 5; k++) {
                    res[j] += res[k];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= 5; i++) {
            ans += res[i];
        }
        return ans;
    }
};
