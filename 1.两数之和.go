/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */

// package main

// import (
// 	"fmt"
// 	"sort"
// )

// @lc code=start
type Item struct {
	Val int
	Idx int
}

type ItemSlice []Item

func (i ItemSlice) Len() int {
	return len(i)
}

func (i ItemSlice) Swap(x int, y int) {
	i[x], i[y] = i[y], i[x]
}

func (i ItemSlice) Less(x int, y int) bool {
	return i[x].Val < i[y].Val
}

func twoSum(nums []int, target int) []int {
	itemSlice := ItemSlice{}
	for idx, val := range nums {
		itemSlice = append(itemSlice, Item{val, idx})
	}
	sort.Sort(itemSlice)
	l := 0
	r := len(itemSlice) - 1
	for {
		if l >= r {
			break
		}
		if itemSlice[l].Val+itemSlice[r].Val < target {
			l += 1
		} else if itemSlice[l].Val+itemSlice[r].Val == target {
			return []int{itemSlice[l].Idx, itemSlice[r].Idx}
		} else {
			r -= 1
		}
	}
	return []int{-1, -1}
}

// func main() {
// 	nums := []int{2, 7, 11, 15}
// 	target := 9
// 	fmt.Println(twoSum(nums, target))
// }

// @lc code=end
