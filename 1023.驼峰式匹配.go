// package main

// import (
// 	"fmt"
// )

/*
 * @lc app=leetcode.cn id=1023 lang=golang
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start

func isCapital(c byte) bool {
	return c >= 'A' && c <= 'Z'
}

func camelMatch(queries []string, pattern string) []bool {
	res := []bool{}
	for _, query := range queries {
		idx1 := 0
		idx2 := 0
		for {
			if idx1 == len(query) || idx2 == len(pattern) {
				break
			}
			for idx1 < len(query) && query[idx1] != pattern[idx2] && !isCapital(query[idx1]) {
				idx1++
			}
			if idx1 == len(query) || idx2 == len(pattern) {
				break
			}

			if query[idx1] == pattern[idx2] {
				idx1++
				idx2++
			} else {
				break
			}
			if idx2 == len(pattern) {
				for ; idx1 < len(query); idx1++ {
					if isCapital(query[idx1]) {
						break
					}
				}
			}
		}
		res = append(res, idx1 == len(query) && idx2 == len(pattern))
	}
	return res
}

// func main() {
// 	queries := []string{"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"}
// 	pattern := "FoBaT"
// 	fmt.Println(camelMatch(queries, pattern))
// }

// @lc code=end
