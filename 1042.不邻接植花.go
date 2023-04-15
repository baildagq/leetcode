/*
 * @lc app=leetcode.cn id=1042 lang=golang
 *
 * [1042] 不邻接植花
 */

// package main

// import (
// 	"fmt"
// )

// @lc code=start
func gardenNoAdj(n int, paths [][]int) []int {
	res := make([]int, n+1)
	for i := 0; i < len(res); i++ {
		res[i] = -1
	}
	node2node := make(map[int][]int)
	for _, path := range paths {
		n1, n2 := path[0], path[1]
		if _, ok := node2node[n1]; !ok {
			node2node[n1] = []int{}
		}
		if _, ok := node2node[n2]; !ok {
			node2node[n2] = []int{}
		}
		node2node[n1] = append(node2node[n1], n2)
		node2node[n2] = append(node2node[n2], n1)
	}

	for i := 1; i <= n; i++ {
		// fmt.Println(i, node2node[i])
		if res[i] == -1 {
			if _, ok := node2node[i]; !ok {
				res[i] = 1
				continue
			}
			alternatives := []int{1, 2, 3, 4}
			for _, node := range node2node[i] {
				if res[node] != -1 {
					alternatives[res[node]-1] = -1
				}
			}
			for _, alter := range alternatives {
				if alter != -1 {
					res[i] = alter
					break
				}
			}
		}
	}
	res = res[1:]
	return res
}

// func main() {
// 	n := 4
// 	paths := [][]int{{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}}
// 	fmt.Println(gardenNoAdj(n, paths))
// }

// @lc code=end
