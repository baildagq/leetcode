/*
 * @lc app=leetcode id=930 lang=golang
 *
 * [930] Binary Subarrays With Sum
 *
 * https://leetcode-cn.com/problems/binary-subarrays-with-sum/description/
 *
 * algorithms
 * Medium (38.05%)
 * Total Accepted:    4.6K
 * Total Submissions: 12.2K
 * Testcase Example:  '[1,0,1,0,1]\n2'
 *
 * 在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：A = [1,0,1,0,1], S = 2
 * 输出：4
 * 解释：
 * 如下面黑体所示，有 4 个满足题目要求的子数组：
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length <= 30000
 * 0 <= S <= A.length
 * A[i] 为 0 或 1
 * 
 * 
 */


func numSubarraysWithSum(A []int, S int) int {
    result := 0
    n := len(A)
    prefix := make(map[int]int, n)
    sum := 0

    for i := range A {
        sum += A[i]
        if sum == S {
            result ++
        }
        // fmt.Printf("%d %d %d\n", i, sum, sum - S)
        result = result + prefix[sum - S]
        prefix[sum] += 1
    }
    return result
}

