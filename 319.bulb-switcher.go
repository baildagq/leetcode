/*
 * @lc app=leetcode id=319 lang=golang
 *
 * [319] Bulb Switcher
 *
 * https://leetcode-cn.com/problems/bulb-switcher/description/
 *
 * algorithms
 * Medium (47.91%)
 * Total Accepted:    15.1K
 * Total Submissions: 31.6K
 * Testcase Example:  '3'
 *
 * 初始时有 n 个灯泡关闭。 第 1 轮，你打开所有的灯泡。 第 2 轮，每两个灯泡你关闭一次。 第 3
 * 轮，每三个灯泡切换一次开关（如果关闭则开启，如果开启则关闭）。第 i 轮，每 i 个灯泡切换一次开关。 对于第 n 轮，你只切换最后一个灯泡的开关。
 * 找出 n 轮后有多少个亮着的灯泡。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 1 
 * 解释: 
 * 初始时, 灯泡状态 [关闭, 关闭, 关闭].
 * 第一轮后, 灯泡状态 [开启, 开启, 开启].
 * 第二轮后, 灯泡状态 [开启, 关闭, 开启].
 * 第三轮后, 灯泡状态 [开启, 关闭, 关闭]. 
 * 
 * 你应该返回 1，因为只有一个灯泡还亮着。
 * 
 * 
 */



/*
// method-1: simulate: TLE
func bulbSwitch(n int) int {
    bulbs := make([]int, n)
    for i := range bulbs {
        bulbs[i] = 0
    }
    for i := 1; i <= n; i++ {
        index := -1 + i
        // fmt.Printf("%d: ", i)
        for true {
            if index >= n {
                break
            }
            // fmt.Printf("%d ", index + 1)
            bulbs[index] += 1
            bulbs[index] %= 2
            index += i
        }
        // fmt.Println()
        // fmt.Printf("cur: %v\n", bulbs)
    }
    res := 0
    for _, val := range bulbs {
        res += val
    }
    return res
}
*/

// method-2 math
/*
 * 看了题解进行的分析，做一个记录
 * 一个灯泡被翻转的次数就是他的因数的个数
 * 当因数个数为奇数时，翻转后灯泡为亮
 * P = A*B，则P的因数总成对出现，只有P为完全平方数时，因数个数才会为奇
 * 所以问题转化为求N内的完全平方数的个数
 * 实际上也就是求sqrt(n)
 */

func bulbSwitch(n int) int {
    res := 0
    base := 1
    for true {
        if (base * base > n) {
            break
        } 
        res += 1
        base += 1
    }
    return res
}

