// package main

// import "fmt"

/*
 * @lc app=leetcode.cn id=654 lang=golang
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func constructMaximumBinaryTree(nums []int) *TreeNode {
	// fmt.Println("nums: ", nums)
	if len(nums) == 0 {
		return nil
	}
	maxVal := -1
	maxIdx := -1
	for i, num := range nums {
		if num > maxVal {
			maxVal = num
			maxIdx = i
		}
	}
	if maxIdx != -1 {
		var leftChild *TreeNode = nil
		var rightChild *TreeNode = nil
		if maxIdx > 0 {
			leftChild = constructMaximumBinaryTree(nums[:maxIdx])
		}
		if maxIdx < len(nums)-1 {
			rightChild = constructMaximumBinaryTree(nums[maxIdx+1:])
		}
		return &TreeNode{nums[maxIdx], leftChild, rightChild}
	} else {
		return nil
	}
}

// func main() {
// 	nums := []int{3, 2, 1, 6, 0, 5}
// 	constructMaximumBinaryTree(nums)
// }

// @lc code=end
