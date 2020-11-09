/*
 * @lc app=leetcode id=508 lang=golang
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode-cn.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (65.20%)
 * Total Accepted:    9.1K
 * Total Submissions: 13.9K
 * Testcase Example:  '[5,2,-3]'
 *
 * 给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 * 
 * 你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 * 
 * 
 * 
 * 示例 1：
 * 输入:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * 
 * 返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
 * 
 * 示例 2：
 * 输入：
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * 
 * 返回 [2]，只有 2 出现两次，-5 只出现 1 次。
 * 
 * 
 * 
 * 提示： 假设任意子树元素和均可以用 32 位有符号整数表示。
 * 
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


var record = make(map[int]int)

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func transfer(root *TreeNode) int {
    sum := root.Val
    if (root.Left != nil) {
        sum += transfer(root.Left)
    }
    if (root.Right != nil) {
        sum += transfer(root.Right)
    }
    _, ok := record[sum]
    if ok {
        record[sum] += 1
    } else {
        record[sum] = 1
    }
    fmt.Printf("sum: %d record[sum]: %d\n", sum, record[sum])
    return sum
}

func findFrequentTreeSum(root *TreeNode) []int {
    var res []int
    if root == nil {
        return res
    }
    transfer(root)
    maxCount := 0
    for _, val := range record {
        maxCount = max(maxCount, val)
    }
    for key, val := range record {
        if val == maxCount {
            res = append(res, key)
        }
    }
    return res
}

