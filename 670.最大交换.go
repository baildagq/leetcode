// package main

// import (
// 	"sort"
// )

/*
 * @lc app=leetcode.cn id=670 lang=golang
 *
 * [670] 最大交换
 */

// @lc code=start
func maximumSwap(num int) int {
	digits := make([]int, 0)
	tmp := num
	for tmp != 0 {
		digits = append(digits, tmp%10)
		tmp = tmp / 10
	}
	digitsSorted := append([]int{}, digits...)
	sort.Ints(digitsSorted)
	i := len(digitsSorted) - 1
	for ; i >= 0 && digitsSorted[i] == digits[i]; i-- {
	}
	if i == -1 {
		return num
	}
	j := 0
	for ; j < i; j++ {
		if digits[j] == digitsSorted[i] {
			break
		}
	}
	digits[i], digits[j] = digits[j], digits[i]
	res := 0
	for idx := len(digits) - 1; idx >= 0; idx-- {
		res = res*10 + digits[idx]
	}
	return res
}

// func main() {
// 	num := 9978281
// 	fmt.Println(maximumSwap(num))
// }

// @lc code=end
