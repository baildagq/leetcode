#
# @lc app=leetcode id=739 lang=python3
#
# [739] Daily Temperatures
#
# https://leetcode-cn.com/problems/daily-temperatures/description/
#
# algorithms
# Medium (65.19%)
# Total Accepted:    119.2K
# Total Submissions: 182.1K
# Testcase Example:  '[73,74,75,71,69,72,76,73]'
#
# 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0
# 来代替。
# 
# 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
# 2, 1, 1, 0, 0]。
# 
# 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
# 
#
class Solution:
    # def dailyTemperatures(self, T: List[int]) -> List[int]:
    def dailyTemperatures(self, T):
       place = [-1]*120
       l = len(T)
       res = [0]*l
       for i in range(l - 1, -1, -1):
           val = T[i]
           ans = l
           find = False
           for j in range(val + 1, 120):
               if place[j] != -1 and place[j] < ans:
                   find = True
                   ans = place[j]
           if find:
               res[i] = ans - i
           place[val] = i
       return res

# List = [89,62,70,58,47,47,46,76,100,70]
# print(Solution().dailyTemperatures(List))
