/*
 * @lc app=leetcode id=896 lang=golang
 *
 * [896] Monotonic Array
 *
 * https://leetcode-cn.com/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (53.47%)
 * Total Accepted:    21.8K
 * Total Submissions: 40.3K
 * Testcase Example:  '[1,2,2,3]'
 *
 * 如果数组是单调递增或单调递减的，那么它是单调的。
 *
 * 如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A
 * 是单调递减的。
 *
 * 当给定的数组 A 是单调数组时返回 true，否则返回 false。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：[1,2,2,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：[6,5,4,4]
 * 输出：true
 *
 *
 * 示例 3：
 *
 * 输入：[1,3,2]
 * 输出：false
 *
 *
 * 示例 4：
 *
 * 输入：[1,2,4,5]
 * 输出：true
 *
 *
 * 示例 5：
 *
 * 输入：[1,1,1]
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= A.length <= 50000
 * -100000 <= A[i] <= 100000
 *
 *
 */
func isMonotonic(A []int) bool {
	var notsure bool = true
	var isgrow bool = false
	var res bool = true
	length := len(A)
	for i := 1; i < length; i++ {
		if A[i] == A[i-1] {
			continue
		} else {
			if notsure {
				isgrow = (A[i] > A[i-1])
			} else {
				if isgrow == (A[i] > A[i-1]) {
					continue
				} else {
					res = false
					break
				}
			}
			notsure = false
		}
	}
	return res
}
