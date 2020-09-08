class Solution:
    def removeBoxes(self, boxes):
        res = 0
        size = len(boxes)
        if size == 0:
            return res
        dp = [[[0]*100]*100]*100
        def solve(l, r, k):
            print(l,r,k)
            nonlocal dp
            if l > r:
                return 0
            if dp[l][r][k] != 0:
                return dp[l][r][k]
            
            while r>l and boxes[r]==boxes[r-1]:
                r -= 1
                k += 1

            ans = solve(l, r-1, 0) + (k+1)*(k+1)
            for i in range(l, r):
                if boxes[i] == boxes[r]:
                    ans = max(ans, solve(l, i, k+1) + solve(i+1, r-1, 0))
            dp[l][r][k] = ans
            print('  ', dp[l][r][k])
            return dp[l][r][k]
        return solve(0, size-1, 0)

# boxes = [1,3,2,2,2,3,4,3,1]
boxes = [1,3,2,2,3]
print(Solution().removeBoxes(boxes))